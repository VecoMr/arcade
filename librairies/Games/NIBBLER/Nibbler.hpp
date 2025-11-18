/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-arcade-alexandre.douard
** File description:
** Nibbler.hpp
*/

#pragma once

#include "Snake.hpp"

namespace arcade {

    class Nibbler: public Snake {
        public:
            Nibbler();
            ~Nibbler() = default;

            void initGame(const PtrWindowP windowP) final;
            void restartGame() final;
            State execute(VGameEvent &events) final;

        private:
            int _timer = 1000;
            size_t _apple = 0;
            int _turn;
            void _changeDirection(int direction) final;
            void _move() final;
            bool _atWall();

            void _loadLevel() final;
            void _loadMap(int id) final;
    };
}
