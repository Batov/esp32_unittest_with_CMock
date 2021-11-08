list(APPEND REQUIRES "cmock")
set(MOCK_GENERATED_HEADERS "")
set(MOCK_GENERATED_SRCS "")
set(MOCK_FILES "")
set(IDF_PATH $ENV{IDF_PATH})
set(CMOCK_DIR "${PROJECT_DIR}/mocks/cmock/CMock")
set(MOCK_GEN_DIR "${CMAKE_CURRENT_BINARY_DIR}")
list(APPEND INCLUDE_DIRS "${MOCK_GEN_DIR}/mocks")

foreach(header_file ${MOCK_HEADER_FILES})
    get_filename_component(file_without_dir ${header_file} NAME_WE)
    list(APPEND MOCK_GENERATED_HEADERS "${MOCK_GEN_DIR}/mocks/Mock${file_without_dir}.h")
    list(APPEND MOCK_GENERATED_SRCS "${MOCK_GEN_DIR}/mocks/Mock${file_without_dir}.c")
endforeach()

file(MAKE_DIRECTORY "${MOCK_GEN_DIR}/mocks")

idf_component_register(SRCS "${MOCK_GENERATED_SRCS}"
                    INCLUDE_DIRS ${INCLUDE_DIRS}
                    REQUIRES ${REQUIRES})

# This command builds the mocks.
add_custom_command(
    OUTPUT ${MOCK_GENERATED_SRCS} ${MOCK_GENERATED_HEADERS}
    COMMAND ${CMAKE_COMMAND} -E env "UNITY_DIR=${IDF_PATH}/components/unity/unity"
        ruby
        ${CMOCK_DIR}/lib/cmock.rb
        -o${CMAKE_CURRENT_SOURCE_DIR}/mock/mock_config.yaml
        ${MOCK_HEADER_FILES}
    )
