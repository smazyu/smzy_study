cmake_minimum_required(VERSION 3.27)
project(new_smzy_study C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(smzy
        C_study/day_28/字符串函数及模拟实现3.c
        C_study/day_29/内存函数.c
)