cmake_minimum_required(VERSION 3.15) # проверка версии CMake. Если версия указанной программы старее указанной, произойдёт аварийный выход.

set(PROJECT_NAME example) # задать значение PROJECT_EXAMPLE
project("${PROJECT_NAME}") # установить имя проекта

set(CMAKE_CXX_STANDART 17) # устанавливаем 17 стандарт языка
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDART_REQUIRED TRUE)

# сказать программе, что должен быть исполняемый файл
add_executable("${PROJECT_NAME}" main.cpp)
