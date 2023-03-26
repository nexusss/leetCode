cmake_minimum_required(VERSION 3.5)

project(enable_if LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(enable_if main.cpp)

install(TARGETS enable_if
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
