set(LIB_NAME B)
set(INC_FILES inc/gmds/b/B.h)
set(SRC_FILES src/B.cpp)

add_library(${LIB_NAME})
target_sources(${LIB_NAME} PRIVATE ${SRC_FILES})
#===============================================================================
component_install(${LIB_NAME})