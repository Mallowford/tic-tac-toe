cmake_minimum_required(VERSION 3.20)
project(tic_tac_toe)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y")

add_executable(TicTacToe 
    ../src/Game.cpp
    ../src/main.cpp
)