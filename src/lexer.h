#pragma once
#include <string>
#include <vector>

enum class TokenType {
    End,
    Number,
    Identifier,
    Plus,
    Minus,
    Mul,
    Div,
    Assign,
    LParen,
    RParen,
    Semicolon,
};

struct Token {
    TokenType type;
    std::string text;
};

class Lexer {
public:
    explicit Lexer(const std::string &input);
    Token nextToken();
    Token peekToken(); // look ahead without consuming

private:
    const std::string input_;
    size_t pos_ = 0;
    void skipWhitespace();
    char peek() const;
    char get();
};
