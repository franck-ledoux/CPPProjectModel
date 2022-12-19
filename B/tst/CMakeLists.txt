add_executable(B_TEST
        BTestSuite.h
        main_test.cpp)

target_link_libraries(B_TEST PUBLIC B gtest)

target_include_directories(B_TEST PRIVATE .)

set_target_properties(B_TEST PROPERTIES
        CXX_STANDARD 14
        CXX_STANDARD_REQUIRED YES)
#==============================================================================
include(GoogleTest)
gtest_discover_tests(B_TEST WORKING_DIRECTORY ${CMAKE_BINARY_DIR})
#==============================================================================
