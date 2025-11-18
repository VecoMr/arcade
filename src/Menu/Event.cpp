/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-arcade-alexandre.douard
** File description:
** Event.cpp
*/

#include "Menu.hpp"

namespace arcade::menu {
    void Menu::_setObjectPositionAndScale(const windowParameters_t windowP) {
        float xScale = windowP.width / DEF_WIDTH;
        float yScale = windowP.height / DEF_HEIGHT;

        for (auto &[text, pos, size] : _textObjects) {
            float xNewPos = pos.x * xScale;
            float yNewPos = pos.y * yScale;
            text->setPos({(int)xNewPos, (int)yNewPos});
            text->setSize(size * yScale);
        }
        _leaderboard.setObjectPositionAndScale(windowP);
    }

    void Menu::_executeEvent(VGameEvent &events) {
        for (auto event : events) {
            if (event.type == event::GameEventType::WINDOW) {
                switch (event.options.windowEv.type) {
                    case event::window::type::RESIZE:
                            _windowParameters->height = event.options.windowEv.height;
                            _windowParameters->width = event.options.windowEv.width;
                            _setObjectPositionAndScale(*_windowParameters);
                        break;
                    default:
                        break;
                }
                events.erase(events.begin());
                continue;
            }
            if (event.type == event::GameEventType::KEYBOARD && event.state == event::Type::PRESSED) {
                if (event.options.key == event::keys::RETURN) {
                    if (_category == Category::USERNAME) {
                        _prompt = !_prompt;
                        if (_prompt)
                            std::get<0>(_textObjects[_index])->setColor({0, 255, 0, 255});
                        else
                            std::get<0>(_textObjects[_index])->setColor({255, 255, 255, 255});
                    }
                }
            }
            if (_prompt) {
                _executeEventName(event);
                events.erase(events.begin());
                continue;
            }
            switch (event.type) {
                case event::GameEventType::EXIT: _state = State::EXIT; break;
                case event::GameEventType::RESTART_GAME: restartGame(); break;
                case event::GameEventType::DOWN: _selectLib(1); break;
                case event::GameEventType::UP: _selectLib(-1); break;
                case event::GameEventType::RIGHT: _selectCategory(1); break;
                case event::GameEventType::LEFT: _selectCategory(-1); break;
                default:
                    break;
            }
            events.erase(events.begin());
        }
    }

    void Menu::_executeEventName(event::GameEvent &event) {
        if ((event.type == event::GameEventType::KEYBOARD && event.state == event::Type::PRESSED) || event.type == event::GameEventType::CLICK
        || event.type == event::GameEventType::DOWN || event.type == event::GameEventType::LEFT
        || event.type == event::GameEventType::NEXT_GAME  || event.type == event::GameEventType::NEXT_GRAPHICAL
        || event.type == event::GameEventType::PREV_GAME || event.type == event::GameEventType::PREV_GRAPHICAL
        || event.type == event::GameEventType::RESTART_GAME || event.type == event::GameEventType::UP
        || event.type == event::GameEventType::RIGHT) {
            if (event.options.key == event::keys::BACKSPACE) {
                if (!_playerName.empty() && _playerName != defaultName)
                    _playerName.pop_back();
            } else if (_playerName.size() < 11 || _playerName == defaultName) {
                if (event.options.key  == event::keys::SPACE && _playerName != defaultName)
                    _playerName += "_";
                else {
                    if (_playerName == defaultName)
                        _playerName = "";
                    _playerName += toString(event.options.key);
                }
            }
        }
        if (_playerName.empty())
            _playerName = defaultName;
        std::get<0>(_textObjects[_index])->setContent(_playerName);
    }
}