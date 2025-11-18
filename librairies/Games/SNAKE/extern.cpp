/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-arcade-alexandre.douard
** File description:
** extern.cpp
*/

#include "Snake.hpp"

extern "C" arcade::Snake *createLib()
{
    return new arcade::Snake();
}

extern "C" arcade::LibType getType()
{
    return arcade::LibType::GAME;
}

extern "C" std::string getName()
{
    return std::string("SNAKE");
}
