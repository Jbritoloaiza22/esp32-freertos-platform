/**
 * @file task_manager.c
 * @brief FreeRTOS task manager implementation.
 *
 * This file contains the task creation and startup
 * routines for the ESP32 firmware platform.
 *
 * Responsibilities:
 * - Create application FreeRTOS tasks
 * - Configure task priorities
 * - Configure task stack sizes
 * - Initialize multitasking execution
 *
 * Managed tasks:
 * - Heartbeat task
 * - UI task
 * - Sensor task
 * - Connectivity task
 * - Control task
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

#include "task_manager.h"

#include "../tasks/heartbeat_task.h"
#include "../tasks/ui_task.h"
#include "../tasks/sensor_task.h"
#include "../tasks/connectivity_task.h"
#include "../tasks/control_task.h"

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

/**
 * @brief Create and start all application FreeRTOS tasks.
 *
 * This function initializes the multitasking environment
 * by creating all application tasks required by the system.
 *
 * Created tasks:
 * - Heartbeat monitoring task
 * - User interface task
 * - Sensor acquisition task
 * - Connectivity management task
 * - Control logic task
 *
 * @note
 * Task priorities and stack sizes should be tuned
 * according to application requirements.
 */
void task_manager_start(void)
{
    /**
     * @brief Heartbeat monitoring task.
     */
    xTaskCreate(
        heartbeat_task,
        "heartbeat_task",
        2048,
        NULL,
        1,
        NULL
    );

    /**
     * @brief User interface management task.
     */
    xTaskCreate(
        ui_task,
        "ui_task",
        4096,
        NULL,
        2,
        NULL
    );

    /**
     * @brief Sensor acquisition and monitoring task.
     */
    xTaskCreate(
        sensor_task,
        "sensor_task",
        4096,
        NULL,
        2,
        NULL
    );

    /**
     * @brief Connectivity management task.
     */
    xTaskCreate(
        connectivity_task,
        "connectivity_task",
        4096,
        NULL,
        2,
        NULL
    );

    /**
     * @brief System control logic task.
     */
    xTaskCreate(
        control_task,
        "control_task",
        4096,
        NULL,
        2,
        NULL
    );
}