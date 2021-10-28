set(original_component_dir "${PROJECT_DIR}/component_a")

set(INCLUDE_DIRS "${original_component_dir}/include")
set(REQUIRES "")
set(MOCK_HEADER_FILES "${original_component_dir}/include/component_a.h")
include(${CMAKE_CURRENT_LIST_DIR}/../mock.cmake)