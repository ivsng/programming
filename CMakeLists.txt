cmake_minimum_required(VERSION 3.10)
project(RectangleProject)

set(CMAKE_CXX_STANDARD 17)

# Указываем путь к заголовочным файлам
include_directories(${CMAKE_SOURCE_DIR}/include)

# Указываем исходные файлы проекта
add_executable(program 
    ${CMAKE_SOURCE_DIR}/main.cpp                 # точка входа
    ${CMAKE_SOURCE_DIR}/src/Rectangle.cpp        # реализация базового класса Rectangle
    ${CMAKE_SOURCE_DIR}/src/MovableRectangle.cpp # реализация производного класса MovableRectangle
)