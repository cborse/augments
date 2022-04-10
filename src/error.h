#pragma once

#include <stdexcept>

class Error : public std::runtime_error {
public:
    explicit Error(const std::string& msg) : std::runtime_error(msg) {}

    std::string whats() const { return what(); }
};
