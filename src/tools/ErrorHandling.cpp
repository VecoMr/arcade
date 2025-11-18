/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** ErrorHandling
*/

#include "ErrorHandling.hpp"

namespace arcade {
    ErrorH::ErrorH(std::string const &message) : _message(message) {}

    ErrorH::~ErrorH() noexcept {}

    const char *ErrorH::what() const noexcept {
        return _message.c_str();
    }
}
