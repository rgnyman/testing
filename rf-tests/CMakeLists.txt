cmake_minimum_required(VERSION 3.20)
project(movie_interface)

find_package(pybind11 REQUIRED)

set(CMAKE_CXX_STANDARD 17)

set(PYBIND_HEADERS $ENV{HOME}/Library/Python/3.8/lib/python/site-packages/pybind11/include/)
set(PYTHON_HEADERS /opt/local/Library/Frameworks/Python.framework/Versions/3.8/include/python3.8/)

include_directories(${PYBIND_HEADERS})
include_directories(${PYTHON_HEADERS})

pybind11_add_module(movie_interface movie-interface.cpp)

set_target_properties(movie_interface PROPERTIES SUFFIX ".so")

target_link_libraries(movie_interface PRIVATE movie_lib)
