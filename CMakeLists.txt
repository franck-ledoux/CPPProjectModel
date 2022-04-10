#===============================================================================
cmake_minimum_required(VERSION 3.21)

#===============================================================================
project(gmds VERSION 1.0.0 LANGUAGES CXX)
#===============================================================================
# Standard options
include(GNUInstallDirs)
set(CMAKE_CXX_STANDARD 14)
#===============================================================================
set(PROJECT_INSTALL_NAME ${PROJECT_NAME})
#===============================================================================
# Project options
option(WITH_A "component A is activated" ON)
option(WITH_B "component B is activated" ON)
#===============================================================================
# specific macros are given here


include(cmake/project_macros.cmake)
if(WITH_A)
    add_subdirectory(A)
endif()
if(WITH_B)
    add_subdirectory(B)
endif()

#===============================================================================
# INSTALLATION PROCEDURE
#===============================================================================
# DESTINATION directory is the project name + version number
set(DESTINATION_DIR ${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_INSTALL_NAME})

# Do not modify below!
install(
        EXPORT ${PROJECT_NAME}-config
        NAMESPACE ${PROJECT_NAME}::
        DESTINATION ${DESTINATION_DIR})

configure_file(${PROJECT_NAME}-config.cmake.in
        ${PROJECT_NAME}-config.cmake
        @ONLY)

install(FILES "${CMAKE_BINARY_DIR}/${PROJECT_NAME}-config.cmake"
        DESTINATION ${DESTINATION_DIR})

