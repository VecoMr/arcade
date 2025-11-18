/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-arcade-alexandre.douard
** File description:
** ASprite.cpp
*/

#include "ASprite.hpp"

namespace arcade {
    ASprite::ASprite(int idTexture, shape_t shape, pos_t pos, shape_t bounds) :
            _idTexture(idTexture), _shape(shape), _pos(pos), _bounds(bounds) {
        _isDisplay = true;
        _type = ObjectType::SPRITE;
    }

    void ASprite::setIdTexture(int idTexture) {
        _idTexture = idTexture;
    }

    int ASprite::getIdTexture() const {
        return _idTexture;
    }

    void ASprite::setShape(shape_t shape) {
        _shape = shape;
    }

    shape_t ASprite::getShape() const {
        return _shape;
    }

    void ASprite::setType(ObjectType type) {
        _type = type;
    }

    ObjectType ASprite::getType() const {
        return _type;
    }

    void ASprite::isDisplay(bool isDisplay) {
        _isDisplay = isDisplay;
    }

    bool ASprite::isDisplay() const {
        return _isDisplay;
    }

    void ASprite::setPos(pos_t pos) {
        _pos = pos;
    }

    pos_t ASprite::getPos() const {
        return _pos;
    }

    void ASprite::setBounds(shape_t bounds) {
        _bounds = bounds;
    }

    shape_t ASprite::getBounds() const {
        return _bounds;
    }
}
