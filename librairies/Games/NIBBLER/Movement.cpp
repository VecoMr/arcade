/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-arcade-alexandre.douard
** File description:
** Movement.c
*/

#include "Nibbler.hpp"

namespace arcade {
    void Nibbler::_changeDirection(int direction) {
        if (std::abs(direction - _direction) == 2)
            return;
        _direction = direction;
    }

    void Nibbler::_move() {
        pos_t head = _pos.front();
        bool grow = false;

        if (_direction != _grid[head.x][head.y]) {
            if (std::abs(_grid[head.x][head.y] - _direction) == 2)
                _direction = _grid[head.x][head.y];
            _turn = _direction;
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
            case WALL:
                if (_atWall())
                    return _move();
                _timer -= 15;
                break;
            default:
                _state = State::LOSE;
                _loseBanner.isDisplay(true);
                break;
        }
        if (grow) {
            if (!--_apple) {
                _state = State::WIN;
                _winBanner.isDisplay(true);
                _printedScore += _timer / 50;
            }
            _printedScore++;
            updateInfo("Score", _printedScore, *_windowParameters);
        }
        _direction = _turn;
    }

    bool Nibbler::_atWall() {
        pos_t head = _pos.front();
        int newDirection = _direction;
        bool first = false;
        bool second = false;
        if (_direction != _grid[head.x][head.y]) {
            _turn = _direction;
            _direction = _grid[head.x][head.y];
            return true;
        }
        if (_direction == H_RIGHT || _direction == H_LEFT) {
            if (_grid[head.x][head.y - 1] != WALL) {
                newDirection = H_UP;
                first = true;
            }
            if (_grid[head.x][head.y + 1] != WALL) {
                newDirection = H_DOWN;
                second = true;
            }
        } else {
            if (_grid[head.x - 1][head.y] != WALL) {
                newDirection = H_LEFT;
                first = true;
            }
            if (_grid[head.x + 1][head.y] != WALL) {
                newDirection = H_RIGHT;
                second = true;
            }
        }
        if (first && second)
            return false;
        _direction = newDirection;
        return true;
    }
}