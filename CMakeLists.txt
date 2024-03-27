cmake_minimum_required(VERSION 3.27)
project("Simulator_of_operations" VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)

add_executable(Simulator_of_operations main.cpp include/coordinate.h include/tools.h src/tools.cpp)