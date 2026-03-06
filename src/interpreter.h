#pragma once
#include <string>
#include <map>

class Interpreter {
public:
    Interpreter(bool echo = true);
    void setVariable(const std::string &name, int value);
    int getVariable(const std::string &name) const;
    bool shouldPrint() const;

private:
    std::map<std::string, int> vars_;
    bool echo_;
};
