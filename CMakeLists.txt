cmake_minimum_required(VERSION 3.20)
project(OpenGL_1 CXX C) # Буква C важна, так как glad.c написан на C

set(CMAKE_CXX_STANDARD 20)

# 1. Настройка и сборка GLFW
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
add_subdirectory(glfw)

# 2. Подключаем папки с заголовочными файлами (.h)
include_directories(
        glfw/include
        libraries/include
)

# 3. Создаем программу, добавляя main.cpp И файл glad.c
add_executable(OpenGL_1
        main.cpp
        libraries/glad.c
)

# 4. Линкуем библиотеку GLFW к проекту
target_link_libraries(OpenGL_1 glfw)
