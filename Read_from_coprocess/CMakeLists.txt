cmake_minimum_required(VERSION 3.5)

project(Read_from_coprocess LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(${PROJECT_NAME}
    ./src/main.cpp
)

target_compile_options(${PROJECT_NAME} PUBLIC -g -O0 -Wall -Wextra)
