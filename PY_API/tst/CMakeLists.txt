#==============================================================================
message("ENVIRONMENT ENVPYTHONPATH $ENV{PYTHONPATH}")

add_test(NAME test_pyapi
        COMMAND pytest ${CMAKE_CURRENT_SOURCE_DIR}  -v
 )
set_tests_properties(test_pyapi
        PROPERTIES ENVIRONMENT "PYTHONPATH=${CMAKE_BINARY_DIR}/PY_API:$ENV{PYTHONPATH}")
#==============================================================================
