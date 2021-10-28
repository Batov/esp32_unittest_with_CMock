#include "component_c.h"
#include "component_c_mock.h"
#include "component_c_real.h"
#include "sdkconfig.h"

#ifdef CONFIG_RUN_UNITTESTS
static bool use_mock = false;

void component_c_do_use_mock(bool _use_mock)
{
    use_mock = _use_mock;
}

uint32_t component_c_do(uint32_t in)
{
    if (use_mock)
        return component_c_do_mock(in);
    else
        return component_c_do_real(in);
        
}
#else
uint32_t component_c_do(uint32_t in) 
{
    return component_c_do_real(in);
}
#endif