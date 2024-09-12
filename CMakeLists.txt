cmake_minimum_required(VERSION 3.20)

# Set the project name and specify the languages
project(smzy_study LANGUAGES C CXX)

# Set C and C++ standards
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# Optionally enforce standards (disable compiler extensions)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)
set(CMAKE_CXX_EXTENSIONS OFF)

# Include directories for header files
include_directories(${PROJECT_SOURCE_DIR}/include)

# Collect all source files automatically
file(GLOB_RECURSE SOURCES
        ${PROJECT_SOURCE_DIR}/cpp_study/day_14/*.cpp
)

# Add the executable target and link the source files
add_executable(smzy ${SOURCES})
