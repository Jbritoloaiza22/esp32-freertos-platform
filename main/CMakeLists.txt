idf_component_register(
    SRCS
        "main.c"
        "../tasks/heartbeat_task.c"

    INCLUDE_DIRS
        "."
        "../tasks"
)