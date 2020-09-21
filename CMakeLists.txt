cmake_minimum_required(VERSION 3.5)
project(optional_test)

include_directories(
    optional/include
    Optional
)

set(CMAKE_CXX_STANDARD 14)
set(PYBIND11_CPP_STANDARD -std=c++14)
add_subdirectory(pybind11)
pybind11_add_module(binding test.cpp)
set_target_properties(binding PROPERTIES POSITION_INDEPENDENT_CODE TRUE)
add_custom_target(test_binding COMMAND python3 ${PROJECT_SOURCE_DIR}/test.py)
