/**
 * @file main.c
 * @brief Main application entry point for the ESP32 platform.
 *
 * This file contains the primary firmware entry point
 * executed by the ESP-IDF runtime after system boot.
 *
 * Responsibilities:
 * - Initialize system hardware and BSP layer
 * - Start application task manager
 * - Launch FreeRTOS-based application architecture
 *
 * The firmware architecture follows a modular layered design:
 * - BSP Layer
 * - Drivers Layer
 * - Services Layer
 * - Task Management Layer
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

#include "system_init.h"
#include "task_manager.h"

/**
 * @brief Main firmware application entry point.
 *
 * This function is automatically executed by the ESP-IDF
 * framework after hardware boot initialization.
 *
 * Execution flow:
 * 1. Initialize system hardware and BSP
 * 2. Start application task manager
 * 3. Launch FreeRTOS multitasking environment
 *
 * @note
 * app_main() is managed internally by ESP-IDF and therefore
 * may appear as unused during static analysis.
 */
// cppcheck-suppress unusedFunction
void app_main(void)
{
    system_init();

    task_manager_start();
}