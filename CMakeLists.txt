cmake_minimum_required(VERSION 3.20)
project(smzy_study C)
set(CMAKE_C_STANDARD 11)
include_directories(.)
add_executable(smzy
        AlgorithmExercises/RemoveElement.c
        DataStruct/day_3/text.c
        AlgorithmExercises/RemoveDuplicatsInOrderedArray.c
)
#cmake_minimum_required(VERSION 3.20)
