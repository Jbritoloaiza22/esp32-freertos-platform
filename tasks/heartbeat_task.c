/**
 * @file heartbeat_task.c
 * @brief System heartbeat FreeRTOS task implementation.
 *
 * This file contains the heartbeat task responsible
 * for providing a visual indication that the firmware
 * is running correctly.
 *
 * Current functionality:
 * - Heartbeat LED blinking
 * - System alive indication
 * - Basic scheduler activity validation
 *
 * Future responsibilities:
 * - Watchdog monitoring
 * - System diagnostics
 * - Runtime health supervision
 * - Fault indication handling
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

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "driver/gpio.h"

#include "../../bsp/bsp_pins.h"

#include <stdio.h>

/**
 * @brief System heartbeat FreeRTOS task.
 *
 * This task periodically toggles the heartbeat
 * LED to indicate that the firmware is executing
 * correctly and the scheduler is active.
 *
 * Current behavior:
 * - LED ON for 500 ms
 * - LED OFF for 500 ms
 *
 * @param pvParameters Pointer to optional task parameters.
 */
void heartbeat_task(void *pvParameters)
{
    while (1)
    {
        /**
         * @brief Turn heartbeat LED ON.
         */
        gpio_set_level(HEARTBEAT_LED_GPIO, 1);

        vTaskDelay(pdMS_TO_TICKS(500));

        /**
         * @brief Turn heartbeat LED OFF.
         */
        gpio_set_level(HEARTBEAT_LED_GPIO, 0);

        vTaskDelay(pdMS_TO_TICKS(500));
    }
}