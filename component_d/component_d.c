#include "component_d.h"

#include <stdbool.h>
#include "freertos/FreeRTOS.h"
#include "freertos/semphr.h"
#include "esp_log.h"
#include "esp_err.h"

static uint32_t base = 0;
static SemaphoreHandle_t mutex = NULL;
static const char *TAG = "component_d";

static bool lock(void)
{
    if (mutex != NULL && xSemaphoreTake(mutex, pdMS_TO_TICKS(100)) == pdTRUE)
        return true;
    else
        ESP_LOGE(TAG, "Mutex error");

    return false;
}

static bool unlock(void)
{
    if (mutex != NULL)
    {
        xSemaphoreGive(mutex);
        return true;
    }

    return false;
}

void component_d_init(void)
{
    mutex = xSemaphoreCreateMutex();
}

uint32_t component_d_do(uint32_t in)
{
    uint32_t res = 0;
    if (lock())
    {
        base += in;
        res = base;
        unlock();
    }
    return res;
}

void component_d_deinit(void)
{
    vSemaphoreDelete(mutex);
}