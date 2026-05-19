/**
 * @file bsp_pins.h
 * @brief GPIO pin mapping definitions for the ESP32 platform.
 *
 * This file centralizes all hardware pin assignments used
 * throughout the firmware architecture.
 *
 * The BSP pin layer provides a single location for
 * maintaining GPIO mappings, improving portability
 * and hardware abstraction.
 *
 * Defined GPIOs:
 * - Heartbeat status LED
 * - UI status LED
 * - Sensor activity LED
 * - Connectivity status LED
 * - Control activity LED
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

#ifndef BSP_PINS_H
#define BSP_PINS_H

#include "driver/gpio.h"

/**
 * @brief Heartbeat task status LED.
 */
#define HEARTBEAT_LED_GPIO      GPIO_NUM_2

/**
 * @brief User interface task status LED.
 */
#define UI_LED_GPIO             GPIO_NUM_4

/**
 * @brief Sensor task activity LED.
 */
#define SENSOR_LED_GPIO         GPIO_NUM_5

/**
 * @brief Connectivity task status LED.
 */
#define CONNECTIVITY_LED_GPIO   GPIO_NUM_18

/**
 * @brief Control task activity LED.
 */
#define CONTROL_LED_GPIO        GPIO_NUM_19

#endif /* BSP_PINS_H */