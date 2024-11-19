#pragma once
#include <string>

class PrintStrategy {
public:
    virtual ~PrintStrategy() = default;
    virtual void print(const std::string& message) = 0;
};