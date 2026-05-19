/**
 * @file control_task.h
 * @brief System control task public interface.
 *
 * This header file provides the public API for the
 * control management FreeRTOS task used by the
 * ESP32 firmware platform.
 *
 * The control task is responsible for:
 * - Relay control
 * - Automation logic
 * - Local button handling
 * - Remote command processing
 * - System actuator management
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

#ifndef CONTROL_TASK_H
#define CONTROL_TASK_H

/**
 * @brief System control FreeRTOS task.
 *
 * Executes actuator management and system
 * control operations.
 *
 * @param pvParameters Pointer to optional task parameters.
 */
void control_task(void *pvParameters);

#endif /* CONTROL_TASK_H */