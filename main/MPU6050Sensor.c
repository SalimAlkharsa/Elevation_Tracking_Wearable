#include "MPU6050Sensor.h"

// Some defines for the MPU6050 sensor
#define I2C_MASTER_NUM 0
#define I2C_MASTER_TIMEOUT_MS 1000
// Note that this "MPU6050_SENSOR_ADDR" is the address read on the i2c_tools code
#define MPU6050_SENSOR_ADDR 0x68

// While the "MPU6050_WHO_AM_I_REG_ADDR" is the address for the specific register inside the sensor
#define MPU6050_WHO_AM_I_REG_ADDR 0x75
#define MPU6050_PWR_MGMT_1_REG_ADDR 0x6B
#define MPU6050_POWER_UP_DELAY_MS 100 // Register begins for a_x data, first variable for this specific example's data read
#define MPU6050_ACCEL_XOUT_H 0x3B

// This is arbitrary, need a tag but the name isn't important
static const char *TAG = "demo";

// Private functions
// Helper functions for reading information from each sensor
esp_err_t MPU6050Sensor_register_read_byte(MPU6050Sensor *sensor, uint8_t reg_addr, uint8_t *data, size_t len)
{
    return i2c_master_write_read_device(I2C_MASTER_NUM, MPU6050_SENSOR_ADDR, &reg_addr, 1, data, len, I2C_MASTER_TIMEOUT_MS / portTICK_PERIOD_MS);
}

/*
    Fail silently function that will change a boolean value.
    This way, instead of throwing the traditional ESP_ERROR_CHECK if a sensor is removed.
    It will just wait until a sequence of events has been performed before throwing the error.
    In this example, this is used to error check if a sensor is not properly plugged in.
*/
bool MPU6050Sensor_checkI2COperation(esp_err_t operationResult)
{
    if (operationResult != ESP_OK)
    {
        return false;
    }
    return true;
}

/*
    Initialize the MPU6050 so that it will properly give data.
    Must write to the board to reset before it can be read from.
*/
void MPU6050Sensor_init(MPU6050Sensor *sensor)
{
    esp_err_t err = ESP_OK;

    // Create a new I2C command handle
    sensor->cmd = i2c_cmd_link_create();

    // Initiating I2C operations to reset the sensor
    MPU6050Sensor_checkI2COperation(i2c_master_start(sensor->cmd));
    MPU6050Sensor_checkI2COperation(i2c_master_write_byte(sensor->cmd, (MPU6050_SENSOR_ADDR << 1) | I2C_MASTER_WRITE, 1));
    MPU6050Sensor_checkI2COperation(i2c_master_write_byte(sensor->cmd, MPU6050_PWR_MGMT_1_REG_ADDR, 1));
    MPU6050Sensor_checkI2COperation(i2c_master_write_byte(sensor->cmd, 0, 1));
    MPU6050Sensor_checkI2COperation(i2c_master_stop(sensor->cmd));
    MPU6050Sensor_checkI2COperation(i2c_master_cmd_begin(I2C_NUM_0, sensor->cmd, 1000 / portTICK_PERIOD_MS));

    // Read the WHO_AM_I register to ensure this is the correct sensor
    uint8_t mpu6050_who_am_i_value;
    err = MPU6050Sensor_register_read_byte(sensor, MPU6050_WHO_AM_I_REG_ADDR, &mpu6050_who_am_i_value, 1);

    // Check if sensor initialization is successful and if the correct sensor is detected
    if (MPU6050Sensor_checkI2COperation(err) && mpu6050_who_am_i_value == MPU6050_SENSOR_ADDR)
    {
        ESP_LOGI(TAG, "MPU6050 sensor detected.");
    }
    else
    {
        ESP_LOGE(TAG, "MPU6050 initialization failed");
    }

    i2c_cmd_link_delete(sensor->cmd);
}

// Public functions
void MPU6050Sensor_initialize(MPU6050Sensor *sensor)
{
    MPU6050Sensor_init(sensor);
}

bool MPU6050Sensor_readData(MPU6050Sensor *sensor)
{
    sensor->start_register = 0x3B;
    sensor->end_register = 0x48;
    uint8_t mpu6050_data[sensor->end_register - sensor->start_register + 1];

    // Set mpu6050_connected flag to true so if checkI2COperation finds a fail, notified
    bool mpu6050_connected = true;
    sensor->cmd = i2c_cmd_link_create();

    ESP_ERROR_CHECK_WITHOUT_ABORT(i2c_master_start(sensor->cmd));

    // Write to the sensor to start acceleration - rotation reads
    mpu6050_connected &= MPU6050Sensor_checkI2COperation(i2c_master_write_byte(sensor->cmd, (MPU6050_SENSOR_ADDR << 1) | I2C_MASTER_WRITE, 1));
    mpu6050_connected &= MPU6050Sensor_checkI2COperation(i2c_master_write_byte(sensor->cmd, sensor->start_register, 1));
    mpu6050_connected &= MPU6050Sensor_checkI2COperation(i2c_master_start(sensor->cmd));
    mpu6050_connected &= MPU6050Sensor_checkI2COperation(i2c_master_write_byte(sensor->cmd, (MPU6050_SENSOR_ADDR << 1) | I2C_MASTER_READ, 1));

    // Read 14 bytes for acceleration - rotation data
    mpu6050_connected &= MPU6050Sensor_checkI2COperation(i2c_master_read(sensor->cmd, mpu6050_data, 14, I2C_MASTER_LAST_NACK));
    mpu6050_connected &= MPU6050Sensor_checkI2COperation(i2c_master_stop(sensor->cmd));
    mpu6050_connected &= MPU6050Sensor_checkI2COperation(i2c_master_cmd_begin(I2C_NUM_0, sensor->cmd, 1000 / portTICK_PERIOD_MS));

    if (!mpu6050_connected)
    {
        printf("MPU6050 sensor not connected!\n");
        return false;
    }

    // Convert the data
    sensor->a_x = (mpu6050_data[0] << 8) | (mpu6050_data[1]);
    sensor->a_y = (mpu6050_data[2] << 8) | (mpu6050_data[3]);
    sensor->a_z = (mpu6050_data[4] << 8) | (mpu6050_data[5]);

    sensor->a_x = sensor->a_x / 8192.0;
    sensor->a_y = sensor->a_y / 8192.0;
    sensor->a_z = sensor->a_z / 8192.0;

    sensor->r_x = (mpu6050_data[8] << 8) | (mpu6050_data[9]);
    sensor->r_y = (mpu6050_data[10] << 8) | (mpu6050_data[11]);
    sensor->r_z = (mpu6050_data[12] << 8) | (mpu6050_data[13]);

    sensor->r_x = sensor->r_x / 131.0;
    sensor->r_y = sensor->r_y / 131.0;
    sensor->r_z = sensor->r_z / 131.0;

    return mpu6050_connected;
}

void MPU6050Sensor_printData(MPU6050Sensor *sensor)
{
    printf("Acceleration: x = %f, y = %f, z = %f g\n", sensor->a_x, sensor->a_y, sensor->a_z);
    printf("Rotation: x = %f, y = %f, z = %f degrees/sec\n", sensor->r_x, sensor->r_y, sensor->r_z);
}
