# The following lines of boilerplate have to be in your project's
# CMakeLists in this exact order for cmake to work correctly
cmake_minimum_required(VERSION 3.5)  
include($ENV{IDF_PATH}/tools/cmake/project.cmake)

list(APPEND EXTRA_COMPONENT_DIRS "component_a")
list(APPEND EXTRA_COMPONENT_DIRS "component_b")
list(APPEND EXTRA_COMPONENT_DIRS "component_c")
list(APPEND EXTRA_COMPONENT_DIRS "component_d")

list(APPEND EXTRA_COMPONENT_DIRS "mocks/component_a") 
list(APPEND EXTRA_COMPONENT_DIRS "mocks/component_c_mock") 
list(APPEND EXTRA_COMPONENT_DIRS "mocks/freertos_mock") 

list(APPEND EXTRA_COMPONENT_DIRS "mocks/cmock") 
 
list(APPEND TEST_COMPONENTS "component_a") 
list(APPEND TEST_COMPONENTS "component_b")
list(APPEND TEST_COMPONENTS "component_c")
list(APPEND TEST_COMPONENTS "component_d")

if(DEFINED ENV{RUN_UNITTESTS})   
    set(SDKCONFIG_DEFAULTS "sdkconfig.unittest")
endif() 
 
project(hello-world)