/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-arcade-alexandre.douard
** File description:
** ASprite.hpp
*/

#pragma once

#include "IObject.hpp"

namespace arcade {
    class ASprite: public ISpriteObject {
        public:
            ASprite(int idTexture, shape_t shape, pos_t pos, shape_t bounds);
            ~ASprite() = default;

            void setIdTexture(int id) override;
            int getIdTexture() const override;

            void setShape(shape_t shape) override;
            shape_t getShape() const override;

            void setType(ObjectType type) override;
            ObjectType getType() const override;

            void isDisplay(bool isDisplay) override;
            bool isDisplay() const override;

            void setPos(pos_t pos) override;
            pos_t getPos() const override;

            void setBounds(shape_t bounds) override;
            shape_t getBounds() const override;

        private:
            int _idTexture;
            shape_t _shape;
            pos_t _pos;
            shape_t _bounds;
            bool _isDisplay;
            ObjectType _type;
    };
}