/**
 * @file ui_task.h
 * @brief User Interface Task Declaration.
 *
 * This module defines the task responsible for managing user interface
 * elements within the embedded system.
 *
 * @note Designed for FreeRTOS-based environments.
 *
 * @author
 * Jesus Daniel Britoloaiza
 *
 * @license
 * -----------------------------------------------------------------------------
 * MIT License (Adapted for Educational and Research Use)
 *
 * Copyright (c) 2026 Jesus Daniel Britoloaiza
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 *
 * This software is intended for educational, academic, and research purposes.
 * -----------------------------------------------------------------------------
 */

#ifndef UI_TASK_H
#define UI_TASK_H

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Crea la pantalla UI de datos.
 */
void ui_dashboard_create(void);

/**
 * @brief Actualiza los valores mostrados en la UI.
 */
void ui_dashboard_update(float voltage, float current);

/**
 * @brief Tarea principal de la interfaz de usuario.
 *
 * Esta función implementa una tarea compatible con FreeRTOS que maneja
 * la lógica de la interfaz de usuario (LEDs, botones, indicadores, etc.).
 *
 * @param pvParameters Parámetro genérico de FreeRTOS (no utilizado o usado
 *                     para pasar configuración de la tarea).
 *
 * @return No retorna nunca (bucle infinito dentro de la tarea).
 */
void ui_task(void *pvParameters);

#ifdef __cplusplus
}
#endif

#endif /* UI_TASK_H */