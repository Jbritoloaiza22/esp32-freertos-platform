/**
 * @file sensor_task.h
 * @brief Sensor management task public interface.
 *
 * This header file provides the public API for the
 * sensor management FreeRTOS task used by the
 * ESP32 firmware platform.
 *
 * The sensor task is responsible for:
 * - Sensor data acquisition
 * - Voltage monitoring
 * - Current monitoring
 * - Power measurement
 * - Energy consumption tracking
 * - Sensor status supervision
 *
 * @author Jesus Daniel Britoloaiza
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

#ifndef SENSOR_TASK_H
#define SENSOR_TASK_H

/**
 * @brief Sensor management FreeRTOS task.
 *
 * Executes sensor acquisition and monitoring
 * operations for the embedded system.
 *
 * @param pvParameters Pointer to optional task parameters.
 */
void sensor_task(void *pvParameters);

#endif /* SENSOR_TASK_H */