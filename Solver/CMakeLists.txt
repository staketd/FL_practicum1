cmake_minimum_required(VERSION 3.12)

project(Solver)

set(SOURCE_LIB solver.cpp)

add_library(Solver STATIC ${SOURCE_LIB})