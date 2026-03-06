#include "interpreter.h"
#include <stdexcept>

Interpreter::Interpreter(bool echo) : echo_(echo) {}

void Interpreter::setVariable(const std::string &name, int value) {
    vars_[name] = value;
}

int Interpreter::getVariable(const std::string &name) const {
    auto it = vars_.find(name);
    if (it == vars_.end())
        throw std::runtime_error("Undefined variable: " + name);
    return it->second;
}

bool Interpreter::shouldPrint() const {
    return echo_;
}
