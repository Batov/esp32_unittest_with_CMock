#include "component_b.h"
#include "component_a.h"

#include <stdbool.h>

static bool init_completed = false;
static uint32_t base = 0;

void component_b_init(uint32_t new_base)
{
    init_completed = true;
    base = new_base;
}

uint32_t component_b_add(uint32_t in)
{
    uint32_t ret = 0;
    if (init_completed)
        ret = component_a_increment(base + in)-1;
    return ret;
}

void component_b_deinit(void)
{
    init_completed = false;
}