cmake_minimum_required(VERSION 3.6)

project(step39Tests LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED on)

add_executable(add_test test_add.cpp)

enable_testing()

add_test(NAME AdditionTest COMMAND add_test)

include(FetchContent)

FetchContent_Declare(googletest URL https://github.com/google/googletest/archive/refs/tags/v1.17.0.tar.gz)

FetchContent_MakeAvailable(googletest)

add_executable(google_test google_test.cpp)

target_link_libraries(google_test PRIVATE GTest::gtest_main)

add_test(NAME GoogleTestCheck COMMAND google_test)