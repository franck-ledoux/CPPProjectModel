cmake_minimum_required(VERSION 3.10)
#==============================================================================
add_subdirectory(pybind11)
#find_package(pybind11 REQUIRED)

pybind11_add_module(pyapi
        src/binding_A.cpp
        )

target_link_libraries(pyapi PUBLIC A)
target_compile_definitions(pyapi PUBLIC cxx_std_14)

install(TARGETS pyapi
        COMPONENT python
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        )
#==============================================================================
if(ENABLE_TEST)
    add_subdirectory(tst)
endif(ENABLE_TEST)