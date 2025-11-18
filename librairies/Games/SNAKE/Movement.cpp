/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-arcade-alexandre.douard
** File description:
** Movement.c
*/

#include "Snake.hpp"

namespace arcade {
    void Snake::_changeDirection(int direction) {
        if (std::abs(direction - _direction) == 2)
            return;
        if (_direction != direction) {
            _direction = direction;
        } else if (_tickTime == std::chrono::milliseconds(170))
            _tickTime = std::chrono::milliseconds(100);
        else
            _tickTime = std::chrono::milliseconds(170);
    }

    void Snake::_move() {
        pos_t head = _pos.front();
        bool grow = false;

        if (std::abs(_grid[head.x][head.y] - _direction) == 2) {
            _direction = _grid[head.x][head.y];
        }
        switch (_direction) {
            case H_RIGHT: head.x++; break;
            case H_DOWN: head.y++; break;
            case H_LEFT: head.x--; break;
            case H_UP: head.y--; break;
            default:
                break;
        }
        head.x = (head.x + _col) % _col;
        head.y = (head.y + _row) % _row;
        switch (_grid[head.x][head.y]) {
            case APPLE:
                _size++;
                grow = true;
            case T_RIGHT:
            case T_DOWN:
            case T_LEFT:
            case T_UP:
            case EMPTY:
                _pos.push_front(head);
                _printTail(_size + SNAKE_SIZE, head);
                break;
            default:
                _state = State::LOSE;
                _loseBanner.isDisplay(true);
                break;
        }
        if (grow) {
            _printedScore++;
            _tickTime = std::chrono::milliseconds(_tickTime - _tickTime / 99);
            if (!_generateApple()) {
                _state = State::WIN;
                _winBanner.isDisplay(true);
            }
            updateInfo("Score", _printedScore, *_windowParameters);
        }
    }

    void Snake::_printTail(int size, pos_t prev) {
        for (auto current : _pos) {
            int x_offset = current.x - prev.x;
            int y_offset = current.y - prev.y;
            if (std::abs(x_offset) > 1)
                x_offset = -x_offset;
            if (std::abs(y_offset) > 1)
                y_offset = -y_offset;
            bool right = x_offset > 0 ? true : false;
            bool down = y_offset > 0 ? true : false;
            bool left = x_offset < 0 ? true : false;
            bool up = y_offset < 0 ? true : false;

            int asset = _grid[current.x][current.y];

            if (current.x == prev.x && current.y == prev.y)
                _grid[current.x][current.y] = _direction;
            if (size == 1) {
                if (right)
                    _grid[current.x][current.y] = T_RIGHT;
                if (left)
                    _grid[current.x][current.y] = T_LEFT;
                if (down)
                    _grid[current.x][current.y] = T_DOWN;
                if (up)
                    _grid[current.x][current.y] = T_UP;
            } else if (size == _size + 3) {
                switch (asset) {
                    case H_RIGHT: right = true; break;
                    case H_LEFT: left = true; break;
                    case H_DOWN: down = true; break;
                    case H_UP: up = true; break;
                }
                if ((right || left) && !down && !up)
                    _grid[current.x][current.y] = B_HORI;
                if ((down || up) && !right && !left)
                    _grid[current.x][current.y] = B_VERT;
                if (right && down)
                    _grid[current.x][current.y] = B_TL;
                if (right && up)
                    _grid[current.x][current.y] = B_BL;
                if (left && down)
                    _grid[current.x][current.y] = B_TR;
                if (left && up)
                    _grid[current.x][current.y] = B_BR;
            }
            if (!size) {
                switch (_grid[current.x][current.y]) {
                    case T_RIGHT:
                    case T_DOWN:
                    case T_LEFT:
                    case T_UP:
                        _grid[current.x][current.y] = EMPTY;
                        break;
                default:
                    break;
                }
                _pos.pop_back();
                break;
            }
            prev = current;
            size--;
        }
    }
}