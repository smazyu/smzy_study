 cmake_minimum_required(VERSION 3.20)
 project(smzy_study C)
 set(CMAKE_C_STANDARD 11)
 include_directories(.)
 add_executable(smzy
         DataStruct/day_2/Seqlist.c
         DataStruct/day_2/Seqlist.h
         DataStruct/day_2/text.c)