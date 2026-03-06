#include "lexer.h"
#include <cctype>

Lexer::Lexer(const std::string &input) : input_(input) {}

char Lexer::peek() const {
    if (pos_ >= input_.size())
        return '\0';
    return input_[pos_];
}

char Lexer::get() {
    if (pos_ >= input_.size())
        return '\0';
    return input_[pos_++];
}

void Lexer::skipWhitespace() {
    while (std::isspace(peek()))
        get();
}

Token Lexer::nextToken() {
    skipWhitespace();
    char c = peek();
    if (c == '\0') {
        return {TokenType::End, ""};
    }
    if (std::isalpha(c)) {
        std::string id;
        while (std::isalnum(peek()))
            id.push_back(get());
        return {TokenType::Identifier, id};
    }
    if (std::isdigit(c)) {
        std::string num;
        while (std::isdigit(peek()))
            num.push_back(get());
        return {TokenType::Number, num};
    }
    switch (get()) {
    case '+': return {TokenType::Plus, "+"};
    case '-': return {TokenType::Minus, "-"};
    case '*': return {TokenType::Mul, "*"};
    case '/': return {TokenType::Div, "/"};
    case '=': return {TokenType::Assign, "="};
    case '(': return {TokenType::LParen, "("};
    case ')': return {TokenType::RParen, ")"};
    case ';': return {TokenType::Semicolon, ";"};
    default:
        // skip unknown, return End to avoid infinite loop
        return {TokenType::End, ""};
    }
}

Token Lexer::peekToken() {
    size_t saved = pos_;
    Token t = nextToken();
    pos_ = saved;
    return t;
}
