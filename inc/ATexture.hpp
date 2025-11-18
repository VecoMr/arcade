/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-arcade-alexandre.douard
** File description:
** ATexture.hpp
*/

#pragma once

#include "IObject.hpp"

namespace arcade {
    class ATexture : public ITexture {
        public:
            ATexture(int id, std::string texturePath, PtrTextObject text);
            ~ATexture() = default;

            void setId(int id) override;
            int getId() const override;

            void setTexturePath(std::string texturePath) override;
            std::string getTexturePath() const override;

            void setTextureText(PtrTextObject text) override;
            PtrTextObject getTextureText() const override;

        private:
            int _id;
            std::string _texturePath;
            PtrTextObject _text;
    };
}