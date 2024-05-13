cmake_minimum_required(VERSION 3.20)
project(smzy_study C)
set(CMAKE_C_STANDARD 11)
include_directories(.)
add_executable(smzy
        DataStruct/day_3/text.c
        DataStruct/day_3/Slist.c
        DataStruct/day_3/Slist.h
        AlgorithmExercises/反转链表.c
)
#cmake_minimum_required(VERSION 3.20)
