/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-arcade-alexandre.douard
** File description:
** Event.cpp
*/

#include "Settings.hpp"

namespace arcade::settings {
    void Settings::_setObjectPositionAndScale(const windowParameters_t windowP) {
        float xScale = windowP.width / DEF_WIDTH;
        float yScale = windowP.height / DEF_HEIGHT;

        auto &[title, p, s] = _textObjects[0];

        p.x = xScale == 1 ? p.x : (windowP.width / 20);
        for (auto &[text, pos, size] : _textObjects) {
            float xNewPos = pos.x * xScale;
            float yNewPos = pos.y * yScale;
            text->setPos({(int)xNewPos, (int)yNewPos});
            text->setSize(size * yScale);
        }
    }

    void Settings::_executeEvent(VGameEvent &events) {
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
            if (_prompt) {
                _executePromptEvent(event);
                events.erase(events.begin());
                continue;
            }
            switch (event.type) {
                case event::GameEventType::EXIT: _state = State::MENU; break;
                case event::GameEventType::RESTART_GAME: restartGame(); break;
                case event::GameEventType::DOWN: _moveCursor(true); break;
                case event::GameEventType::UP: _moveCursor(false); break;
                case event::GameEventType::RIGHT: _beginPrompt(); break;
                case event::GameEventType::LEFT: _resetControl(); break;
                default:
                    break;
            }
            events.erase(events.begin());
        }
    }

    void Settings::_beginPrompt() {
        _prompt = true;
        std::get<0>(_textObjects[_index * 2 + 3])->setContent("_");
        std::get<0>(_textObjects[_index * 2 + 3])->setColor({0, 255, 0, 255});
    }
    void Settings::_executePromptEvent(event::GameEvent &event) {
        if ((event.type == event::GameEventType::KEYBOARD && event.state == event::Type::PRESSED) || event.type == event::GameEventType::CLICK
        || event.type == event::GameEventType::DOWN || event.type == event::GameEventType::LEFT
        || event.type == event::GameEventType::NEXT_GAME  || event.type == event::GameEventType::NEXT_GRAPHICAL
        || event.type == event::GameEventType::PREV_GAME || event.type == event::GameEventType::PREV_GRAPHICAL
        || event.type == event::GameEventType::RESTART_GAME || event.type == event::GameEventType::UP
        || event.type == event::GameEventType::RIGHT) {
            std::string newKey = toString(event.options.key);
            if (newKey == "")
                newKey = toStringSpecial(event.options.key);
            if (newKey == "")
                return;
            std::get<0>(_textObjects[_index * 2 + 3])->setContent(newKey);
            std::get<0>(_textObjects[_index * 2 + 3])->setColor({200, 200, 200, 255});
            auto it = std::next(_controls.begin(), _index);
            it->first = event::ArcadeEvent {.type = event::EventType::KEYBOARD,.evKey = {.type = event::Type::PRESSED,.key = event.options.key}};
            it->second.options.key = event.options.key;
            _prompt = false;
        }
    }

    void Settings::_resetControl() {
        auto it = std::next(_controls.begin(), _index);
        auto itDefault = std::next(_default.begin(), _index);

        it->first = itDefault->first;
        it->second.options.key = itDefault->second.options.key;

        std::string oldKey = toString(it->second.options.key);
        if (oldKey == "")
            oldKey = toStringSpecial(it->second.options.key);
        std::get<0>(_textObjects[_index * 2 + 3])->setContent(oldKey);
        std::get<0>(_textObjects[_index * 2 + 3])->setColor({200, 200, 200, 255});
    }
}