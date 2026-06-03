/******************************************************************************
 * @file    st7789.c
 * @brief   ST7789 LCD Driver and LVGL Display Interface
 *
 * @author  Jesus Daniel Britoloaiza
 *
 * @copyright
 * Copyright (c) 2026 Jesus Daniel Britoloaiza.
 *
 * This source code was developed for educational and academic purposes.
 * Permission is granted to use, study, modify, and distribute this code
 * for learning, research, and non-commercial educational activities,
 * provided that this copyright notice and author attribution are retained.
 *
 * This software is provided "as is", without warranty of any kind,
 * express or implied, including but not limited to the warranties of
 * merchantability, fitness for a particular purpose, and noninfringement.
 * In no event shall the author be liable for any claim, damages, or other
 * liability arising from the use of this software.
 *
 * Project: ESP32 FreeRTOS Platform
 * Module : ST7789 LCD Driver
 ******************************************************************************/
#include "st7789.h"
#include "esp_heap_caps.h"
#include "driver/spi_master.h"
#include "driver/gpio.h"

#include "esp_lcd_panel_io.h"
#include "esp_lcd_panel_vendor.h"
#include "esp_lcd_panel_ops.h"

#include "lvgl.h"

#define LCD_HOST SPI2_HOST

#define PIN_NUM_MOSI 23
#define PIN_NUM_CLK  18
#define PIN_NUM_CS    5
#define PIN_NUM_DC   2
#define PIN_NUM_RST  4
#define PIN_NUM_BCKL 21

#define LCD_H_RES 240
#define LCD_V_RES 320

static esp_lcd_panel_handle_t panel_handle = NULL;
static lv_display_t *display = NULL;

static lv_color_t *buf1 = NULL;
static lv_color_t *buf2 = NULL;

/* ============================================================
 * LVGL Flush Callback
 * ============================================================
 */

static void lvgl_flush_cb(
    lv_display_t *disp,
    const lv_area_t *area,
    uint8_t *px_map)
{
    esp_lcd_panel_draw_bitmap(
        panel_handle,
        area->x1,
        area->y1,
        area->x2 + 1,
        area->y2 + 1,
        px_map
    );

    lv_display_flush_ready(disp);
}

/* ============================================================
 * Init
 * ============================================================
 */

void st7789_init(void)
{
    gpio_config_t bk_gpio = {
        .mode = GPIO_MODE_OUTPUT,
        .pin_bit_mask = 1ULL << PIN_NUM_BCKL
    };

    gpio_config(&bk_gpio);

    gpio_set_level(PIN_NUM_BCKL, 1);

    spi_bus_config_t buscfg = {
        .sclk_io_num = PIN_NUM_CLK,
        .mosi_io_num = PIN_NUM_MOSI,
        .miso_io_num = -1,
        .quadwp_io_num = -1,
        .quadhd_io_num = -1,
        .max_transfer_sz = LCD_H_RES * 40 * sizeof(uint16_t),
    };

    ESP_ERROR_CHECK(spi_bus_initialize(
        LCD_HOST,
        &buscfg,
        SPI_DMA_CH_AUTO));

    esp_lcd_panel_io_spi_config_t io_config = {
        .dc_gpio_num = PIN_NUM_DC,
        .cs_gpio_num = PIN_NUM_CS,
        .pclk_hz = 40 * 1000 * 1000,
        .lcd_cmd_bits = 8,
        .lcd_param_bits = 8,
        .spi_mode = 0,
        .trans_queue_depth = 10,
    };

    esp_lcd_panel_io_handle_t io_handle = NULL;

    ESP_ERROR_CHECK(
        esp_lcd_new_panel_io_spi(
            (esp_lcd_spi_bus_handle_t)LCD_HOST,
            &io_config,
            &io_handle
        )
    );

    esp_lcd_panel_dev_config_t panel_config = {
        .reset_gpio_num = PIN_NUM_RST,
        .rgb_ele_order = LCD_RGB_ELEMENT_ORDER_BGR,
        .bits_per_pixel = 16,
    };

    ESP_ERROR_CHECK(
        esp_lcd_new_panel_st7789(
            io_handle,
            &panel_config,
            &panel_handle
        )
    );

    ESP_ERROR_CHECK(esp_lcd_panel_reset(panel_handle));
    ESP_ERROR_CHECK(esp_lcd_panel_init(panel_handle));

    ESP_ERROR_CHECK(esp_lcd_panel_swap_xy(panel_handle, false));
    ESP_ERROR_CHECK(esp_lcd_panel_mirror(panel_handle, true, true));

    ESP_ERROR_CHECK(esp_lcd_panel_invert_color(panel_handle, true));

    ESP_ERROR_CHECK(esp_lcd_panel_disp_on_off(panel_handle, true));

    /* =======================================================
     * LVGL
     * =======================================================
     */

    display = lv_display_create(LCD_H_RES, LCD_V_RES);

    buf1 = heap_caps_malloc(
        LCD_H_RES * 40 * sizeof(lv_color_t),
        MALLOC_CAP_DMA
    );

    buf2 = heap_caps_malloc(
        LCD_H_RES * 40 * sizeof(lv_color_t),
        MALLOC_CAP_DMA
    );

    lv_display_set_buffers(
        display,
        buf1,
        buf2,
        LCD_H_RES * 40 * sizeof(lv_color_t),
        LV_DISPLAY_RENDER_MODE_PARTIAL
    );

    lv_display_set_flush_cb(display, lvgl_flush_cb);
}