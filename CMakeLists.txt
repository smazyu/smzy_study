cmake_minimum_required(VERSION 3.20)
project(smzy_study C)
set(CMAKE_C_STANDARD 11)
include_directories(.)

#cmake_minimum_required(VERSION 3.20)
add_executable(smzy
        DSStudy/day_14/heap.c
        DSStudy/day_14/heap.h
        DSStudy/day_14/test.c
)
