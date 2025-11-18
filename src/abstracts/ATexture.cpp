/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-arcade-alexandre.douard
** File description:
** ATexture.cpp
*/

#include "ATexture.hpp"

namespace arcade {
    ATexture::ATexture(int id, std::string texturePath, PtrTextObject text) : _id(id), _texturePath(texturePath), _text(text) {

    }

    void ATexture::setId(int id) {
        _id = id;
    }

    int ATexture::getId() const {
        return _id;
    }

    void ATexture::setTexturePath(std::string texturePath) {
        _texturePath = texturePath;
    }

    std::string ATexture::getTexturePath() const {
        return _texturePath;
    }

    void ATexture::setTextureText(PtrTextObject text) {
        _text.reset(text.get());
    }

    PtrTextObject ATexture::getTextureText() const {
        return _text;
    }
}