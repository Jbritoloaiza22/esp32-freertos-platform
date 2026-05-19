/**
 * @file ui_task.h
 * @brief Declaración de la tarea de interfaz de usuario (UI Task).
 *
 * Este módulo define la tarea responsable de manejar elementos de la interfaz
 * de usuario dentro del sistema embebido.
 *
 * @note Diseñado para entornos FreeRTOS.
 *
 * @author
 * Jesús Daniel Britoloaiza
 *
 * @license
 * -----------------------------------------------------------------------------
 * MIT License (adaptada para uso educativo e investigativo)
 *
 * Copyright (c) 2026 Jesús Daniel Britoloaiza
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
 * This software is intended for educational and research purposes.
 * -----------------------------------------------------------------------------
 */

#ifndef UI_TASK_H
#define UI_TASK_H

#ifdef __cplusplus
extern "C" {
#endif

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