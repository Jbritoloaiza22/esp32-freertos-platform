/**
 * @file led.c
 * @brief LED driver implementation for the ESP32 platform.
 *
 * This file contains the low-level LED initialization
 * routines used by the firmware architecture.
 *
 * The LED driver provides GPIO configuration and control
 * for status indication, debugging, and task activity
 * visualization during system execution.
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

#include "led.h"

#include "driver/gpio.h"

#include "../../bsp/bsp_pins.h"

/**
 * @brief Initialize LED GPIO peripheral.
 *
 * Configures the default LED GPIO pin as output mode
 * for status indication and debugging purposes.
 */
void led_init(void)
{
    gpio_config_t io_conf =
    {
        .pin_bit_mask = (1ULL << LED_GPIO),
        .mode = GPIO_MODE_OUTPUT
    };

    gpio_config(&io_conf);
}