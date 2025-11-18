/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-arcade-alexandre.douard
** File description:
** ABanner.hpp
*/

#pragma once

#include "AText.hpp"
#include "ARect.hpp"
#include "Window.hpp"

namespace arcade {
    class ABanner {
        public:
            ABanner();
            ~ABanner() = default;

            VPtrObject &getObjects();
            void initBanner(std::string title, std::string description, color_t background);
            void setObjectPositionAndScale(const windowParameters_t windowP);
            void isDisplay(const bool display);

        private:
            VPtrObject _objects;

            std::vector<std::tuple<PtrTextObject, pos_t, int>> _textObjects;
            std::pair<PtrRect, PtrRect> _rectObjects;
    };
}