#===============================================================================
cmake_minimum_required(VERSION 3.20)
#===============================================================================
project(toy VERSION 1.0.0 LANGUAGES CXX)
#===============================================================================
# Standard options
set(CMAKE_CXX_STANDARD 14)
#===============================================================================
# LIBRARIES ARE INSTALLED USING THE VERSION NUMBER OF OUR PROJECT
set(PROJECT_INSTALL_NAME ${PROJECT_NAME}-${PROJECT_VERSION})
#===============================================================================
# Project options
option(WITH_A "component A is activated" ON)
option(WITH_B "component B is activated" ON)
option(ENABLE_TEST "enable unit testing" ON)
option(ENABLE_COV "enable code coverage" ON)
option(ENABLE_PYTHON "enable python wrapper" ON)
#===============================================================================
# specific macros are given in this file
set(CMAKE_MODULE_PATH "${CMAKE_MODULE_PATH};${PROJECT_SOURCE_DIR}/cmake")
include(GNUInstallDirs)
include(project_macros)
set(INSTALL_GTEST OFF)
#===============================================================================
# Coverage require to run testing codes
if(ENABLE_COV)
    set(ENABLE_TEST ON)
endif()
#===============================================================================
if(ENABLE_TEST)
    include(FetchContent)
    set(FETCHCONTENT_UPDATES_DISCONNECTED ON CACHE BOOL "")
    FetchContent_Declare(
            googletest
            URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
    )

    # For Windows: Prevent overriding the parent project's compiler/linker settings
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
    FetchContent_MakeAvailable(googletest)
    include(GoogleTest)
    enable_testing()
endif()
#===============================================================================
if(ENABLE_COV)
    prj_activate_coverage()
endif()
#===============================================================================
prj_add_subdirectory_if(A WITH_A)
prj_add_subdirectory_if(B WITH_B)

#===============================================================================
# Python wrapping
if(ENABLE_PYTHON)
    add_subdirectory(PY_API)
endif()
#===============================================================================
# INSTALLATION PROCEDURE
#===============================================================================
# DESTINATION directory is the project name + version number
set(DESTINATION_DIR ${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_INSTALL_NAME})

# Do not modify below!
install(EXPORT ${PROJECT_NAME}-config
        NAMESPACE ${PROJECT_NAME}::
        DESTINATION ${DESTINATION_DIR})

configure_file(${PROJECT_NAME}-config.cmake.in
        ${PROJECT_NAME}-config.cmake
        @ONLY)
#===============================================================================
