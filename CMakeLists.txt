cmake_minimum_required(VERSION 3.18...3.25)
project(se_for_sci_hw6 LANGUAGES CXX)

include(FetchContent)

FetchContent_Declare(
  eigen
  URL https://gitlab.com/libeigen/eigen/-/archive/3.4.0/eigen-3.4.0.tar.bz2
  URL_HASH
    SHA256=b4c198460eba6f28d34894e3a5710998818515104d6e74e5cc331ce31e46e626
  SOURCE_SUBDIR ignore_cmakelists)
FetchContent_MakeAvailable(eigen)

if(DEFINED SKBUILD)
  # Using pybind11 to create a Python binding for our C++ code.
find_package(pybind11 CONFIG REQUIRED)
# Adding a module named '_core', which is our Python extension, built from the specified source files.
pybind11_add_module(_core MODULE src/_core.cpp src/integrator.hpp)
# Setting the include directories for our module. It includes our source directory and the Eigen library directory.
target_include_directories(_core PRIVATE src "${eigen_SOURCE_DIR}")
# Specifying the C++ standard to be used for our module. We use C++11 here.
target_compile_features(_core PRIVATE cxx_std_11)
else()
  add_executable(main src/main.cpp src/integrator.hpp)
  target_include_directories(main PRIVATE src "${eigen_SOURCE_DIR}")
  target_compile_features(main PRIVATE cxx_std_11)
endif()
