/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-arcade-alexandre.douard
** File description:
** Event.cpp
*/

#include "Snake.hpp"

namespace arcade {
    void Snake::_executeEvent(VGameEvent &events) {
        for (auto event : events) {
            switch (event.type) {
            case event::GameEventType::WINDOW:
                switch (event.options.windowEv.type) {
                    case event::window::type::RESIZE:
                            _windowParameters->height = event.options.windowEv.height;
                            _windowParameters->width = event.options.windowEv.width;
                            _setObjectPositionAndScale(*_windowParameters);
                        break;
                    default:
                        break;
                }
                break;
            case event::GameEventType::EXIT:
                if (_state == State::PAUSE) {
                    _pauseBanner.isDisplay(false);
                    _state = State::GAME;
                } else if (_state == State::GAME) {
                    _pauseBanner.isDisplay(true);
                    _state = State::PAUSE;
                } else if (_state == State::WIN || _state == State::LOSE) {
                    _score = _printedScore;
                    _state = State::MENU;
                }
                break;
            case event::GameEventType::RESTART_GAME:
                if (_state == State::PAUSE)
                    _state = State::MENU;
                else
                    restartGame();
                break;
            case event::GameEventType::RIGHT: _changeDirection(H_RIGHT); break;
            case event::GameEventType::DOWN: _changeDirection(H_DOWN); break;
            case event::GameEventType::LEFT: _changeDirection(H_LEFT); break;
            case event::GameEventType::UP: _changeDirection(H_UP); break;
            default:
                break;
            }
            events.erase(events.begin());
        }
    }
}