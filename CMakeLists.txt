cmake_minimum_required(VERSION 3.14)
project(StudentuSistema)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_library(core
    src/studentas.cpp
    src/funkcijos.cpp
)


add_executable(app
    src/main.cpp
)

target_link_libraries(app core)

enable_testing()
find_package(GTest REQUIRED)

add_executable(runTests
    tests/test_studentas.cpp
)

target_link_libraries(runTests core GTest::gtest GTest::gtest_main)
add_test(NAME StudentTests COMMAND runTests)
