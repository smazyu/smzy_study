cmake_minimum_required(VERSION 3.27)
project(new_smzy_study C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(smzy
        C_study/day_35/new_contact.h
        C_study/day_35/new_text.c
        C_study/day_35/new_contact.c
)