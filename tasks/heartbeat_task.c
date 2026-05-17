#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include <stdio.h>

void heartbeat_task(void *pvParameters)
{
    while (1)
    {
        printf("Heartbeat task running\n");
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}