/**
 * @file bsp_board.h
 * @brief Board Support Package (BSP) interface definitions.
 *
 * This header file provides the public interface for
 * board-level hardware initialization routines used
 * by the ESP32 platform firmware.
 *
 * The BSP layer abstracts low-level hardware setup
 * and centralizes GPIO configuration for the system.
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

#ifndef BSP_BOARD_H
#define BSP_BOARD_H

#include "driver/gpio.h"

/**
 * @brief Default onboard LED GPIO definition.
 */
#define LED_GPIO GPIO_NUM_2

/**
 * @brief Initialize board hardware peripherals.
 *
 * Configures the GPIOs and peripherals required
 * during system startup.
 */
void bsp_board_init(void);

#endif /* BSP_BOARD_H */