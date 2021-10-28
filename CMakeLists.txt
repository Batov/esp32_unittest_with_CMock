# The following lines of boilerplate have to be in your project's
# CMakeLists in this exact order for cmake to work correctly
cmake_minimum_required(VERSION 3.5)  
include($ENV{IDF_PATH}/tools/cmake/project.cmake)

#list(APPEND EXTRA_COMPONENT_DIRS "component_a")
list(APPEND EXTRA_COMPONENT_DIRS "component_b")

list(APPEND EXTRA_COMPONENT_DIRS "mocks/component_a") 

list(APPEND TEST_COMPONENTS "component_a") 
list(APPEND TEST_COMPONENTS "component_b")

if(DEFINED ENV{RUN_UNITTESTS})  
    set(SDKCONFIG_DEFAULTS "sdkconfig.unittest")
endif()
 
project(hello-world)