#include "BMP280Sensor.h"

// Defines for BMP280
#define BMP280_SENSOR_ADDR 0x77
#define BMP280_WHO_AM_I_REG_ADDR 0xD0
#define I2C_MASTER_NUM 0
#define I2C_MASTER_TIMEOUT_MS 100
// This is arbitrary, need a tag but the name isn't important
static const char *TAG = "demo";

/*
    Fail silently function that will change a boolean value.
    This way, instead of throwing the traditional ESP_ERROR_CHECK if a sensor is removed.
    It will just wait until a sequence of events has been performed before throwing the error.
    In this example, this is used to error check if a sensor is not properly plugged in.
*/
bool bmp280_checkI2COperation(esp_err_t operationResult)
{
    if (operationResult != ESP_OK)
    {
        return false;
    }
    return true;
}

esp_err_t bmp280_register_read_byte(uint8_t reg_addr, uint8_t *data, size_t len)
{
    return i2c_master_write_read_device(I2C_MASTER_NUM, BMP280_SENSOR_ADDR, &reg_addr, 1, data, len, I2C_MASTER_TIMEOUT_MS / portTICK_PERIOD_MS);
}

/*
    Perform temperature calibration for the BMP280
    Uses blanket function from the datasheet
*/
float bmp280_compensate_T_int32(int32_t adc_T, int32_t dig_T1, int32_t dig_T2, int32_t dig_T3)
{
    int32_t var1, var2, T;
    int32_t t_fine = 0;
    float temp;

    var1 = ((((adc_T >> 3) - ((int32_t)dig_T1 << 1)) * ((int32_t)dig_T2)) >> 11);
    var2 = (((((adc_T >> 4) - ((int32_t)dig_T1)) * ((adc_T >> 4) - ((int32_t)dig_T1))) >> 12) * ((int32_t)dig_T3)) >> 14;

    t_fine = var1 + var2;
    T = (t_fine * 5 + 128) >> 8;

    // Additional calculations added for calibration by me
    temp = T / 100.0;

    return temp;
}

/*
    Perform pressure calibration for the BMP280
    Uses blanket function from the datasheet
*/
float bmp280_compensate_P_int64(int32_t adc_P, int32_t dig_P1, int32_t dig_P2, int32_t dig_P3, int32_t dig_P4, int32_t dig_P5, int32_t dig_P6, int64_t dig_P7, int64_t dig_P8, int64_t dig_P9)
{
    int64_t var1, var2, p;
    int32_t t_fine = 0;
    float press;
    var1 = ((int64_t)t_fine) - 128000;
    var2 = var1 * var1 * (int64_t)dig_P6;
    var2 = var2 + ((var1 * (int64_t)dig_P5) << 17);
    var2 = var2 + (((int64_t)dig_P4) << 35);
    var1 = ((var1 * var1 * (int64_t)dig_P3) >> 8) + ((var1 * (int64_t)dig_P2) << 12);
    var1 = (((((int64_t)1) << 47) + var1)) * ((int64_t)dig_P1) >> 33;

    if (var1 == 0)
    {
        // Avoid exception caused by division by zero
        return 0;
    }

    p = 1048576 - adc_P;
    p = (((p << 31) - var2) * 3125) / var1;
    var1 = (((int64_t)dig_P9) * (p >> 13) * (p >> 13)) >> 25;
    var2 = (((int64_t)dig_P8) * p) >> 19;
    p = ((p + var1 + var2) >> 8) + (((int64_t)dig_P7) << 4);

    press = p / 256.0;
    return press;
}

/*
    Initialize the BMP280 so that it will properly give data
    Must write to the board to reset before it can be read from at two registers
    According to the datasheet, 0xF4 and 0xF5 set the configurations of the device
*/
void BMP280Sensor_init(BMP280Sensor *sensor)
{
    i2c_cmd_handle_t cmd;
    uint8_t bmp280_who_am_i_value;

    cmd = i2c_cmd_link_create();

    bmp280_checkI2COperation(i2c_master_start(cmd));
    bmp280_checkI2COperation(i2c_master_write_byte(cmd, (BMP280_SENSOR_ADDR << 1) | I2C_MASTER_WRITE, 1));
    i2c_master_write_byte(cmd, 0xF5, 1);

    // Pulled these opmode select sets from the BMP280 datasheet
    i2c_master_write_byte(cmd, 0b00011100, 1);
    bmp280_checkI2COperation(i2c_master_stop(cmd));
    bmp280_checkI2COperation(i2c_master_cmd_begin(I2C_NUM_0, cmd, 100 / portTICK_PERIOD_MS));

    i2c_cmd_link_delete(cmd);

    cmd = i2c_cmd_link_create();

    bmp280_checkI2COperation(i2c_master_start(cmd));
    bmp280_checkI2COperation(i2c_master_write_byte(cmd, (BMP280_SENSOR_ADDR << 1) | I2C_MASTER_WRITE, 1));
    i2c_master_write_byte(cmd, 0xF4, 1);

    // Pulled these opmode select sets from the BMP280 datasheet
    i2c_master_write_byte(cmd, 0b11101011, 1);
    // i2c_master_write_byte(cmd, 0b01010111, 1);
    bmp280_checkI2COperation(i2c_master_stop(cmd));
    bmp280_checkI2COperation(i2c_master_cmd_begin(I2C_NUM_0, cmd, 100 / portTICK_PERIOD_MS));

    esp_err_t err = bmp280_register_read_byte(BMP280_WHO_AM_I_REG_ADDR, &bmp280_who_am_i_value, 1);

    if (bmp280_checkI2COperation(err) && bmp280_who_am_i_value == 0x58)
    {
        ESP_LOGI(TAG, "BMP280 sensor detected.");
    }
    else
    {
        ESP_LOGE(TAG, "BMP280 sensor initialization failed");
    }

    i2c_cmd_link_delete(cmd);
}

void BMP280Sensor_initialize(BMP280Sensor *sensor)
{
    BMP280Sensor_init(sensor);
}

bool BMP280Sensor_readData(BMP280Sensor *sensor)
{
    int size;
    // Once read from MPU6050, adjust the register starts for temperature and pressure ADC values
    uint8_t start_register = 0xF7;
    uint8_t end_register = 0xFC;
    uint8_t bmp280_data[end_register - start_register + 1];

    // Create an I2C command link
    sensor->cmd = i2c_cmd_link_create();

    // Write to the sensor to start pressure - temperature reads
    bool bmp280_connected = true;
    i2c_cmd_handle_t cmd;
    cmd = i2c_cmd_link_create();

    // Write to the sensor to start pressure - temperature reads
    bmp280_connected &= bmp280_checkI2COperation(i2c_master_start(cmd));
    bmp280_connected &= bmp280_checkI2COperation(i2c_master_write_byte(cmd, (BMP280_SENSOR_ADDR << 1) | I2C_MASTER_WRITE, 1));
    bmp280_connected &= bmp280_checkI2COperation(i2c_master_write_byte(cmd, start_register, 1));
    bmp280_connected &= bmp280_checkI2COperation(i2c_master_start(cmd));
    bmp280_connected &= bmp280_checkI2COperation(i2c_master_write_byte(cmd, (BMP280_SENSOR_ADDR << 1) | I2C_MASTER_READ, 1));

    // Read 6 bytes for the pressure and temperature data
    bmp280_connected &= bmp280_checkI2COperation(i2c_master_read(cmd, bmp280_data, 6, I2C_MASTER_LAST_NACK));
    bmp280_connected &= bmp280_checkI2COperation(i2c_master_stop(cmd));
    bmp280_connected &= bmp280_checkI2COperation(i2c_master_cmd_begin(I2C_NUM_0, cmd, 100 / portTICK_PERIOD_MS));

    i2c_cmd_link_delete(cmd);

    int32_t adc_P = (bmp280_data[0] << 12) | (bmp280_data[1] << 4) | (bmp280_data[2] & (0xFF));
    int32_t adc_T = (bmp280_data[3] << 12) | (bmp280_data[4] << 4) | (bmp280_data[5] & (0xFF));

    // Adjust start register to read the calibrations
    start_register = 0x88;
    end_register = 0x9F;
    uint8_t calibration_bmp280_data[end_register - start_register + 1];

    // Error check to ensure sensor is constantly reading
    calibration_bmp280_data[0] = 0x11;
    size = sizeof(calibration_bmp280_data) / sizeof(calibration_bmp280_data[0]);

    // Fill in data with dummy values so that we can check and see if new data is written
    for (int i = 1; i < size; i++)
    {
        calibration_bmp280_data[i] = 0x11;
    }

    bool bmp280_calibration_success = true;

    cmd = i2c_cmd_link_create();

    // Perform the I2C operations, checking for success at each step
    bmp280_calibration_success &= bmp280_checkI2COperation(i2c_master_start(cmd));
    bmp280_calibration_success &= bmp280_checkI2COperation(i2c_master_write_byte(cmd, (BMP280_SENSOR_ADDR << 1) | I2C_MASTER_WRITE, 1));
    bmp280_calibration_success &= bmp280_checkI2COperation(i2c_master_write_byte(cmd, start_register, 1));
    bmp280_calibration_success &= bmp280_checkI2COperation(i2c_master_start(cmd));
    bmp280_calibration_success &= bmp280_checkI2COperation(i2c_master_write_byte(cmd, (BMP280_SENSOR_ADDR << 1) | I2C_MASTER_READ, 1));
    bmp280_calibration_success &= bmp280_checkI2COperation(i2c_master_read(cmd, calibration_bmp280_data, 24, I2C_MASTER_LAST_NACK));
    bmp280_calibration_success &= bmp280_checkI2COperation(i2c_master_stop(cmd));
    bmp280_calibration_success &= bmp280_checkI2COperation(i2c_master_cmd_begin(I2C_NUM_0, cmd, 100 / portTICK_PERIOD_MS));

    i2c_cmd_link_delete(cmd);

    if (!bmp280_calibration_success)
    {
        printf("BMP280 calibration read failed!\n");
        return false;
    }

    // Convert the data
    unsigned short dig_T1 = (calibration_bmp280_data[1] << 8) | (calibration_bmp280_data[0]);
    signed short dig_T2 = (calibration_bmp280_data[3] << 8) | (calibration_bmp280_data[2]);
    signed short dig_T3 = (calibration_bmp280_data[5] << 8) | (calibration_bmp280_data[4]);

    // Perform calculations for calibrated temperature
    float temp_calibrated = bmp280_compensate_T_int32(adc_T, dig_T1, dig_T2, dig_T3);

    unsigned short dig_P1 = (calibration_bmp280_data[7] << 8) | (calibration_bmp280_data[6]);
    signed short dig_P2 = (calibration_bmp280_data[9] << 8) | (calibration_bmp280_data[8]);
    signed short dig_P3 = (calibration_bmp280_data[11] << 8) | (calibration_bmp280_data[10]);
    signed short dig_P4 = (calibration_bmp280_data[13] << 8) | (calibration_bmp280_data[12]);
    signed short dig_P5 = (calibration_bmp280_data[15] << 8) | (calibration_bmp280_data[14]);
    signed short dig_P6 = (calibration_bmp280_data[17] << 8) | (calibration_bmp280_data[16]);
    signed short dig_P7 = (calibration_bmp280_data[19] << 8) | (calibration_bmp280_data[18]);
    signed short dig_P8 = (calibration_bmp280_data[21] << 8) | (calibration_bmp280_data[20]);
    signed short dig_P9 = (calibration_bmp280_data[23] << 8) | (calibration_bmp280_data[22]);

    // Perform calculations for calibrated pressure
    float press_calibrated = bmp280_compensate_P_int64(adc_P, dig_P1, dig_P2, dig_P3, dig_P4, dig_P5, dig_P6, dig_P7, dig_P8,
                                                       dig_P9);

    // Set the sensor values
    sensor->temperature = temp_calibrated;
    sensor->pressure = press_calibrated;

    i2c_cmd_link_delete(sensor->cmd);

    return bmp280_connected;
}

void BMP280Sensor_printData(BMP280Sensor *sensor)
{
    printf("Pressure: %.2f Pa\n", sensor->pressure);
    printf("Temperature: %.2f degrees Celsius\n", sensor->temperature);
}
