cmake_minimum_required(VERSION 3.5)

project(sfinae LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(sfinae main.cpp)

install(TARGETS sfinae
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
