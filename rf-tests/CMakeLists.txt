cmake_minimum_required(VERSION 3.20)
project(movie_interface)

find_package(Python 3.9 COMPONENTS Interpreter Development REQUIRED)
find_package(pybind11 REQUIRED)

set(CMAKE_CXX_STANDARD 17)

pybind11_add_module(movie_interface movie-interface.cpp)

set_target_properties(movie_interface PROPERTIES SUFFIX ".so")

target_link_libraries(movie_interface PRIVATE movie_lib)
