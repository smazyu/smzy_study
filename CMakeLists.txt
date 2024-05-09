cmake_minimum_required(VERSION 3.27)
project(new_smzy_study C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(smzy
        算法练习/消失的数字.c
        数据结构/day_2/text.c
        数据结构/day_2/Seqlist.c
        数据结构/day_2/Seqlist.h)