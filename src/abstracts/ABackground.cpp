/*
** EPITECH PROJECT, 2024
** B-OOP-400-LYN-4-1-arcade-alexandre.douard
** File description:
** ABackground
*/

#include "ABackground.hpp"

namespace arcade {
    ABackground::ABackground(color_t color)
    : _type(ObjectType::BACKGROUND), _isDisplay(true), _pos({0, 0}), _color(color)
    {
    }

    void ABackground::setType(ObjectType type)
    {
        _type = type;
    }

    ObjectType ABackground::getType() const
    {
        return _type;
    }

    void ABackground::isDisplay(bool isDisplay)
    {
        _isDisplay = isDisplay;
    }

    bool ABackground::isDisplay() const
    {
        return _isDisplay;
    }

    void ABackground::setPos(pos_t pos)
    {
        _pos = pos;
    }

    pos_t ABackground::getPos() const
    {
        return _pos;
    }

    void ABackground::setColor(color_t color)
    {
        _color = color;
    }

    color_t ABackground::getColor() const
    {
        return _color;
    }

    void ABackground::setBounds(shape_t)
    {
        return;
    }

    shape_t ABackground::getBounds() const
    {
        return {0, 0, 0, 0};
    }
}