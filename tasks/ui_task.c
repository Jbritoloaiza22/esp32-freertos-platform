/**
 * @file ui_task.c
 * @brief User Interface FreeRTOS task implementation.
 *
 * This file contains the UI task responsible
 * for handling graphical user interface operations
 * within the ESP32 firmware platform.
 *
 * Current functionality:
 * - UI activity LED indication
 * - Periodic LED blinking for task validation
 *
 * Future responsibilities:
 * - LVGL task handling
 * - Screen rendering
 * - Widget updates
 * - User interaction management
 * - Display refresh synchronization
 * - UI event processing
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

#include "ui_task.h"

#include "driver/gpio.h"

#include "../../bsp/bsp_pins.h"

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

/**
 * @brief User Interface FreeRTOS task.
 *
 * This task periodically toggles the UI
 * status LED to indicate task execution.
 *
 * Current behavior:
 * - LED ON for 1000 ms
 * - LED OFF for 1000 ms
 *
 * @param pvParameters Pointer to optional task parameters.
 */
void ui_task(void *pvParameters)
{
    while (1)
    {
        /**
         * @brief Turn UI LED ON.
         */
        gpio_set_level(UI_LED_GPIO, 1);

        vTaskDelay(pdMS_TO_TICKS(1000));

        /**
         * @brief Turn UI LED OFF.
         */
        gpio_set_level(UI_LED_GPIO, 0);

        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}