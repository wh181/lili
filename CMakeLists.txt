cmake_minimum_required(VERSION 3.27)
project(lili)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(./src)

add_executable(lili
        main.cpp
        src/grammar_analysis/grammar_analysis.cpp
        src/grammar_analysis/expression/scenes.cpp
        src/grammar_analysis/expression/expression.cpp
        src/lexical_analysis/lexical_analysis.cpp)
