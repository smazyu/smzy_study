cmake_minimum_required(VERSION 3.20)
project(smzy_study C)
set(CMAKE_C_STANDARD 11)
include_directories(.)

#cmake_minimum_required(VERSION 3.20)
add_executable(smzy
        DSStudy/day_23/quciksort_nonr.c
        DSStudy/day_23/stack.c
        DSStudy/day_23/stack.h
        DSStudy/day_24_end/countsort.c
)
