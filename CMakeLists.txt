cmake_minimum_required(VERSION 3.20)

# 项目名和支持的语言
project(smzy_study C CXX)

# 设置 C 和 C++ 标准
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# 包含头文件目录
include_directories(.)

# 添加可执行文件并指定 C 和 C++ 源文件
add_executable(smzy
        cpp_study/day_1/test.cpp
)
