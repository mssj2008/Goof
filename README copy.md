# Simple C++ Interpreter

This project implements a basic interpreter in C++ that can evaluate arithmetic expressions and handle variable assignments. It features:

- Tokenizer (lexer)
- Recursive-descent parser
- In-memory variable environment
- REPL interface

## Building

You can build the project with CMake if it is available:

```sh
mkdir build && cd build
cmake ..
cmake --build .
```

If you don't have CMake, a simple manual compile command also works:

```sh
g++ -std=c++17 src/*.cpp -o SimpleInterpreter
```

Ensure your system has a C++17-capable compiler such as `g++` or `clang++`.

## Usage

Run the executable and type expressions or assignments:

```
> x = 5
> y = x * 2 + 3
> y
13
```

Press Ctrl+D (EOF) to exit.
