idf_component_register(
    SRCS
        "main.c"
        "system_init.c"
        "task_manager.c"

        "../tasks/heartbeat_task.c"
        "../tasks/sensor_task.c"
        "../tasks/connectivity_task.c"
        "../tasks/control_task.c"

        "../bsp/bsp_board.c"
        "../drivers/display/st7789.c"
        "../drivers/led/led.c"

        "../tasks/ui/ui_task.c"
        "../tasks/ui/ui_dashboard.c"

    INCLUDE_DIRS
        "."
        "../tasks"
        "../tasks/ui"
        "../bsp"
        "../drivers/display"
        "../drivers/led"

    REQUIRES
        lvgl
        esp_driver_gpio
        esp_driver_spi
        esp_lcd
        esp_timer
)