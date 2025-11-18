/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-arcade-alexandre.douard
** File description:
** AGrid.hpp
*/

#pragma once

#include "IGames.hpp"
#include "ATexture.hpp"
#include "AText.hpp"
#include "ARect.hpp"
#include "ASprite.hpp"
#include "ABanner.hpp"

namespace arcade {

    class AGrid: public IGames {
        public:
            AGrid();
            virtual ~AGrid() = default;

            VPtrObject &getObjects() final;
            std::vector<std::string> &getFontPaths() final;
            VPtrTexture &getTextures() final;

            void addInfo(const std::string info, const int value, const color_t color);
            void updateInfo(const std::string info, const int value, const windowParameters_t windowP);

        protected:
            VPtrObject _objects;
            VPtrTexture _textures;
            std::vector<std::string> _fontPaths;

            size_t _row;
            size_t _col;
            std::vector<std::vector<int>> _grid;

            void _setObjectPositionAndScale(const windowParameters_t windowP);
            void _setSize(const size_t row, const size_t col, const color_t bg_color = {100, 100, 100, 255});

            ABanner _winBanner;
            ABanner _loseBanner;
            ABanner _pauseBanner;
        private:
            std::vector<std::pair<PtrTextObject, PtrTextObject>> _infos;
            VPtrSpriteObject _assets;
            PtrRect _background;
    };
}
