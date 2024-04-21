cmake_minimum_required(VERSION 3.27)
project(new_smzy_study C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(smzy
        C_study/day_30/内存函数3.c
        C_study/day_31/自定义类型1.c
)