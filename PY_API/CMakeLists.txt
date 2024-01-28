cmake_minimum_required(VERSION 3.10)
#==============================================================================
find_package(pybind11 REQUIRED)

pybind11_add_module(PY_API
        src/binding_A.cpp
        )

target_link_libraries(PY_API PRIVATE A)
target_compile_definitions(PY_API PUBLIC cxx_std_14)

install(TARGETS PY_API
        COMPONENT python
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        )
#==============================================================================
if(ENABLE_TEST)
    add_subdirectory(tst)
endif(ENABLE_TEST)