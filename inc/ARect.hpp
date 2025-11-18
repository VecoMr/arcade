/*
** EPITECH PROJECT, 2024
** B-OOP-400-LYN-4-1-arcade-alexandre.douard
** File description:
** ARect
*/

#pragma once

#include "IObject.hpp"

namespace arcade {
    class ARect : public IRect {
        public:
            ARect(shape_t bounds, color_t color, pos_t pos);
            ~ARect() = default;

            void setType(ObjectType type) override;
            ObjectType getType() const override;

            void isDisplay(bool isDisplay) override;
            bool isDisplay() const override;

            void setPos(pos_t pos) override;
            pos_t getPos() const override;

            void setColor(color_t color) override;
            color_t getColor() const override;

            void setBounds(shape_t bounds) override;
            shape_t getBounds() const override;

            void setShape(shape_t bounds) override;
            shape_t getShape() const override;

        private:
            ObjectType _type;
            bool _isDisplay;
            pos_t _pos;
            color_t _color;
            shape_t _bounds;
    };
}