/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-arcade-alexandre.douard
** File description:
** Select.cpp
*/

#include "Menu.hpp"

namespace arcade::menu {
    void Menu::_moveCursor() {
        _index = _selected[_category];
        switch (_category) {
            case USERNAME: _index = _games.size() + 1;
            __attribute__ ((fallthrough));
            case GAME: _index += _graphics.size() + 1;
            __attribute__ ((fallthrough));
            case GRAPHIC: _index++; break;
            default:
                break;
        }
        if (_category >= GAME) {
            _printScoreboard();
            _leaderboard.isDisplay(true);
        } else
            _leaderboard.isDisplay(false);
        std::get<1>(_textObjects.back()).y = std::get<1>(_textObjects[_index]).y + 3;
        std::get<0>(_textObjects[_index])->setBackGroundColor({0, 0, 0, 255});
        std::get<0>(_textObjects[_index])->setColor({255, 255, 255, 255});
        _setObjectPositionAndScale(*_windowParameters);
    }

    void Menu::_selectLib(int next) {
        _selected[_category] += next;
        size_t top = 0;
        switch (_category) {
            case GRAPHIC: top = _graphics.size(); break;
            case GAME: top = _games.size(); break;
            default:
                break;
        }
        if (_selected[_category] >= top)
            _selected[_category] = next > 0 ? 0 : top - 1;
        _moveCursor();
    }

    void Menu::_selectCategory(int next) {
        int index = static_cast<int>(_category) + next;
        if (index < 0)
            index = 0;
        _category = static_cast<Category>(index);
        if (_category != END) {
            if (next > 0) {
                std::get<0>(_textObjects[_index])->setBackGroundColor({255, 255, 255, 255});
                std::get<0>(_textObjects[_index])->setColor({0, 0, 0, 255});
            }
            _moveCursor();
        } else if (_playerName == defaultName) {
            _category = USERNAME;
            std::get<0>(_textObjects[_index])->setColor({255, 0, 0, 255});
        }
    }
}
