cmake_minimum_required(VERSION 3.27)
project(new_smzy_study C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(smzy
        C_study/day_23/指针进阶6.c
        #        C_study/day_21/指针进阶3.c
)