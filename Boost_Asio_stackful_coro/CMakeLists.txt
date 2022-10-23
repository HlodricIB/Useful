cmake_minimum_required(VERSION 3.5)

project(Stackful_coro LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Boost)
if(Boost_FOUND)
    include_directories(//usr/include/boost)
    add_executable(${PROJECT_NAME}
        ./src/main.cpp
        ./src/stackful_coro.cpp
        ./include/stackful_coro.h
)
endif()

target_compile_options(${PROJECT_NAME} PUBLIC -g -O0 -Wall -Wextra)
target_link_options(${PROJECT_NAME} PUBLIC -dynamic)

target_include_directories(${PROJECT_NAME} PUBLIC ./include)

target_link_libraries(${PROJECT_NAME} PRIVATE /usr/lib/x86_64-linux-gnu/libboost_coroutine.so.1.74.0)
