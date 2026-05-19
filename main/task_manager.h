/**
 * @file task_manager.h
 * @brief FreeRTOS task manager public interface.
 *
 * This header file provides the public API for the
 * task management layer used by the ESP32 firmware
 * platform.
 *
 * The task manager is responsible for:
 * - Creating FreeRTOS application tasks
 * - Managing multitasking startup
 * - Organizing task initialization flow
 * - Coordinating system execution layers
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

#ifndef TASK_MANAGER_H
#define TASK_MANAGER_H

/**
 * @brief Create and start all application tasks.
 *
 * Initializes the FreeRTOS multitasking environment
 * by creating all firmware application tasks.
 */
void task_manager_start(void);

#endif /* TASK_MANAGER_H */