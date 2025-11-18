/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-arcade-alexandre.douard
** File description:
** Map.cpp
*/

#include "Nibbler.hpp"

#define MAP "assets/Nibbler/map/"

static std::vector<std::string> maps = {
    MAP"map1.txt",
    MAP"map2.txt",
    MAP"map3.txt",
    MAP"map4.txt",
    MAP"map5.txt"};

namespace arcade {
    void Nibbler::_loadMap(int id) {
        size_t id_s = id;
        const std::string map = id < 0 || id_s >= maps.size() ? "" : maps[id];
        std::ifstream file(map);

        _map.clear();
        if (!file.is_open()) {
            std::cerr << "Map file could not be opened. Training map loading..." << std::endl;
            _row = DEF_ROW;
            _col = DEF_COL;
            _map.resize(_col, std::vector<int>(_row, EMPTY));
            for (size_t i = 0; i < _row; ++i) {
                for (size_t j = 0; j < _col; ++j) {
                    if (i == 0 || i == _row - 1 || j == 0 || j == _col - 1)
                        _map[j][i] = WALL;
                }
            }
            _map[0][0] = APPLE;
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
}