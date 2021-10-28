#include "component_c.h"
#include "unity.h"

static const char test_tag[] = "[component_c]";

TEST_CASE("C 1", test_tag)
{
    component_c_do_use_mock(false);
    TEST_ASSERT_EQUAL(component_c_do(1), 101);
}

TEST_CASE("C 2", test_tag)
{
    component_c_do_use_mock(false);
    TEST_ASSERT_EQUAL(component_c_do(100), 200);
}
