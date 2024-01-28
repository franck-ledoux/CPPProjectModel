/*----------------------------------------------------------------------------*/
#include "toy/a/A.h"
/*----------------------------------------------------------------------------*/
#include <pybind11/pybind11.h>
/*----------------------------------------------------------------------------*/
namespace py = pybind11;
/*----------------------------------------------------------------------------*/
void bind_math(py::module &m){
	py::class_<A>(m, "A")
	   .def("f", &A::f);
}