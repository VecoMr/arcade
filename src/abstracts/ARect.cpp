/*
** EPITECH PROJECT, 2024
** B-OOP-400-LYN-4-1-arcade-alexandre.douard
** File description:
** ARect
*/

#include "ARect.hpp"

namespace arcade {
    ARect::ARect(shape_t bounds, color_t color, pos_t pos)
    : _type(ObjectType::RECT), _isDisplay(true), _pos(pos), _color(color), _bounds(bounds)
    {
    }

    void ARect::setType(ObjectType type)
    {
        _type = type;
    }

    ObjectType ARect::getType() const
    {
        return _type;
    }

    void ARect::isDisplay(bool isDisplay)
    {
        _isDisplay = isDisplay;
    }

    bool ARect::isDisplay() const
    {
        return _isDisplay;
    }

    void ARect::setPos(pos_t pos)
    {
        _pos = pos;
    }

    pos_t ARect::getPos() const
    {
        return _pos;
    }

    void ARect::setColor(color_t color)
    {
        _color = color;
    }

    color_t ARect::getColor() const
    {
        return _color;
    }

    void ARect::setBounds(shape_t bounds)
    {
        _bounds = bounds;
    }

    shape_t ARect::getBounds() const
    {
        return _bounds;
    }

    void ARect::setShape(shape_t bounds)
    {
        _bounds = bounds;
    }

    shape_t ARect::getShape() const
    {
        return _bounds;
    }
}
