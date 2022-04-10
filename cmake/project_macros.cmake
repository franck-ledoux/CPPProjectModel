#==============================================================================
# The procedure is given for the component of this project with the component
# structure including subdirectories inc/ and src/
#==============================================================================
# COMP_NAME    component name
macro(component_install COMP_NAME)
target_include_directories(${COMP_NAME} PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/inc>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}/${PROJECT_INSTALL_NAME}>)

install(TARGETS ${COMP_NAME}
        EXPORT gmds-config
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR})

install(DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/inc/
        DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/${PROJECT_INSTALL_NAME})
endmacro()
