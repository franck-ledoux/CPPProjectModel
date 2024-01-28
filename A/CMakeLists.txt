#===============================================================================
set(LIB_NAME A)
set(INC_FILES inc/toy/a/A.h)
set(SRC_FILES src/A.cpp)
#===============================================================================
add_library(${LIB_NAME})
target_sources(${LIB_NAME} PRIVATE ${SRC_FILES})
#===============================================================================
if(ENABLE_TEST)
    add_subdirectory(tst)
endif()

#===============================================================================
prj_component_install(${LIB_NAME})
