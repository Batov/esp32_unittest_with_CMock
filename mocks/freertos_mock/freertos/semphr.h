#pragma once

#include <stdbool.h>

typedef void *SemaphoreHandle_t;

SemaphoreHandle_t sema_create();
bool sema_give(SemaphoreHandle_t);
bool sema_take(SemaphoreHandle_t, uint32_t);
void sema_delete(SemaphoreHandle_t);

#define xSemaphoreCreateMutex() sema_create()
#define xSemaphoreGive(xSemaphore) sema_give(xSemaphore)
#define xSemaphoreTake(xSemaphore, xBlockTime) sema_take(xSemaphore, xBlockTime)
#define vSemaphoreDelete(xSemaphore) sema_delete(xSemaphore)
