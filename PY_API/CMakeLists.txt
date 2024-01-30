cmake_minimum_required(VERSION 3.10)
project(pyapi)
#==============================================================================
find_package(pybind11 REQUIRED)
pybind11_add_module(pyapi src/binding_A.cpp src/binding_B.cpp src/pyapi.cpp)

target_link_libraries(pyapi PRIVATE A B)

target_compile_definitions(pyapi PUBLIC cxx_std_14)
#==============================================================================
install(TARGETS pyapi
        COMPONENT python
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        )
#==============================================================================
if(ENABLE_TEST)
    add_subdirectory(tst)
endif(ENABLE_TEST)
#==============================================================================
