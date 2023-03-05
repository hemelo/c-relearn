cmake_minimum_required(VERSION 3.24)
project(untitled C)

set(CMAKE_C_STANDARD 23)

add_executable(untitled main.c structures/dyn_array.c structures/dyn_array.h utils/math.c utils/math.h)
