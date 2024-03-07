/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** ErrorHandling
*/

#pragma once

#include <iostream>
#include <exception>


namespace arcade {
    class ErrorH : public std::exception {
        public:
            ErrorH(std::string const &message);
            ~ErrorH() noexcept override;

            const char *what() const noexcept override;
   
        private:
            std::string _message;
    };
}
