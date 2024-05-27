cmake_minimum_required(VERSION 3.20)
project(smzy_study C)
set(CMAKE_C_STANDARD 11)
include_directories(.)

#cmake_minimum_required(VERSION 3.20)
add_executable(smzy
        DSStudy/day_9/stack/stack.c
        DSStudy/day_9/stack/stack.h
        DSStudy/day_9/stack/text.c
)
