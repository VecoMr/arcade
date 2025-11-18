/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-arcade-alexandre.douard
** File description:
** Select.cpp
*/

#include "Settings.hpp"

namespace arcade::settings {
    void Settings::_resetCursor() {
        _index = 0;

        std::get<1>(_textObjects[1]).y = std::get<1>(_textObjects[_index * 2 + 2]).y;
        std::get<1>(_textObjects[1]).x = std::get<1>(_textObjects[_index * 2 + 2]).x - 25;
        _setObjectPositionAndScale(*_windowParameters);
    }

    void Settings::_moveCursor(bool next) {
        _index += next ? 1 : -1;
        _index = (_index + NB_SET) % NB_SET;

        std::get<1>(_textObjects[1]).y = std::get<1>(_textObjects[_index * 2 + 2]).y;
        std::get<1>(_textObjects[1]).x = std::get<1>(_textObjects[_index * 2 + 2]).x - 25;
        _setObjectPositionAndScale(*_windowParameters);
    }
}
