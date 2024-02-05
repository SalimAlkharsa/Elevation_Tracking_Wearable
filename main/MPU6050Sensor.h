#ifndef MPU6050_SENSOR_H
#define MPU6050_SENSOR_H

#include <stdint.h>
#include <stdbool.h>
#include "driver/i2c.h"
#include "esp_log.h"

typedef struct
{
    int start_register;
    int end_register;
    float a_x;
    float a_y;
    float a_z;
    float r_x;
    float r_y;
    float r_z;

    i2c_cmd_handle_t cmd;
} MPU6050Sensor;

// Function declarations
esp_err_t MPU6050Sensor_register_read_byte(MPU6050Sensor *sensor, uint8_t reg_addr, uint8_t *data, size_t len);
bool MPU6050Sensor_checkI2COperation(esp_err_t operationResult);
void MPU6050Sensor_init(MPU6050Sensor *sensor);
void MPU6050Sensor_initialize(MPU6050Sensor *sensor);
bool MPU6050Sensor_readData(MPU6050Sensor *sensor);
void MPU6050Sensor_printData(MPU6050Sensor *sensor);

#endif // MPU6050_SENSOR_H
