/**
 * @file bsp_board.c
 * @brief Board Support Package (BSP) hardware initialization.
 *
 * This file contains the low-level board initialization routines
 * for the ESP32 platform. GPIO peripherals used by the application
 * are configured here during system startup.
 *
 * Configured peripherals:
 * - Heartbeat LED
 * - UI status LED
 * - Sensor activity LED
 * - Connectivity status LED
 * - Control status LED
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

#include "bsp_board.h"
#include "../../bsp/bsp_pins.h"

#include "driver/gpio.h"

/**
 * @brief Initialize board GPIO peripherals.
 *
 * Configures all application status LEDs as GPIO outputs.
 * This function is executed during system startup as part
 * of the BSP initialization layer.
 *
 * Configured GPIOs:
 * - HEARTBEAT_LED_GPIO
 * - UI_LED_GPIO
 * - SENSOR_LED_GPIO
 * - CONNECTIVITY_LED_GPIO
 * - CONTROL_LED_GPIO
 */
void bsp_board_init(void)
{
    gpio_config_t io_conf =
    {
        .mode = GPIO_MODE_OUTPUT,

        .pin_bit_mask =
            (1ULL << HEARTBEAT_LED_GPIO)    |
            (1ULL << UI_LED_GPIO)           |
            (1ULL << SENSOR_LED_GPIO)       |
            (1ULL << CONNECTIVITY_LED_GPIO) |
            (1ULL << CONTROL_LED_GPIO)
    };

    gpio_config(&io_conf);
}