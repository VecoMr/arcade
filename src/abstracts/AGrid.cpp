/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-arcade-alexandre.douard
** File description:
** AGrid.cpp
*/

#include "AGrid.hpp"

namespace arcade {
    class IGames;

    AGrid::AGrid() {
    }

    VPtrObject &AGrid::getObjects() {
        size_t asset = 0;
        for (auto row : _grid) {
            for (auto cell : row) {
                if (cell == -1) {
                    _assets[asset]->isDisplay(false);
                } else {
                    _assets[asset]->setIdTexture(cell);
                    _assets[asset]->isDisplay(true);
                }
                asset++;
            }
        }
        return _objects;
    }

    std::vector<std::string> &AGrid::getFontPaths() {
        return _fontPaths;
    }

    VPtrTexture &AGrid::getTextures() {
        return _textures;
    }

    void AGrid::_setObjectPositionAndScale(const windowParameters_t windowP) {
        size_t info_rows = _infos.size();
        size_t row_size = windowP.height / (_row + info_rows);
        size_t col_size = windowP.width / _col;
        int square_size = row_size > col_size ? col_size : row_size;
        int x_start = 0;
        int y_start = 0;

        if (row_size > col_size)
            y_start += (windowP.height - (_row + info_rows) * col_size) / 2;
        else
            x_start = (windowP.width - _col * row_size) / 2;

        pos_t pos = {.x = x_start, .y = y_start};
        for (auto [str, val] : _infos) {
            str->setPos(pos);
            str->setSize(square_size - 10);
            pos.x += _col * square_size - val->getContent().size() * (square_size - 8) / 2;
            val->setPos(pos);
            val->setSize(square_size - 10);
            pos.x = x_start;
            pos.y += square_size;
        }
        y_start = pos.y;
        pos.x = x_start;
        size_t i = 0;
        for (auto &asset : _assets) {
            asset->setPos(pos);
            asset->setShape({0, 0, square_size, square_size});
            pos.y += square_size;
            if (++i == _row) {
                i = 0;
                pos.y = y_start;
                pos.x += square_size;
            }
        }
        _background->setPos({x_start, y_start});
        _background->setShape({0, 0, static_cast<int>(square_size * _col), static_cast<int>(square_size * _row)});
        _winBanner.setObjectPositionAndScale(windowP);
        _loseBanner.setObjectPositionAndScale(windowP);
        _pauseBanner.setObjectPositionAndScale(windowP);
    }

    void AGrid::_setSize(const size_t row, const size_t col, const color_t bg_color) {
        // if (row == 0 || col == 0)
        //     throw ErrorH("Grid size not valid");

        _row = row;
        _col = col;
        _grid.clear();
        _grid.resize(col, std::vector<int>(row, -1));
        _assets.resize(row * col);

        _objects.resize(_infos.size() * 2);

        shape_t shape = {0, 0, 0, 0};
        pos_t pos = {0, 0};
        _background = std::make_shared<ARect>(shape, bg_color, pos);
        _objects.push_back(_background);
        for (auto &asset : _assets) {
            asset = std::make_shared<ASprite>(0, shape, pos, shape);
            asset->isDisplay(false);
            _objects.push_back(asset);
        }
        for (auto object : _winBanner.getObjects())
            _objects.push_back(object);
        for (auto object : _loseBanner.getObjects())
            _objects.push_back(object);
        for (auto object : _pauseBanner.getObjects())
            _objects.push_back(object);
    }

    void AGrid::addInfo(const std::string info, const int value, const color_t color) {
        pos_t pos = {0, 0};
        PtrTextObject str = std::make_shared<AText>(0, info, pos, 0, color);
        PtrTextObject val = std::make_shared<AText>(0, std::to_string(value), pos, 0, color);
        _objects.push_back(str);
        _objects.push_back(val);
        _infos.push_back(std::make_pair(str, val));
    }

    void AGrid::updateInfo(const std::string info, const int value, const windowParameters_t windowP) {
        for (auto [str, val] : _infos) {
            if (str->getContent() == info) {
                val->setContent(std::to_string(value));
                _setObjectPositionAndScale(windowP);
                break;
            }
        }
    }
}