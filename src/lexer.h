#pragma once
//#ifndef stdcpp_h
#include <bits/stdc++.h>


using namespace std;

enum class TokenType {
    Number,
    Identifier,
    Slitral,
    Operator,
    LParen,
    RParen,
    LCurly,
    RCurly,
    LSqrly,
    RSqrly,
    Semicolon,
    End,
};

struct Token {
    TokenType type;
    std::string text;
};

class Lexer {
public:
    Lexer(const string &input);
    void Tokenize(vector<Token> &tokens);

private:
    const std::string input_;
    size_t pos_ = 0;
    void skipWhitespace();
    char peek() const;
    char get();
};
