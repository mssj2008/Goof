#pragma once
#include "lexer.h"
#include <string>
#include <map>

// forward declaration
class Interpreter;

class Parser {
public:
    Parser(Lexer &lexer, Interpreter &interp);
    void parse(); // parse entire input (multiple statements)

private:
    Lexer &lexer_;
    Interpreter &interp_;
    Token curToken_;

    void advance();
    void expect(TokenType type);

    int statement();
    int expression();
    int term();
    int factor();
};
