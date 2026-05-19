/**
 * @file connectivity_task.c
 * @brief Connectivity management FreeRTOS task implementation.
 *
 * This file contains the connectivity task responsible
 * for managing and indicating system connectivity status.
 *
 * Current functionality:
 * - Connectivity status LED indication
 * - Periodic LED blinking for task activity validation
 *
 * Future responsibilities:
 * - Wi-Fi management
 * - MQTT communication
 * - Alexa integration
 * - Cloud connectivity monitoring
 * - Network reconnection handling
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

#include "connectivity_task.h"

#include "driver/gpio.h"

#include "../../bsp/bsp_pins.h"

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

/**
 * @brief Connectivity management task.
 *
 * This FreeRTOS task periodically toggles the
 * connectivity status LED to indicate task execution.
 *
 * Current behavior:
 * - LED ON for 1500 ms
 * - LED OFF for 1500 ms
 *
 * @param pvParameters Pointer to optional task parameters.
 */
void connectivity_task(void *pvParameters)
{
    while (1)
    {
        /**
         * @brief Turn connectivity LED ON.
         */
        gpio_set_level(CONNECTIVITY_LED_GPIO, 1);

        vTaskDelay(pdMS_TO_TICKS(1500));

        /**
         * @brief Turn connectivity LED OFF.
         */
        gpio_set_level(CONNECTIVITY_LED_GPIO, 0);

        vTaskDelay(pdMS_TO_TICKS(1500));
    }
}