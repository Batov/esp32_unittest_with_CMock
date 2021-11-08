set(PRIV_REQUIRES )
set(INCLUDE_DIRS ".")

if(DEFINED ENV{RUN_UNITTESTS})
    list(APPEND PRIV_REQUIRES freertos_mock)
    list(APPEND INCLUDE_DIRS "${PROJECT_DIR}/mocks/freertos_mock")
endif()

idf_component_register(SRCS "component_d.c"
                       PRIV_REQUIRES ${PRIV_REQUIRES}
                       INCLUDE_DIRS ${INCLUDE_DIRS})