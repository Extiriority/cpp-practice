cmake_minimum_required(VERSION 3.21)
project(untitled)

set(CMAKE_CXX_STANDARD 20)

add_executable(untitled src/main.cpp
        src/Games/TicTacToe.cpp
        src/Games/TicTacToe.h
        src/Utils/Stopwatch.hpp
        src/Advent_of_Code/Day1/Not_Quite_Lisp.cpp
        src/Advent_of_Code/Day1/Not_Quite_Lisp.h
)
