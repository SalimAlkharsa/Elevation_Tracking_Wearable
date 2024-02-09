/*
The code below is written by Anna Theodore for Capstone Team 75's Wearable Device project.
November 17th, 2023

The following functionality is present in this code.

1. Integration of the MPU6050 sensor. More information on this part can be found here.
https://invensense.tdk.com/wp-content/uploads/2015/02/MPU-6000-Register-Map1.pdf

2. Integration of the BMP280 sensor. More information on this part can be found here.
https://cdn-shop.adafruit.com/datasheets/BST-BMP280-DS001-11.pdf

3. This example uses an ESP-32 WROOM, which receives data from the two sensors above.
https://www.espressif.com/sites/default/files/documentation/esp32-wroom-32_datasheet_en.pdf

4. A Wi-Fi connection is established for the HTTP Post to work effectively in following steps.
It is important to note that these Wi-Fi settings can be changed, but for the purposes of this
project connect to the TAMU_IoT network. If you would like to change these settings, Ctrl+F for the following "// Wi-Fi Settings".

5. Once the Wi-Fi is connected, the data inputs will be sent as JSON data to the web server.
In this example, the following URL is used.
"http://i-want-to-pass-capstone-96abfc16411c.herokuapp.com/post_endpoint".
If you would like to change these settings, Ctrl+F for the following "// URL Settings".

6. This concludes the functionality of this specific file,
but note that the final data transmission will be to the postgreSQL database, written in Python.
*/

/*
  This code is based on the example projects from the ESP-IDF sample projects:
  1. hello_world
  2. sample_project
  3. http_server_simple
  4. i2c_simple

  Additional modifications and customizations have been made for specific purposes in this code.
*/

// PRIOR TO RUNNING CONTROL THIS TOGGLE
/*
    This is to control for how the code is being outputted.
    If you are testing the code, uncomment the TESTING_MODE define.
    If you are debugging the code, uncomment the DEBUGGING_MODE define.
    When we are fully operational, neither of these should be defined and the code should be cleaned.
    For now, Salim needs a way to control the output of the code to see how the data interacts with the model using a debugger.
*/
#define TESTING_MODE
// #define DEBUGGING_MODE

#include <stdio.h>
#include <inttypes.h>
#include "driver/i2c.h"
#include "sdkconfig.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_chip_info.h"
#include "esp_flash.h"
#include <string.h>
#include "freertos/event_groups.h"
#include "esp_system.h"
#include "esp_wifi.h"
#include "esp_event.h"
#include "nvs_flash.h"
#include "lwip/err.h"
#include "lwip/sys.h"
#include <esp_crt_bundle.h>
#include "esp_http_client.h"
#include "cJSON.h"
#include "esp_tls.h"
#include "esp_log.h"
#include <time.h>
#include <sys/time.h>
#include <stdbool.h>
#include "freertos/queue.h"
#include "freertos/timers.h"
#include "lwip/apps/sntp.h"
#include "driver/uart.h"

// Imports where the sensors are defined
#include "MPU6050Sensor.h"
#include "BMP280Sensor.h"

// Imports that control data windowing and queueing
#include "Window_Queue.c"
#include "Window.h"
#include "Observation.h"
#include "Metrics.h"

// Port communication defines
// Used to debug the model's interaction with the sensor data
#define TXD_PIN (GPIO_NUM_17)
#define RXD_PIN (GPIO_NUM_16)
#define BAUD_RATE 115200

// This is the function that initializes the UART communication when in testing mode
void init_uart()
{
    uart_config_t uart_config = {
        .baud_rate = BAUD_RATE,
        .data_bits = UART_DATA_8_BITS,
        .parity = UART_PARITY_DISABLE,
        .stop_bits = UART_STOP_BITS_1,
        .flow_ctrl = UART_HW_FLOWCTRL_DISABLE};

    uart_param_config(UART_NUM_1, &uart_config);
    uart_set_pin(UART_NUM_1, TXD_PIN, RXD_PIN, UART_PIN_NO_CHANGE, UART_PIN_NO_CHANGE);
    uart_driver_install(UART_NUM_1, 1024, 0, 0, NULL, 0);
}

// This is the function that sends the sensor data over UART when in testing mode
void send_sensor_data(float x_acc, float y_acc, float z_acc, float x_rot, float y_rot, float z_rot, float temp, float press)
{
    // Not sure what value to use for the buffer size but 50 is arbitrary and works for now
    char data[100];

    // Format the data as per the protocol
    snprintf(data, sizeof(data), "%f, %f, %f, %f, %f, %f, %f, %f", x_acc, y_acc, z_acc, x_rot, y_rot, z_rot, temp, press);

    // Print the data for debugging purposes
    printf("%s\n", data);

    // Send data over UART
    uart_write_bytes(UART_NUM_1, data, strlen(data));
}

// Defines for I2C functionality
// Defines for the SCL and SDA pins on the ESP-32 WROOM
#define I2C_MASTER_SCL_IO 22
#define I2C_MASTER_SDA_IO 21

// Frequency desired for sampling
// I2C communication timeout
#define I2C_MASTER_FREQ_HZ 25

// AT: ayo what is this
#define I2C_MASTER_TIMEOUT_MS 1000

// Defaults for the I2C, disable buffers for this example
#define I2C_MASTER_NUM 0
#define I2C_MASTER_TX_BUF_DISABLE 0
#define I2C_MASTER_RX_BUF_DISABLE 0

/*
Explicit defines for TAMU network.

For the TAMU_IoT network, the MAC address of your microcontroller must be registered.

Follow the link below to register the MAC address.

https://wemr-cp.net.tamu.edu/guest/mac_list.php
*/

// Wi-Fi Settings
#define EXAMPLE_ESP_WIFI_SSID "TAMU_IoT"
#define EXAMPLE_ESP_WIFI_PASS ""

// This WiFi network is open, but the includes below may be used if a different network is needed.
#define ESP_WIFI_SCAN_AUTH_MODE_THRESHOLD WIFI_AUTH_OPEN

// #define EXAMPLE_ESP_WIFI_SSID "wifisfuneral"
// #define EXAMPLE_ESP_WIFI_PASS "13bricks"

// #define EXAMPLE_ESP_MAXIMUM_RETRY 5

// TODO: Is this code removable?
// Extra defines not needed for this example because it is an open network
// If a different network is used, these if statements will need to be implemented
/*
#elif CONFIG_ESP_WIFI_AUTH_WEP
#define ESP_WIFI_SCAN_AUTH_MODE_THRESHOLD WIFI_AUTH_WEP
#elif CONFIG_ESP_WIFI_AUTH_WPA_PSK
#define ESP_WIFI_SCAN_AUTH_MODE_THRESHOLD WIFI_AUTH_WPA_PSK
#elif CONFIG_ESP_WIFI_AUTH_WPA2_PSK
#define ESP_WIFI_SCAN_AUTH_MODE_THRESHOLD WIFI_AUTH_WPA2_PSK
#elif CONFIG_ESP_WIFI_AUTH_WPA_WPA2_PSK
#define ESP_WIFI_SCAN_AUTH_MODE_THRESHOLD WIFI_AUTH_WPA_WPA2_PSK
#elif CONFIG_ESP_WIFI_AUTH_WPA3_PSK
#define ESP_WIFI_SCAN_AUTH_MODE_THRESHOLD WIFI_AUTH_WPA3_PSK
#elif CONFIG_ESP_WIFI_AUTH_WPA2_WPA3_PSK
#define ESP_WIFI_SCAN_AUTH_MODE_THRESHOLD WIFI_AUTH_WPA2_WPA3_PSK
#elif CONFIG_ESP_WIFI_AUTH_WAPI_PSK
#define ESP_WIFI_SCAN_AUTH_MODE_THRESHOLD WIFI_AUTH_WAPI_PSK
#endif
*/

// Define for timestamp data
#define PRINT_INTERVAL_MILLISECONDS 40

// URL Settings
#define SERVER_URL "http://i-want-to-pass-capstone-96abfc16411c.herokuapp.com/post_endpoint"

/* The event group allows multiple bits for each event, but we only care about two events:
 * - we are connected to the AP with an IP
 * - we failed to connect after the maximum amount of retries */
#define WIFI_CONNECTED_BIT BIT0
#define WIFI_FAIL_BIT BIT1

// This is arbitrary, need a tag but the name isn't important
static const char *TAG = ""; // Try an empty string

// FreeRTOS event group to signal when connected
static EventGroupHandle_t s_wifi_event_group;

// Initial condition for the local time when initialized
static struct timeval start_time;

// Variable counter for number of Wi-Fi attempts
static int s_retry_num = 0;

// Returns temperature in DegC, resolution is 0.01 DegC.
int32_t t_fine = 0;
i2c_cmd_handle_t cmd;

// Timestamp variable, YYYY-MM-DD HH:MM:SS.SSS
typedef struct
{
    char formatted_timestamp[30];
    long microseconds;
} TimestampInfo;

/*
   This function is invoked when a timer expires. It retrieves the current system time
   and calculates the milliseconds elapsed since a reference time (start_time).
*/
void timer_callback(TimerHandle_t xTimer)
{
    // Get the current system time
    struct timeval current_time;
    gettimeofday(&current_time, NULL);

    // Calculate milliseconds since a reference time (start_time), not a part of the generic time functionality but necessary for this example
    unsigned long long start_ms = start_time.tv_sec * 1000 + start_time.tv_usec / 1000;
    unsigned long long current_ms = current_time.tv_sec * 1000 + current_time.tv_usec / 1000;
}

/*
   This function calculates the elapsed time since the reference time (start_time)
   in milliseconds and adds it to get the total hours, minutes, and seconds.
*/
void calculate_elapsed_time(unsigned long long *elapsed_ms, char *strftime_buf)
{
    // Get the current system time
    struct timeval current_time;
    gettimeofday(&current_time, NULL);

    // Calculate milliseconds since a reference time (start_time)
    unsigned long long start_ms = start_time.tv_sec * 1000 + start_time.tv_usec / 1000;
    unsigned long long current_ms = current_time.tv_sec * 1000 + current_time.tv_usec / 1000;

    // Calculate elapsed milliseconds
    *elapsed_ms = current_ms - start_ms;

    // Format the current time to a specific string format
    strftime(strftime_buf, sizeof(strftime_buf), "%Y-%m-%d %H:%M:%S", localtime(&current_time.tv_sec));

    // Calculate elapsed time in hours, minutes, and seconds
    unsigned long long elapsed_seconds = *elapsed_ms / 1000;
    unsigned long long elapsed_minutes = elapsed_seconds / 60;
    unsigned long long elapsed_hours = elapsed_minutes / 60;
    elapsed_seconds %= 60;
    elapsed_minutes %= 60;

#ifdef DEBUGGING_MODE
    // Append the elapsed time to the formatted timestamp
    snprintf(strftime_buf + strlen(strftime_buf), sizeof(strftime_buf) - strlen(strftime_buf),
             " | Elapsed time: %02llu:%02llu:%02llu", elapsed_hours, elapsed_minutes, elapsed_seconds);
#endif
}

/*
   Initializes a timer to the current time zone and starts the timer.
*/
void initialize_timer()
{
    // Set the initial reference time
    gettimeofday(&start_time, NULL);

    // Create and start a timer
    TimerHandle_t timer = xTimerCreate("UnixTimer", pdMS_TO_TICKS(PRINT_INTERVAL_MILLISECONDS), pdTRUE, 0, timer_callback);

    if (timer == NULL)
    {
#ifdef DEBUGGING_MODE
        printf("Failed to create timer\n");
#endif
        return;
    }

    if (xTimerStart(timer, 0) != pdPASS)
    {
#ifdef DEBUGGING_MODE
        printf("Failed to start timer\n");
#endif
        return;
    }
}

/*
   Initializes SNTP (Simple Network Time Protocol) for time synchronization
   using the polling mode and sets the server name to "pool.ntp.org".

   This pulls from the Wi-Fi to ensure the initial condition time is dependent on real world current date and time
*/
void initialize_sntp(void)
{
    sntp_setoperatingmode(SNTP_OPMODE_POLL);
    sntp_setservername(0, "pool.ntp.org");
    sntp_init();
}

/*
   Obtains the current Central Standard Time (CST).
*/
// AT: timer + time = what?
void obtain_time(void)
{
    // Initialize SNTP for time synchronization
    initialize_sntp();
    time_t now = 0;
    struct tm timeinfo = {0};

    // Wait until the time is obtained and set
    while (timeinfo.tm_year < (2020 - 1900))
    {
        vTaskDelay(pdMS_TO_TICKS(1000));
        time(&now);
        localtime_r(&now, &timeinfo);
    }

    // Adjust the obtained time by subtracting hours to get it to CST
    int hoursToSubtract = 6;
    timeinfo.tm_hour -= hoursToSubtract;
    if (timeinfo.tm_hour < 0)
    {
        timeinfo.tm_hour += 24;
        timeinfo.tm_mday--;
    }

    char strftime_buf[64];
    calculate_elapsed_time(&(unsigned long long){0}, strftime_buf);
}

/*
   Calculates the elapsed time since the reference time (start_time) and formats
   it into a timestamp string with milliseconds. It also adjusts the local time
   and allocates memory to store the formatted timestamp.
*/
char *report_time_elapsed()
{
    struct timeval current_time;
    unsigned long long elapsed_ms;
    char strftime_buf[64];

    // Get the current system time
    gettimeofday(&current_time, NULL);

    // Calculate and format elapsed time
    calculate_elapsed_time(&elapsed_ms, strftime_buf);

    // Calculate elapsed seconds and milliseconds
    unsigned long long elapsed_sec = elapsed_ms / 1000;
    unsigned long long elapsed_msec = elapsed_ms % 1000;

    // Obtain the current local time in CST
    time_t now = time(NULL);
    struct tm *timeinfo = localtime(&now);
    timeinfo->tm_hour -= 6;
    mktime(timeinfo);

    // Format the local time with milliseconds
    strftime(strftime_buf, sizeof(strftime_buf), "%Y-%m-%d %H:%M:%S", timeinfo);
    snprintf(strftime_buf + strlen(strftime_buf), sizeof(strftime_buf) - strlen(strftime_buf),
             ".%03llu", elapsed_msec);

    // Allocate memory for the formatted timestamp and copy the string
    char *formatted_timestamp = (char *)malloc(strlen(strftime_buf) + 1);
    strcpy(formatted_timestamp, strftime_buf);

    return formatted_timestamp;
}

/*
    Wi-Fi event handler function handling various Wi-Fi events:
   - Manages Wi-Fi events such as connection start, disconnection, and IP address acquisition.
   - Initiates connection retries upon disconnection and manages connection success/failure events.
*/
void wifi_event_handler(void *arg, esp_event_base_t event_base, int32_t event_id, void *event_data)
{
    if (event_base == WIFI_EVENT && event_id == WIFI_EVENT_STA_START)
    {
        // Connect to Wi-Fi as the STA (Station) starts
        esp_wifi_connect();
    }
    else if (event_base == WIFI_EVENT && event_id == WIFI_EVENT_STA_DISCONNECTED)
    {
        if (s_retry_num < 5)
        {
            // Attempt to reconnect if disconnected, up to 5 retries
            esp_wifi_connect();
            s_retry_num++;
            ESP_LOGI(TAG, "retry to connect to the AP");

            // Delay 2 seconds before next retry
            vTaskDelay(pdMS_TO_TICKS(2000));
        }
        else
        {
            // Set fail bit if maximum retries reached
            xEventGroupSetBits(s_wifi_event_group, WIFI_FAIL_BIT);
        }
        ESP_LOGI(TAG, "connect to the AP fail");
    }
    else if (event_base == IP_EVENT && event_id == IP_EVENT_STA_GOT_IP)
    {
        // IP address obtained; connection successful
        ip_event_got_ip_t *event = (ip_event_got_ip_t *)event_data;
        ESP_LOGI(TAG, "got ip:" IPSTR, IP2STR(&event->ip_info.ip));

        // Reset retry counter
        s_retry_num = 0;
        xEventGroupSetBits(s_wifi_event_group, WIFI_CONNECTED_BIT);

        // Call the local time once the Wi-Fi is connected to for the intial condition
        obtain_time();
    }
}

/*
    Function to initialize Wi-Fi in station (STA) mode:
   - Sets up the Wi-Fi stack, event handlers, and connects the device to a specified Wi-Fi network.
   - Manages event-driven connection establishment and retries with a defined set of SSID and password.
*/
void wifi_init_sta(void)
{
    // Create event group to manage Wi-Fi events
    s_wifi_event_group = xEventGroupCreate();

    // Initialize the underlying TCP/IP stack
    ESP_ERROR_CHECK(esp_netif_init());

    // Create default event loop
    ESP_ERROR_CHECK(esp_event_loop_create_default());

    // Create default Wi-Fi station interface
    esp_netif_create_default_wifi_sta();

    // Initialize Wi-Fi with default configuration
    wifi_init_config_t cfg = WIFI_INIT_CONFIG_DEFAULT();
    ESP_ERROR_CHECK(esp_wifi_init(&cfg));

    // Register event handlers for Wi-Fi and IP events
    esp_event_handler_instance_t instance_any_id;
    esp_event_handler_instance_t instance_got_ip;
    ESP_ERROR_CHECK(esp_event_handler_instance_register(WIFI_EVENT,
                                                        ESP_EVENT_ANY_ID,
                                                        &wifi_event_handler,
                                                        NULL,
                                                        &instance_any_id));
    ESP_ERROR_CHECK(esp_event_handler_instance_register(IP_EVENT,
                                                        IP_EVENT_STA_GOT_IP,
                                                        &wifi_event_handler,
                                                        NULL,
                                                        &instance_got_ip));

    // Configure Wi-Fi station with SSID and password
    wifi_config_t wifi_config = {
        .sta = {
            .ssid = EXAMPLE_ESP_WIFI_SSID,
            .password = EXAMPLE_ESP_WIFI_PASS,
            .threshold.authmode = ESP_WIFI_SCAN_AUTH_MODE_THRESHOLD, // Set authentication mode threshold
        },
    };

    ESP_ERROR_CHECK(esp_wifi_set_mode(WIFI_MODE_STA));
    ESP_ERROR_CHECK(esp_wifi_set_config(WIFI_IF_STA, &wifi_config));
    ESP_ERROR_CHECK(esp_wifi_start());

    ESP_LOGI(TAG, "wifi_init_sta finished.");

    /*
    Wait until either the connection is established (WIFI_CONNECTED_BIT) or connection fails for maximum
    number of retries (WIFI_FAIL_BIT). These bits are set by the event handler
    */
    EventBits_t bits = xEventGroupWaitBits(s_wifi_event_group,
                                           WIFI_CONNECTED_BIT | WIFI_FAIL_BIT,
                                           pdFALSE,
                                           pdFALSE,
                                           portMAX_DELAY);

    // Check which event occurred based on bits set by xEventGroupWaitBits()
    if (bits & WIFI_CONNECTED_BIT)
    {
        ESP_LOGI(TAG, "connected to ap SSID:%s password:%s",
                 EXAMPLE_ESP_WIFI_SSID, EXAMPLE_ESP_WIFI_PASS);
    }
    else if (bits & WIFI_FAIL_BIT)
    {
        ESP_LOGI(TAG, "Failed to connect to SSID:%s, password:%s",
                 EXAMPLE_ESP_WIFI_SSID, EXAMPLE_ESP_WIFI_PASS);
    }
    else
    {
        ESP_LOGE(TAG, "UNEXPECTED EVENT");
    }
}

/*
   Handles events occurring during an HTTP client operation:
   - Switches over different events and performs appropriate actions if needed.
   - Current implementation does nothing for HTTP_EVENT_ON_DATA and defaults for other events.
*/
esp_err_t client_event_post_handler(esp_http_client_event_handle_t evt)
{
    switch (evt->event_id)
    {
    case HTTP_EVENT_ON_DATA:
        break;
    default:
        break;
    }

    return ESP_OK;
}

/*
   Sends a POST request to a server with sensor data in JSON format:
   - Creates a JSON object and arrays for each sensor data variable.
   - Adds sensor data to respective arrays within the JSON object.
   - Initializes an HTTP client, configures it with server details and POSTs the JSON data.
   - Cleans up resources after the request is performed.
*/
void send_post_request(char *my_timestamp, float user_id, float a_x, float a_y, float a_z,
                       float r_x, float r_y, float r_z,
                       float temp_calibrated, float press_calibrated)
{
    // Create a JSON object
    cJSON *json_root = cJSON_CreateObject();

    // Create arrays for each variable
    cJSON *timestampArray = cJSON_CreateArray();
    cJSON *userIDArray = cJSON_CreateArray();
    cJSON *axArray = cJSON_CreateArray();
    cJSON *ayArray = cJSON_CreateArray();
    cJSON *azArray = cJSON_CreateArray();
    cJSON *rxArray = cJSON_CreateArray();
    cJSON *ryArray = cJSON_CreateArray();
    cJSON *rzArray = cJSON_CreateArray();
    cJSON *temperatureArray = cJSON_CreateArray();
    cJSON *pressureArray = cJSON_CreateArray();

    // Add arrays to the root object
    cJSON_AddItemToObject(json_root, "my_timestamp", timestampArray);
    cJSON_AddItemToObject(json_root, "user_id", userIDArray);
    cJSON_AddItemToObject(json_root, "a_x", axArray);
    cJSON_AddItemToObject(json_root, "a_y", ayArray);
    cJSON_AddItemToObject(json_root, "a_z", azArray);
    cJSON_AddItemToObject(json_root, "r_x", rxArray);
    cJSON_AddItemToObject(json_root, "r_y", ryArray);
    cJSON_AddItemToObject(json_root, "r_z", rzArray);
    cJSON_AddItemToObject(json_root, "temperature", temperatureArray);
    cJSON_AddItemToObject(json_root, "pressure", pressureArray);

    // Add an element to each array
    cJSON_AddItemToArray(timestampArray, cJSON_CreateString(my_timestamp));
    cJSON_AddItemToArray(userIDArray, cJSON_CreateNumber(user_id));
    cJSON_AddItemToArray(axArray, cJSON_CreateNumber(a_x));
    cJSON_AddItemToArray(ayArray, cJSON_CreateNumber(a_y));
    cJSON_AddItemToArray(azArray, cJSON_CreateNumber(a_z));
    cJSON_AddItemToArray(rxArray, cJSON_CreateNumber(r_x));
    cJSON_AddItemToArray(ryArray, cJSON_CreateNumber(r_y));
    cJSON_AddItemToArray(rzArray, cJSON_CreateNumber(r_z));
    cJSON_AddItemToArray(temperatureArray, cJSON_CreateNumber(temp_calibrated));
    cJSON_AddItemToArray(pressureArray, cJSON_CreateNumber(press_calibrated));

    // Print the JSON object
    char *post_data = cJSON_Print(json_root);
#ifdef DEBUGGING_MODE
    printf("%s\n", post_data);
#endif

    // Initialize the HTTP client configuration
    esp_http_client_config_t config = {
        .url = SERVER_URL,
        .method = HTTP_METHOD_POST,
        .timeout_ms = 6000,
        .cert_pem = NULL,
        .event_handler = client_event_post_handler,
        .transport_type = HTTP_TRANSPORT_OVER_TCP,
        .crt_bundle_attach = esp_crt_bundle_attach,
    };

    // Initialize the HTTP client handle
    esp_http_client_handle_t client = esp_http_client_init(&config);
    esp_http_client_set_method(client, HTTP_METHOD_POST);
    esp_http_client_set_post_field(client, post_data, strlen(post_data));
    esp_http_client_set_header(client, "Content-Type", "application/json");

    // Perform the HTTP POST request
    esp_err_t err = esp_http_client_perform(client);

    // Cleanup resources
    esp_http_client_cleanup(client);
    cJSON_free((void *)post_data);
    cJSON_Delete(json_root);
}

/*
    Prints out specific information about the current microcontroller you are using.
    Used primarily in debugging applications if you are having issues connecting to the ESP-32.
    It can also tell you if you have Wi-Fi functionality on your specific board.
*/
void print_chip_info()
{
    // Print a starting message
    printf("Hello world!\n");

    // Retrieve and print information about the ESP chip
    esp_chip_info_t chip_info;
    uint32_t flash_size;

    // Get information about the chip (type, cores, features)
    esp_chip_info(&chip_info);
    printf("This is %s chip with %d CPU core(s), WiFi%s%s, ",
           CONFIG_IDF_TARGET,
           chip_info.cores,
           (chip_info.features & CHIP_FEATURE_BT) ? "/BT" : "",
           (chip_info.features & CHIP_FEATURE_BLE) ? "/BLE" : "");

    // Print the silicon revision version
    unsigned major_rev = chip_info.revision / 100;
    unsigned minor_rev = chip_info.revision % 100;
    printf("silicon revision v%d.%d, ", major_rev, minor_rev);

    // Get and print the flash size of the chip
    if (esp_flash_get_size(NULL, &flash_size) != ESP_OK)
    {
        printf("Get flash size failed");
        return;
    }
    printf("%" PRIu32 "MB %s flash\n", flash_size / (uint32_t)(1024 * 1024),
           (chip_info.features & CHIP_FEATURE_EMB_FLASH) ? "embedded" : "external");

    // Print the minimum free heap size available
    printf("Minimum free heap size: %" PRIu32 " bytes\n", esp_get_minimum_free_heap_size());

    // Flush the standard output stream
    fflush(stdout);
}

/*
    Initializes the I2C master for communication with sensors.
    Returns ESP_OK if initialization is successful, otherwise returns an error code.
 */
static esp_err_t i2c_master_init(void)
{
    // Configuration for I2C master
    i2c_config_t conf = {
        .mode = I2C_MODE_MASTER,
        .sda_io_num = I2C_MASTER_SDA_IO,
        .scl_io_num = I2C_MASTER_SCL_IO,
        .sda_pullup_en = GPIO_PULLUP_ENABLE,
        .scl_pullup_en = GPIO_PULLUP_ENABLE,
        .master.clk_speed = I2C_MASTER_FREQ_HZ,
    };

    // Configure I2C parameters
    i2c_param_config(I2C_MASTER_NUM, &conf);

    // Install the I2C driver
    return i2c_driver_install(I2C_MASTER_NUM, conf.mode, I2C_MASTER_RX_BUF_DISABLE, I2C_MASTER_TX_BUF_DISABLE, 0);
}

TimestampInfo getTimestampInfo()
{
    TimestampInfo result;
    struct timeval tv;
    struct tm *timeinfo;

    // Get the current time
    gettimeofday(&tv, NULL);

    // Convert the time to a tm structure in UTC
    timeinfo = gmtime(&tv.tv_sec);

    if (timeinfo == NULL)
    {
        // Handle the error, e.g. print an error message
        perror("gmtime failed");
        exit(EXIT_FAILURE);
    }

    // Format the timestamp
    strftime(result.formatted_timestamp, sizeof(result.formatted_timestamp), "%Y-%m-%d %H:%M:%S", timeinfo);

    // Set the microseconds
    result.microseconds = tv.tv_usec;

    return result;
}

// Declare the variables for the sensor data
float a_x;
float a_y;
float a_z;
float r_x;
float r_y;
float r_z;
float temp_calibrated;
float press_calibrated;
void app_main(void)
{
#ifdef DEBUGGING_MODE
    // Ensure it is properly reading from the microcontroller
    print_chip_info();
#endif DEBUGGING_MODE

#ifdef TESTING_MODE
    // Initialize the UART
    init_uart();
#endif

    // Initialize non-volatile storage
    esp_err_t ret = nvs_flash_init();
    if (ret == ESP_ERR_NVS_NO_FREE_PAGES || ret == ESP_ERR_NVS_NEW_VERSION_FOUND)
    {
        ESP_ERROR_CHECK(nvs_flash_erase());
        ret = nvs_flash_init();
    }
    ESP_ERROR_CHECK(ret);

    // Initialize the Wi-Fi connection
    // wifi_init_sta();

    // AT: need to figure out if this delay is still necessary
    // vTaskDelay(500 / portTICK_PERIOD_MS);

    // Intialize the I2C port
    ESP_ERROR_CHECK(i2c_master_init());

    initialize_timer();
    // AT: need to figure out if this delay is still necessary
    // vTaskDelay(pdMS_TO_TICKS(7500));

    // Declare the sensor object
    MPU6050Sensor mpuSensor;
    BMP280Sensor bmpSensor;
    // Initialize the sensor objects
    MPU6050Sensor_init(&mpuSensor);
    BMP280Sensor_init(&bmpSensor);
    // Initialize a variable to check if the sensor is connected
    bool mpuSensorConnected;
    bool bmpSensorConnected;

    // Create a queue to hold data, in case more data is being read than can be processed
    WindowQueue *myQueue = initializeQueue();

    // Data is stored in windows, before being compressed and sent to the model, so create a window to hold it
    Window *myWindow = createWindow();

    // Continuously take sensor inputs until power is lost
    while (1)
    {
        // Read the data from the MPU6050Sensor
        mpuSensorConnected = MPU6050Sensor_readData(&mpuSensor);
        if (!mpuSensorConnected)
        {
#ifdef DEBUGGING_MODE
            printf("MPU6050 sensor not connected!\n");
#endif
            // Apply actual handling procedure here...
            vTaskDelay(pdMS_TO_TICKS(5000));
            MPU6050Sensor_init(&mpuSensor);
            mpuSensorConnected = true;
            // TO DO: Determine if this is the correct way to handle the sensor not being connected
            continue;
        }
        else
        {
#ifdef DEBUGGING_MODE
            printf("MPU6050 is connected.\n");
#endif
        }

#ifdef DEBUGGING_MODE
        // Print the data from the MPU6050Sensor for debugging purposes
        MPU6050Sensor_printData(&mpuSensor);
#endif
        // Read the data from the BMP280Sensor
        bmpSensorConnected = BMP280Sensor_readData(&bmpSensor);

        if (!bmpSensorConnected)
        {
#ifdef DEBUGGING_MODE
            printf("BMP280 sensor not connected!\n");
#endif
            // Apply actual handling procedure here...
            vTaskDelay(pdMS_TO_TICKS(5000));
            BMP280Sensor_init(&bmpSensor);
            bmpSensorConnected = true;
            // TO DO: Determine if this is the correct way to handle the sensor not being connected
            continue;
        }
        else
        {
#ifdef DEBUGGING_MODE
            printf("BMP280 is connected.\n");
#endif
        }

#ifdef DEBUGGING_MODE
        // Print the data from the BMP280Sensor for debugging purposes
        BMP280Sensor_printData(&bmpSensor);
#endif

        // Data Reads are now done, so we can start processing the data

        // Allocate timestamp
        char *my_timestamp = report_time_elapsed();

        // Check if we can insert the data into the window
        if (myWindow->observationCount < 12)
        {
            Observation newObservation;
            newObservation.Pa = bmpSensor.pressure;
            newObservation.Z_rot = mpuSensor.r_z;
            newObservation.Z_acc = mpuSensor.a_z;
            newObservation.Y_acc = mpuSensor.a_y;
            insertObservation(myWindow, newObservation);
        }
        // If we can not, that means the window is full so print the window and calculate the metrics (for debgging purposes)
        else
        {
#ifdef DEBUGGING_MODE
            // Print statements for the observations to ensure the window is correctly working
            for (int i = 0; i < myWindow->observationCount; i++)
            {
                printf("Observation %d: Pa = %f, Z_rot = %f, Z_acc = %f, Y_acc = %f\n", i, myWindow->observations[i].Pa, myWindow->observations[i].Z_rot, myWindow->observations[i].Z_acc, myWindow->observations[i].Y_acc);
            }
#endif
            // Calculate the metrics of the window (these metrics will change as the model changes)
            // Currently these are the valuable metrics from ECEN 403
            Metrics myMetrics = calculateMetrics(myWindow);

            // Assign the calculated metrics to the window
            myWindow->metrics = myMetrics;

            // Now reset the window observations, to free space since the model only needs the metrics, not every observation
            clearObservations(myWindow);

#ifdef DEBUGGING_MODE
            // Debugging Print to ensure the metrics are being calculated correctly, cross compare with the observations previously printed
            printf("Metrics: Pa_roc = %f, Z_rot_max_min = %f, Z_g_max = %f, Z_g_min = %f, Y_g_kurtosis = %f\n", myWindow->metrics.Pa_roc, myWindow->metrics.Z_rot_max_min, myWindow->metrics.Z_g_max, myWindow->metrics.Z_g_min, myWindow->metrics.Y_g_kurtosis);
#endif
            // Now send the window to the queue
            enqueue(myQueue, *myWindow); // TODO: The logic here is not correct so the queue is not gonna work but this is a later problem

#ifdef DEBUGGING_MODE
            // Print the queue for debugging purposes, goal is to see if a window is being added to the queue
            printQueue(myQueue);
#endif

            // Now make a new window called myWindow
            myWindow = createWindow();
        }
        // Handle queue later here after the windows and pass to the model (whatever that entails)

        // Check if timestamp was successfully allocated
        if (my_timestamp != NULL)
        {
            // Use the stored timestamp or perform operations
            // Note that user_id is currently hard coded and will be fully implemented in 404
            a_x = mpuSensor.a_x;
            a_y = mpuSensor.a_y;
            a_z = mpuSensor.a_z;
            r_x = mpuSensor.r_x;
            r_y = mpuSensor.r_y;
            r_z = mpuSensor.r_z;
            temp_calibrated = bmpSensor.temperature;
            press_calibrated = bmpSensor.pressure;
            // send_post_request(my_timestamp, 287423, a_x, a_y, a_z, r_x, r_y, r_z, temp_calibrated, press_calibrated);

#ifdef TESTING_MODE
            // Send the sensor data over UART
            send_sensor_data(a_x, a_y, a_z, r_x, r_y, r_z, temp_calibrated, press_calibrated);
#endif

            // Free the allocated memory once done using it
            free(my_timestamp);
        }
    }

    // Delete i2c driver installs
    ESP_ERROR_CHECK(i2c_driver_delete(I2C_MASTER_NUM));

    // Delete the task created for time
    vTaskDelete(NULL);
}

/*
Thanks for reading
HERE'S A HUG :)
*/