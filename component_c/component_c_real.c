#include "component_c.h"
#include <stdio.h>


uint32_t component_c_do_real(uint32_t in)
{
    printf("I am real component_c_do\r\n");
    return in + 100;
}