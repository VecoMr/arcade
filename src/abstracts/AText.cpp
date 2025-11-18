/*
** EPITECH PROJECT, 2024
** B-OOP-400-LYN-4-1-arcade-alexandre.douard
** File description:
** AText
*/

#include "AText.hpp"

namespace arcade {
    AText::AText(int fontId, std::string text, pos_t pos, int size, color_t color)
    : _fontId(fontId), _text(text), _pos(pos), _size(size), _color(color), _isDisplay(true), _type(ObjectType::TEXT), _bounds({0, 0, 0, 0}), _backGroundColor({0, 0, 0, 0})
    {
    }

    AText::AText(int fontId, char *text, pos_t pos, int size, color_t color)
    : _fontId(fontId), _text(text), _pos(pos), _size(size), _color(color), _isDisplay(true), _type(ObjectType::TEXT), _bounds({0, 0, 0, 0}), _backGroundColor({0, 0, 0, 0})
    {
    }

    AText::AText(int fontId, std::string text, pos_t pos, int size, color_t color, color_t backGroundColor)
    : _fontId(fontId), _text(text), _pos(pos), _size(size), _color(color), _isDisplay(true), _type(ObjectType::TEXT), _bounds({0, 0, 0, 0}), _backGroundColor(backGroundColor)
    {
    }

    void AText::setType(const ObjectType type)
    {
        _type = type;
    }

    ObjectType AText::getType() const
    {
        return _type;
    }

    void AText::isDisplay(bool isDisplay)
    {
        _isDisplay = isDisplay;
    }

    bool AText::isDisplay() const
    {
        return _isDisplay;
    }

    void AText::setPos(const pos_t pos)
    {
        _pos = pos;
    }

    pos_t AText::getPos() const
    {
        return _pos;
    }


    void AText::setContent(const std::string text)
    {
        _text = text;
    }

    std::string AText::getContent() const
    {
        return _text;
    }

    void AText::setIdFontFamily(const int id)
    {
        _fontId = id;
    }

    int &AText::getIdFontFamily()
    {
        return _fontId;
    }

    void AText::setSize(const int size)
    {
        _size = size;
    }

    int AText::getSize() const
    {
        return _size;
    }

    void AText::setColor(const color_t color)
    {
        _color = color;
    }

    color_t AText::getColor() const
    {
        return _color;
    }

    void AText::setBounds(const shape_t bounds)
    {
        _bounds = bounds;
    }

    shape_t AText::getBounds() const
    {
        return _bounds;
    }

    void AText::setBackGroundColor(const color_t color)
    {
        _backGroundColor = color;
    }

    color_t AText::getBackGroundColor() const
    {
        return _backGroundColor;
    }

    bool AText::isIn(const pos_t pos) const
    {
        if (pos.x >= _pos.x && pos.x <= _pos.x + _bounds.width && pos.y >= _pos.y && pos.y <= _pos.y + _bounds.height)
            return true;
        return false;
    }
}