#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/stl_bind.h>
// #include "optional.hpp"
#include "tl/optional.hpp"

namespace py = pybind11;
using rvp = py::return_value_policy;
using namespace pybind11::literals;

namespace pybind11
{
namespace detail
{
template <typename T>
struct type_caster<tl::optional<T>> : optional_caster<tl::optional<T>>
{
};
}
}

struct Pod
{
    tl::optional<std::string> optional;
};

PYBIND11_MODULE(binding, m)
{
    py::class_<Pod>(m, "Pod") // for testing
        .def(py::init<>())
        .def_readwrite("optional", &Pod::optional)
        //
        ;
}