cmake_minimum_required(VERSION 2.8)

#project name
PROJECT(ReinforcementLearning)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

aux_source_directory(src SRC)
include_directories(include)

add_executable(ReinforcementLearning ${SRC})
