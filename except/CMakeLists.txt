# CMakeLists.txt

# 指定 CMake 的最低版本要求
cmake_minimum_required(VERSION 3.10)

# 设置项目名称
project(ExceptionHandlingProject)

# 设置头文件路径
include_directories(include)

# 添加测试可执行文件，并包含 src/except.c
add_executable(except_test src_test/except_test.c src/except.c)