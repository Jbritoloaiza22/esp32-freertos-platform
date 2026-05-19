/**
 * @file system_init.h
 * @brief System initialization interface definitions.
 *
 * This header file provides the public interface
 * for the global system initialization layer used
 * by the ESP32 firmware platform.
 *
 * The system initialization layer is responsible for:
 * - BSP initialization
 * - Driver initialization
 * - Middleware/service initialization
 * - System startup sequencing
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

#ifndef SYSTEM_INIT_H
#define SYSTEM_INIT_H

/**
 * @brief Initialize the complete embedded system.
 *
 * Executes all startup initialization routines
 * required before launching the FreeRTOS task
 * environment.
 */
void system_init(void);

#endif /* SYSTEM_INIT_H */