cmake_minimum_required(VERSION 3.20)
project(Garden VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(garden INTERFACE)
target_include_directories(garden INTERFACE include/)

enable_testing()

foreach(TEST_FILE
    tests/test_vector.cpp
    tests/test_stack.cpp
    tests/test_circular_buffer.cpp
    tests/test_merge_sort.cpp)
    get_filename_component(TEST_NAME ${TEST_FILE} NAME_WE)
    add_executable(${TEST_NAME} ${TEST_FILE})
    target_link_libraries(${TEST_NAME} PRIVATE garden)
    add_test(NAME ${TEST_NAME} COMMAND ${TEST_NAME})
endforeach()
