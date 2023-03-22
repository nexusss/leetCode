cmake_minimum_required(VERSION 3.5)

project(test LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(test main.cpp)

install(TARGETS test
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
