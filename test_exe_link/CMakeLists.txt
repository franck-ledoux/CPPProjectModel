cmake_minimum_required(VERSION 3.21)
project(test_exe_link)

set(CMAKE_CXX_STANDARD 14)

find_package(gmds REQUIRED CONFIG COMPONENTS A B)

add_executable(test_exe_link  main.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE gmds::A gmds::B)