/**
 * @file ui_task.c
 * @brief User Interface FreeRTOS task implementation.
 *
 * This file contains the UI task responsible
 * for handling graphical user interface operations
 * within the ESP32 firmware platform.
 *
 * Current functionality:
 * - UI activity LED indication
 * - Periodic LED blinking for task validation
 *
 * Future responsibilities:
 * - LVGL task handling
 * - Screen rendering
 * - Widget updates
 * - User interaction management
 * - Display refresh synchronization
 * - UI event processing
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

#include "ui_task.h"

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "lvgl.h"

static lv_obj_t *label_voltage;
static lv_obj_t *label_current;
static lv_obj_t *label_power;
static lv_obj_t *label_connectivity;
static lv_obj_t *title;

void ui_dashboard_create(void)
{
    /* Background */
    lv_obj_t *scr = lv_scr_act();
    lv_obj_remove_style_all(scr);
    lv_obj_set_style_bg_color(scr, lv_color_hex(0x4169E1), 0);
    lv_obj_set_style_bg_opa(scr, LV_OPA_COVER, 0);
    lv_obj_set_style_border_width(scr, 0, 0);

    /* Title */
    title = lv_label_create(scr);
    lv_label_set_text(title, "POWER MONITOR");
    lv_obj_set_style_text_color(title, lv_color_hex(0xFFFFFF), 0);
    lv_obj_set_style_text_font(title, &lv_font_montserrat_26, 0);
    lv_obj_set_style_text_opa(title, LV_OPA_COVER, 0);
    lv_obj_align(title, LV_ALIGN_TOP_MID, 0, 10);

    /* Voltage */
    label_voltage = lv_label_create(scr);
    lv_label_set_text(label_voltage, "Voltage: 0.00 V");
    lv_obj_set_style_text_color(label_voltage, lv_color_hex(0xFFFFFF), 0);
    lv_obj_set_style_text_font(label_voltage, &lv_font_montserrat_22, 0);
    lv_obj_set_style_text_opa(label_voltage, LV_OPA_COVER, 0);
    lv_obj_align(label_voltage, LV_ALIGN_TOP_LEFT, 10, 55);

    /* Current */
    label_current = lv_label_create(scr);
    lv_label_set_text(label_current, "Current: 0.00 A");
    lv_obj_set_style_text_color(label_current, lv_color_hex(0xFFFFFF), 0);
    lv_obj_set_style_text_font(label_current, &lv_font_montserrat_22, 0);
    lv_obj_set_style_text_opa(label_current, LV_OPA_COVER, 0);
    lv_obj_align(label_current, LV_ALIGN_TOP_LEFT, 10, 90);

    /* Power */
    label_power = lv_label_create(scr);
    lv_label_set_text(label_power, "Power: 0.00 W");
    lv_obj_set_style_text_color(label_power, lv_color_hex(0xFFFFFF), 0);
    lv_obj_set_style_text_font(label_power, &lv_font_montserrat_22, 0);
    lv_obj_set_style_text_opa(label_power, LV_OPA_COVER, 0);
    lv_obj_align(label_power, LV_ALIGN_TOP_LEFT, 10, 130);

    /* Connectivity */
    label_connectivity = lv_label_create(scr);
    lv_label_set_text(label_connectivity, "Network: offline");
    lv_obj_set_style_text_color(label_connectivity, lv_color_hex(0xFFFFFF), 0);
    lv_obj_set_style_text_font(label_connectivity, &lv_font_montserrat_22, 0);
    lv_obj_set_style_text_opa(label_connectivity, LV_OPA_COVER, 0);
    lv_obj_align(label_connectivity, LV_ALIGN_TOP_LEFT, 10, 170);
}

void ui_dashboard_update(float voltage, float current)
{
    char buf[64];

    snprintf(buf, sizeof(buf), "Voltage: %.2f V", voltage);
    lv_label_set_text(label_voltage, buf);

    snprintf(buf, sizeof(buf), "Current: %.2f A", current);
    lv_label_set_text(label_current, buf);

    float power = voltage * current;
    snprintf(buf, sizeof(buf), "Power: %.2f W", power);
    lv_label_set_text(label_power, buf);
}

static volatile float async_voltage = 12.0f;
static volatile float async_current = 0.5f;

static void ui_dashboard_update_async(void *arg)
{
    (void)arg;
    ui_dashboard_update(async_voltage, async_current);
}

/* ============================================================
 * UI TASK
 * ============================================================
 */
void ui_task(void *pvParameters)
{
    float voltage = 12.0f;
    float current = 0.5f;

    while (1)
    {
        voltage += 0.01f;
        if (voltage > 12.6f) voltage = 11.8f;

        current += 0.02f;
        if (current > 2.0f) current = 0.3f;

        async_voltage = voltage;
        async_current = current;
        lv_async_call(ui_dashboard_update_async, NULL);

        vTaskDelay(pdMS_TO_TICKS(100));
    }
}