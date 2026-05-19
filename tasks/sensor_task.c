/**
 * @file sensor_task.c
 * @brief Sensor management FreeRTOS task implementation.
 *
 * This file contains the sensor task responsible
 * for handling sensor acquisition and monitoring
 * within the ESP32 firmware platform.
 *
 * Current functionality:
 * - Sensor activity LED indication
 * - Periodic LED blinking for task validation
 *
 * Future responsibilities:
 * - PZEM-004T data acquisition
 * - Voltage measurement
 * - Current measurement
 * - Power consumption monitoring
 * - Energy usage calculations
 * - Sensor fault detection
 *
 * @author Jesus Daniel Brito Loaiza
 * @date 2026
 *
 * @note
 * This project is intended for educational, research,
 * and embedded systems learning purposes.
 *
 * @copyright
 * Copyright (c) 2026.
 * Permission is granted to use, modify, and distribute this
 * software for educational and research purposes only.
 */

#include "sensor_task.h"

#include "driver/gpio.h"

#include "../../bsp/bsp_pins.h"

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

/**
 * @brief Sensor management FreeRTOS task.
 *
 * This task periodically toggles the sensor
 * status LED to indicate task execution.
 *
 * Current behavior:
 * - LED ON for 200 ms
 * - LED OFF for 200 ms
 *
 * @param pvParameters Pointer to optional task parameters.
 */
void sensor_task(void *pvParameters)
{
    while (1)
    {
        /**
         * @brief Turn sensor LED ON.
         */
        gpio_set_level(SENSOR_LED_GPIO, 1);

        vTaskDelay(pdMS_TO_TICKS(200));

        /**
         * @brief Turn sensor LED OFF.
         */
        gpio_set_level(SENSOR_LED_GPIO, 0);

        vTaskDelay(pdMS_TO_TICKS(200));
    }
}