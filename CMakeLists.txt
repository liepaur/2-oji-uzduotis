cmake_minimum_required(VERSION 3.10)
project(CalculatorProject CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory(googletest)

add_library(calculator_lib
    src/calculator.cpp
    src/calculator.h
)

target_include_directories(calculator_lib PUBLIC src)

add_executable(run_tests tests/calculator_test.cpp)

target_link_libraries(run_tests
    calculator_lib       
    gtest_main           
)

include(CTest)
add_test(NAME AllTests COMMAND run_tests)