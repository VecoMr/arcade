/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-arcade-alexandre.douard
** File description:
** Snake.hpp
*/

#pragma once

#include "AGrid.hpp"
#include <list>
#include <fstream>

#define DEF_ROW 10
#define DEF_COL 16

#define NB_TEXTURE 16

#define SNAKE_SIZE 4

#define EMPTY -1
#define WALL 0
#define APPLE 1
#define H_RIGHT 2
#define H_DOWN 3
#define H_LEFT 4
#define H_UP 5
#define B_HORI 6
#define B_VERT 7
#define B_BL 8
#define B_TL 9
#define B_TR 10
#define B_BR 11
#define T_RIGHT 12
#define T_DOWN 13
#define T_LEFT 14
#define T_UP 15

namespace arcade {

    class Snake: public AGrid {
        public:
            Snake();
            ~Snake() = default;

            void initGame(const PtrWindowP windowP) override;
            void destroyGame() final;
            void restartGame() override;
            bool isGameOver() final;

            State execute(VGameEvent &events) override;
            int getScore() final;


        protected:
            PtrWindowP _windowParameters;
            std::vector<std::vector<int>> _map;

            State _state = State::GAME;
            int _level = 0;
            int _score = 0;
            int _size = 0;
            int _printedScore = 0;

            int _direction;
            virtual void _changeDirection(int direction);
            std::list<pos_t> _pos;

            int _start;
            std::chrono::milliseconds _tickTime;
            std::chrono::steady_clock::time_point _startTick = std::chrono::steady_clock::now();

            virtual void _loadMap(int id);
            virtual void _loadLevel();

            void _executeEvent(VGameEvent &events);

            virtual void _move();
            virtual void _printTail(int size, pos_t prev);

            virtual bool _generateSnake(pos_t pos);

        private:
            bool _generateApple();
    };
}
