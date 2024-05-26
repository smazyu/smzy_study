cmake_minimum_required(VERSION 3.20)
project(smzy_study C)
set(CMAKE_C_STANDARD 11)
include_directories(.)

#cmake_minimum_required(VERSION 3.20)
add_executable(smzy
        DataStructStudy/day_8/List.c
        DataStructStudy/day_8/List.h
        DataStructStudy/day_8/text.c
)
