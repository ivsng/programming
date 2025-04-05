cmake_minimum_required(VERSION 3.10)
project(RectangleProject)

set(CMAKE_CXX_STANDARD 17)  # Используем C++17

# Указываем директорию с заголовочными файлами
include_directories(${CMAKE_SOURCE_DIR}/include)

# Указываем, что компилировать все cpp файлы
add_executable(program ${CMAKE_SOURCE_DIR}/main.cpp ${CMAKE_SOURCE_DIR}/src/Rectangle.cpp)
