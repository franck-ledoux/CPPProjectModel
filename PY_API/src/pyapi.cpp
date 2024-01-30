/*----------------------------------------------------------------------------*/
#include <pybind11/pybind11.h>
/*----------------------------------------------------------------------------*/
namespace py = pybind11;
/*----------------------------------------------------------------------------*/
void bind_A(py::module &);
void bind_B(py::module &);
/*----------------------------------------------------------------------------*/
// pyapi is the module name
PYBIND11_MODULE(pyapi, m)
{
// current version
m.attr("__version__") = "dev";
// module description
m.doc() = "example of python binding";
auto sub_A = m.def_submodule("A", "module A");
bind_A(sub_A);
auto sub_B = m.def_submodule("B", "module B");
bind_B(sub_B);
}
