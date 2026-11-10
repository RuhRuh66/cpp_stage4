cmake_minimum_required(VERSION 3.16)
project(step48 LANGUAGES CXX)


add_library(calculator STATIC src/Calculator.cpp)

target_include_directories(calculator INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include)




add_executable(app src/main.cpp)

target_link_libraries(app PRIVATE calculator)