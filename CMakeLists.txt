cmake_minimum_required(VERSION 3.3)
project(AcmAlgorithms)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Math/HighPrecisionInteger.h)
add_executable(AcmAlgorithms ${SOURCE_FILES})