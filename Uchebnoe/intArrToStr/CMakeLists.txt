cmake_minimum_required(VERSION 3.5)

project(intArrToStr LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(intArrToStr main.cpp)

install(TARGETS intArrToStr
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
