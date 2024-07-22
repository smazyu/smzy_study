cmake_minimum_required(VERSION 3.20)
project(smzy_study C)
set(CMAKE_C_STANDARD 11)
include_directories(.)

#cmake_minimum_required(VERSION 3.20)
add_executable(smzy
        DSStudy/day_18/BalancedBinaryTree.c
        DSStudy/day_19/question1.c
        DSStudy/day_19/question2.c
)
