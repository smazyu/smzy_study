cmake_minimum_required(VERSION 3.27)
project(new_smzy_study C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(smzy
        C_study/day_24/指针进阶7.c
        C_study/day_25/指针进阶8.c
        算法练习/基于栈的算术表达式求值.c
        #        C_study/day_21/指针进阶3.c
)