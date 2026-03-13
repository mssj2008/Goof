#include "lexer.h"
#include <cctype>

Lexer::Lexer(const string &input) : input_(input) {}

char Lexer::peek() const
{
    if (pos_ >= input_.size())
        return '\0';
    return input_[pos_];
}

char Lexer::get()
{
    if (pos_ >= input_.size())
        return '\0';
    return input_[pos_++];
}

void Lexer::skipWhitespace()
{
    while (peek() == ' ' || peek() == '\n')
        get();
}

void Lexer::Tokenize(vector<Token> &tokens)
{
    while (true)
    {
        skipWhitespace();
        char c = peek();
        if(c == '\0')
            break;
        if (std::isalpha(c))
        {
            std::string id;
            while (std::isalnum(peek()))
                id.push_back(get());
            tokens.push_back({TokenType::Identifier, id});
        }
        else if (std::isdigit(c))
        {
            std::string num;
            while (std::isdigit(peek()))
                num.push_back(get());
            tokens.push_back({TokenType::Number, num});
        }
        else if(c == '"')
        {
            get(); // consume the opening quote
            std::string str;
            while (peek() != '"')
                str.push_back(get());
            get(); // consume the closing quote
            tokens.push_back({TokenType::Slitral, str});
        }
        else
        {
        c = get();
        switch (c)
        {
        case '(':
            tokens.push_back({TokenType::LParen, "("}); break;
        case ')':
            tokens.push_back({TokenType::RParen, ")"}); break;
        case '{':
            tokens.push_back({TokenType::LCurly, "{"}); break;
        case '}':
            tokens.push_back({TokenType::RCurly, "}"}); break;
        case '[':
            tokens.push_back({TokenType::LSqrly, "["}); break;
        case ']':
            tokens.push_back({TokenType::RSqrly, "]"}); break;
        case ';':
            tokens.push_back({TokenType::Semicolon, ";"}); break;
        case '\0':
            // skip unknown, return End to avoid infinite loop
            tokens.push_back({TokenType::End, ""}); break;
        default:
            tokens.push_back({TokenType::Operator, string(1, c)}); break;
        }
        //get(); // consume the operator or unknown character
        }
    }
}
