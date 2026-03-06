cmake_minimum_required(VERSION 3.10)
project(SimpleInterpreter)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(src)

add_executable(SimpleInterpreter
    src/main.cpp
    src/lexer.cpp
    src/parser.cpp
    src/interpreter.cpp
)
