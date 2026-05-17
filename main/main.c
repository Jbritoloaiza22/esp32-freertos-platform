#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "../tasks/heartbeat_task.h"

void app_main(void)
{
    xTaskCreate(
        heartbeat_task,
        "heartbeat_task",
        2048,
        NULL,
        1,
        NULL
    );
}