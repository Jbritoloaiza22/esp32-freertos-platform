/**
 * @file connectivity_task.h
 * @brief Connectivity management task public interface.
 *
 * This header file provides the public API for the
 * connectivity management FreeRTOS task used by the
 * ESP32 firmware platform.
 *
 * The connectivity task is responsible for:
 * - Wi-Fi management
 * - Network monitoring
 * - MQTT communication
 * - Alexa/cloud integration
 * - Connectivity status indication
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

#ifndef CONNECTIVITY_TASK_H
#define CONNECTIVITY_TASK_H

/**
 * @brief Connectivity management FreeRTOS task.
 *
 * Handles system connectivity operations and
 * network-related services.
 *
 * @param pvParameters Pointer to optional task parameters.
 */
void connectivity_task(void *pvParameters);

#endif /* CONNECTIVITY_TASK_H */