cmake_minimum_required(VERSION 3.20)
project(test_link)

set(CMAKE_CXX_STANDARD 14)

find_package(toy REQUIRED CONFIG COMPONENTS A B)

add_executable(test_link  main.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE toy::A toy::B)


#enable_testing()
#add_test(
#        NAME link_on_lib
#        COMMMAND $<TARGET_FILE:test_link>
#)