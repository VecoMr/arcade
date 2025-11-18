/*
** EPITECH PROJECT, 2024
** B-OOP-400-LYN-4-1-arcade-alexandre.douard
** File description:
** ABackground
*/

#pragma once

#include "IObject.hpp"

namespace arcade {
    class ABackground : public IBackground {
        public:
            ABackground(color_t color = {0, 0, 0, 255});
            ~ABackground() = default;

            void setType(ObjectType type) override;
            ObjectType getType() const override;

            void isDisplay(bool isDisplay) override;
            bool isDisplay() const override;

            void setPos(pos_t pos) override;
            pos_t getPos() const override;

            void setColor(color_t color) override;
            color_t getColor() const override;

            void setBounds(shape_t bounds) override ;
            shape_t getBounds() const override;

        private:
            ObjectType _type;
            bool _isDisplay;
            pos_t _pos;
            color_t _color;
    };
}