// BMP280Sensor.h
#ifndef BMP280_SENSOR_H
#define BMP280_SENSOR_H

#include <stdint.h>
#include <stdbool.h>
#include "driver/i2c.h"
#include "esp_log.h"

typedef struct
{
    int32_t adc_P;
    int32_t adc_T;
    float pressure;
    float temperature;

    i2c_cmd_handle_t cmd;
} BMP280Sensor;

// Function declarations
bool bmp280_checkI2COperation(esp_err_t operationResult);
float bmp280_compensate_T_int32(int32_t adc_T, int32_t dig_T1, int32_t dig_T2, int32_t dig_T3);
float bmp280_compensate_P_int64(int32_t adc_P, int32_t dig_P1, int32_t dig_P2, int32_t dig_P3, int32_t dig_P4, int32_t dig_P5, int32_t dig_P6, int64_t dig_P7, int64_t dig_P8, int64_t dig_P9);
esp_err_t bmp280_register_read_byte(uint8_t reg_addr, uint8_t *data, size_t len);
void BMP280Sensor_init(BMP280Sensor *sensor);
void BMP280Sensor_initialize(BMP280Sensor *sensor);
bool BMP280Sensor_readData(BMP280Sensor *sensor);
void BMP280Sensor_printData(BMP280Sensor *sensor);

#endif // BMP280_SENSOR_H
