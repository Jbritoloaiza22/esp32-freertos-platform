/**
 * @file system_init.c
 * @brief System initialization layer implementation.
 *
 * This file contains the global system initialization
 * routines executed during firmware startup.
 *
 * Responsibilities:
 * - Initialize Board Support Package (BSP)
 * - Initialize hardware drivers
 * - Initialize middleware services
 * - Prepare the system before task execution
 *
 * The initialization sequence follows a layered
 * embedded architecture approach:
 * - BSP Layer
 * - Drivers Layer
 * - Services Layer
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

#include "system_init.h"

#include "../bsp/bsp_board.h"

#include "../drivers/led/led.h"

#include "../services/ui/ui_manager.h"

/**
 * @brief Initialize the complete embedded system.
 *
 * Executes the startup initialization sequence for:
 * - BSP layer
 * - Hardware drivers
 * - Middleware services
 *
 * This function is executed before starting
 * the FreeRTOS task scheduler.
 */
void system_init(void)
{
    /**
     * @brief Initialize Board Support Package.
     */
    bsp_board_init();

    /**
     * @brief Initialize hardware drivers.
     */

    // relay_init();

    led_init();

    // button_init();

    // display_init();

    // lv_port_disp_init();

    // pzem_init();

    /**
     * @brief Initialize middleware services.
     */

    // ui_manager_init();
}