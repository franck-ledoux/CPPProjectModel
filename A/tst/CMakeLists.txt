add_executable(A_TEST
        ATestSuite.h
        main_test.cpp)

target_link_libraries(A_TEST PUBLIC A gtest)

target_include_directories(A_TEST PRIVATE .)

set_target_properties(A_TEST PROPERTIES
        CXX_STANDARD 14
        CXX_STANDARD_REQUIRED YES)
#==============================================================================
include(GoogleTest)
gtest_discover_tests(A_TEST WORKING_DIRECTORY ${CMAKE_BINARY_DIR})
#==============================================================================
