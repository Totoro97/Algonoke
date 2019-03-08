cmake_minimum_required(VERSION 3.0.0)
project(Algonoke)
set(CMAKE_BUILD_TYPE Debug)
set(SOURCE_FILES Algonoke/Algonoke.cpp Algonoke/Algonoke.h)
add_library(Algonoke ${SOURCE_FILES})
add_executable(TestAll ${SOURCE_FILES} Algonoke/TestAll.cpp)

