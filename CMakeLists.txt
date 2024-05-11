cmake_minimum_required(VERSION 3.20)
project(smzy_study C)
set(CMAKE_C_STANDARD 11)
include_directories(.)
add_executable(smzy
        AlgorithmExercises/RemoveElement.c
        DataStruct/day_3/text.c
        AlgorithmExercises/RemoveDuplicatsInOrderedArray.c
        AlgorithmExercises/MergeTwoSortedArrays.c
        DataStruct/day_3/LinkedList.c
        DataStruct/day_3/Slist.c
        DataStruct/day_3/Slist.h
)
#cmake_minimum_required(VERSION 3.20)
