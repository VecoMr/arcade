/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** Texture
*/

#pragma once

#include <iostream>
#include <vector>
#include <memory>

namespace arcade {
    using VPtrTexture = std::vector<std::shared_ptr<Texture>>;

    class Texture {
        public:
            Texture() = default;
            Texture(int id, std::string texturePath);
            ~Texture() = default;

            void setId(int id);
            int getId() const;

            void setTexturePath(std::string texturePath);
            std::string getTexturePath() const;

        private:
            int _id;
            std::string _texturePath;
    };
}