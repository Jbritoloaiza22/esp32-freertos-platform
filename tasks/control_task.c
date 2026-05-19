/**
 * @file control_task.c
 * @brief System control FreeRTOS task implementation.
 *
 * This file contains the control task responsible
 * for executing system control logic and actuator
 * management within the ESP32 firmware platform.
 *
 * Current functionality:
 * - Control status LED indication
 * - Periodic LED blinking for task validation
 *
 * Future responsibilities:
 * - Relay control
 * - Button event handling
 * - Power switching logic
 * - Automation routines
 * - Alexa command processing
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

#include "control_task.h"

#include "driver/gpio.h"

#include "../../bsp/bsp_pins.h"

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

/**
 * @brief System control FreeRTOS task.
 *
 * This task periodically toggles the control
 * status LED to indicate task execution.
 *
 * Current behavior:
 * - LED ON for 300 ms
 * - LED OFF for 300 ms
 *
 * @param pvParameters Pointer to optional task parameters.
 */
void control_task(void *pvParameters)
{
    while (1)
    {
        /**
         * @brief Turn control LED ON.
         */
        gpio_set_level(CONTROL_LED_GPIO, 1);

        vTaskDelay(pdMS_TO_TICKS(300));

        /**
         * @brief Turn control LED OFF.
         */
        gpio_set_level(CONTROL_LED_GPIO, 0);

        vTaskDelay(pdMS_TO_TICKS(300));
    }
}