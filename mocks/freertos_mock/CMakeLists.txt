set(INCLUDE_DIRS "${CMAKE_CURRENT_SOURCE_DIR}/freertos")
set(REQUIRES "")
set(MOCK_HEADER_FILES "${CMAKE_CURRENT_SOURCE_DIR}/freertos/semphr.h")

include(${PROJECT_DIR}/mocks/idf_component_mock.cmake)
