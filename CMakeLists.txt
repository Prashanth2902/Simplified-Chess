cmake_minimum_required(VERSION 3.10)
project(SimplifiedChess CXX)
set(CMAKE_CXX_STANDARD 17)

add_executable(SimplifiedChess src/main.cpp src/Board.cpp)
target_include_directories(SimplifiedChess PRIVATE include)