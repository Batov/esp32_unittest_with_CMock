#include "component_d.h"
#include "unity.h"
#include "Mocksemphr.h"

static const char test_tag[] = "[component_d]";

TEST_CASE("D 1", test_tag)
{
    Mocksemphr_Init();
    sema_create_ExpectAndReturn((void *)0x1000);
    component_d_init();

    sema_take_ExpectAnyArgsAndReturn(pdTRUE);
    sema_give_ExpectAnyArgsAndReturn(pdTRUE);
    component_d_do(10);
}