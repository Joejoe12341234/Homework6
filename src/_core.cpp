#include <pybind11/eigen.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include "integrator.hpp"

namespace py = pybind11;

PYBIND11_MODULE(_core, m) {
  // Defining a pybind11 class for HarmonicOscillator that inherits from IntegratorBase.
py::class_<HarmonicOscillator, IntegratorBase>(m, "HarmonicOscillator")
    // Exposing the default constructor of the HarmonicOscillator class.
    .def(py::init<>())
    // Exposing the 'integrate' method to Python. This allows calling it from Python code.
    // py::arg is used to specify the names of the arguments for more clarity in Python.
    .def("integrate", &HarmonicOscillator::integrate, 
         py::arg("stepsize"), py::arg("steps"), py::arg("init_y"));
}
