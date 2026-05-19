idf_component_register(
    SRCS
        "main.c"
        "system_init.c"
        "task_manager.c"

        "../tasks/heartbeat_task.c"
        "../tasks/ui_task.c"
        "../tasks/sensor_task.c"
        "../tasks/connectivity_task.c"
        "../tasks/control_task.c"

        "../bsp/bsp_board.c"

        "../drivers/led/led.c"

    INCLUDE_DIRS
        "."
        "../tasks"
        "../bsp"
        "../drivers/led"
)