#include "component_b.h"
#include "unity.h"
#include "Mockcomponent_a.h"
#include "Mockcomponent_c.h"

static const char test_tag[] = "[component_b]";

TEST_CASE("B 1", test_tag)
{
    Mockcomponent_a_Init();
    component_a_increment_ExpectAnyArgsAndReturn(2);
    TEST_ASSERT_EQUAL(0, component_b_add(1));
}

TEST_CASE("B 2", test_tag)
{
    Mockcomponent_a_Init();
    component_b_init(11);
    component_a_increment_ExpectAndReturn(12, 13);
    TEST_ASSERT_EQUAL(12, component_b_add(1));
}

TEST_CASE("B 3", test_tag)
{
    Mockcomponent_c_Init();
    component_b_init(11);
    TEST_ASSERT_EQUAL(112, component_b_do(1));
}