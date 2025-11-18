/*
** EPITECH PROJECT, 2024
** B-OOP-400-LYN-4-1-arcade-alexandre.douard
** File description:
** AText
*/

#pragma once

#include "IObject.hpp"

namespace arcade {
    class AText : public ITextObject {
        public:
            AText(int fontId, std::string text, pos_t pos, int size, color_t color);
            AText(int fontId, std::string text, pos_t pos, int size, color_t color, color_t backGroundColor);
            AText(int fontId, char *text, pos_t pos, int size, color_t color);
            ~AText() = default;

            void setType(const ObjectType type) override;
            ObjectType getType() const override;

            void isDisplay(bool isDisplay) override;
            bool isDisplay() const override;

            void setPos(const pos_t pos) override;
            pos_t getPos() const override;

            void setContent(const std::string text) override;
            std::string getContent() const override;

            void setIdFontFamily(const int id) override;
            int &getIdFontFamily() override;

            void setSize(const int size) override;
            int getSize() const override;

            void setColor(const color_t color) override;
            color_t getColor() const override;

            void setBounds(const shape_t bounds) override;
            shape_t getBounds() const override;

            void setBackGroundColor(const color_t color) override;
            color_t getBackGroundColor() const override;

            bool isIn(pos_t pos) const;

        private:
            int _fontId;
            std::string _text;
            pos_t _pos;
            int _size;
            color_t _color;
            bool _isDisplay;
            ObjectType _type;
            shape_t _bounds;
            color_t _backGroundColor;
    };
}