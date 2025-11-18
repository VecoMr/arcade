/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-arcade-alexandre.douard
** File description:
** Map.cpp
*/

#include "Snake.hpp"

#define MAP "assets/Snake/map/"

static std::vector<std::string> maps = {
    MAP"map1.txt",
    MAP"map2.txt",
    MAP"map3.txt",
    MAP"map4.txt",
    MAP"map5.txt",
    MAP"map_win.txt",
    MAP"map_keur.txt",
    MAP"map_antoine.txt",
    MAP"map_kentin.txt"};

namespace arcade {
    void Snake::_loadMap(int id) {
        const std::string map = id < 0 ? "" : maps[id % maps.size()];
        std::ifstream file(map);

        _map.clear();
        if (!file.is_open()) {
            std::cerr << "Map file could not be opened. Default map loading..." << std::endl;;
            _row = DEF_ROW;
            _col = DEF_COL;
            _map.resize(_col, std::vector<int>(_row, EMPTY));
            for (size_t i = 0; i < _row; ++i) {
                for (size_t j = 0; j < _col; ++j) {
                    if (i == 0 || i == _row - 1 || j == 0 || j == _col - 1)
                        _map[j][i] = WALL;
                }
            }
            return;
        }

        file >> _row >> _col;
        _map.resize(_col, std::vector<int>(_row, EMPTY));
        for (size_t i = 0; i < _row; ++i) {
            for (size_t j = 0; j < _col; ++j) {
                file >> _map[j][i];
                _map[j][i]--;
            }
        }
        file.close();
    }

    bool Snake::_generateSnake(pos_t pos) {
        _direction = H_RIGHT;

        _pos.clear();
        _pos.push_front(pos);
        _grid[pos.x][pos.y] = _direction;
        for (int i = 1; i < SNAKE_SIZE; i++) {
            pos.x--;
            pos.x = (pos.x + _col) % _col;
            _grid[pos.x][pos.y] = B_HORI;
            _pos.push_back(pos);
        }
        _grid[pos.x][pos.y] = T_LEFT;
        _printTail(SNAKE_SIZE + 1, _pos.front());
        return true;
    }

    bool Snake::_generateApple() {
        size_t x = rand() % _col;
        size_t y = rand() % _row;

        bool stop = false;
        for (size_t i = (y + 1) % _row; !stop; i = (i + 1) % _row) {
            for (size_t j = (x + 1) % _col; j != x;) {
                if (_grid[j][i] == EMPTY) {
                    _grid[j][i] = APPLE;
                    return true;
                }
                j = (j + 1) % _col;
                if (j == x && i == y) {
                    stop = true;
                    break;
                }
            }
        }
        return false;
    }
}