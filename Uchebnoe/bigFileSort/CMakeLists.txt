cmake_minimum_required(VERSION 3.5)

project(bigFileSort LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS "-Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

include_directories(bigFileSort include)

set(SOURCES main.cpp src/generatefile.cpp src/threadpool.cpp src/outmerge.cpp src/sortandsplitfile.cpp)

add_executable(bigFileSort ${SOURCES})
