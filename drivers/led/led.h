/**
 * @file led.h
 * @brief LED driver public interface definitions.
 *
 * This header file provides the public API for the
 * LED driver used by the ESP32 firmware platform.
 *
 * The LED driver abstracts GPIO configuration for
 * onboard and external status LEDs used for:
 * - System heartbeat indication
 * - Task activity visualization
 * - Debugging support
 * - System status monitoring
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

#ifndef LED_H
#define LED_H

#include "driver/gpio.h"

/**
 * @brief Default onboard LED GPIO definition.
 */
#define LED_GPIO GPIO_NUM_2

/**
 * @brief Initialize LED GPIO peripheral.
 *
 * Configures the LED pin as a GPIO output for
 * status indication and debugging purposes.
 */
void led_init(void);

#endif /* LED_H */