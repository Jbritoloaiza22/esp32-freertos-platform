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
#include "esp_timer.h"

#include "lvgl.h"
#include "lv_demos.h"
#include "demos/widgets/lv_demo_widgets.h"

#include "system_init.h"
#include "task_manager.h"
#include "../tasks/ui/ui_task.h"

#include "../drivers/display/st7789.h"

/* ============================================================
 * LVGL Task
 * ============================================================
 */
static void lv_tick_task(void *arg)
{
    lv_tick_inc(1);
}
static void lvgl_task(void *pvParameters)
{
    lv_obj_t *scr = lv_scr_act();
    lv_obj_clean(scr);

    ui_dashboard_create();

    while (1)
    {
        lv_timer_handler();
        vTaskDelay(pdMS_TO_TICKS(10));
    }
}

/* ============================================================
 * Main Entry Point
 * ============================================================
 */

void app_main(void)
{
    /* System init */
    system_init();

    /* LVGL init */
    lv_init();
const esp_timer_create_args_t periodic_timer_args = {
    .callback = &lv_tick_task,
    .name = "lv_tick"
};

esp_timer_handle_t periodic_timer;

ESP_ERROR_CHECK(
    esp_timer_create(
        &periodic_timer_args,
        &periodic_timer
    )
);

ESP_ERROR_CHECK(
    esp_timer_start_periodic(
        periodic_timer,
        1000
    )
);
    /* Display init */
    st7789_init();

    /* Start LVGL diagnostic: draw a full red screen first */

    /* LVGL task */
    xTaskCreate(
        lvgl_task,
        "lvgl_task",
        12288,
        NULL,
        5,
        NULL
    );

    /* Start app tasks */
    task_manager_start();
}