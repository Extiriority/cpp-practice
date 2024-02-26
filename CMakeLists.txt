cmake_minimum_required(VERSION 3.21)
project(untitled)

set(CMAKE_CXX_STANDARD 20)

add_executable(untitled src/main.cpp
        src/Games/TicTacToe/TicTacToe.cpp
        src/Games/TicTacToe/TicTacToe.h
        src/Utils/Stopwatch.hpp
        src/Advent_of_Code/Day1/Not_Quite_Lisp.cpp
        src/Advent_of_Code/Day1/Not_Quite_Lisp.h
        src/Advent_of_Code/Day2/I_Was_Told_There_Would_Be_No_Math.cpp
        src/Advent_of_Code/Day2/I_Was_Told_There_Would_Be_No_Math.h
        src/Advent_of_Code/Day3/Perfectly_Spherical_Houses_in_a_Vacuum.cpp
        src/Advent_of_Code/Day3/Perfectly_Spherical_Houses_in_a_Vacuum.h
        src/Games/StratagemCade/Stratagem.cpp
        src/Games/StratagemCade/Stratagem.h
)
