set(original_component_dir "${PROJECT_DIR}/component_c")

set(INCLUDE_DIRS "${original_component_dir}/include")
set(REQUIRES "")
set(MOCK_HEADER_FILES "${original_component_dir}/include/component_c_mock.h")

# Waiting for idf_component_mock =)
include(${CMAKE_CURRENT_LIST_DIR}/../idf_component_mock.cmake)