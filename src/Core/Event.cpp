/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-arcade-alexandre.douard
** File description:
** Event.cpp
*/

#include "Core.hpp"

namespace arcade {
    void Core::changeGraphic(bool next) {
        int index = 0;

        for (auto [path, name] : _graphicsLib) {
            if (name == _graphicName)
                break;
            index++;
        }

        index += next ? 1 : -1;
        index = (index + _graphicsLib.size()) % _graphicsLib.size();

        auto [path, name] = _graphicsLib[index];
        _graphicName = name;
        loadGraphic(path);
    }

    void Core::changeGame(bool next) {
        int index = 0;

        for (auto [path, name] : _gamesLib) {
            if (name == _gameName)
                break;
            index++;
        }

        index += next ? 1 : -1;
        index = (index + _gamesLib.size()) % _gamesLib.size();

        auto [path, name] = _gamesLib[index];
        _gameName = name;
        loadGame(path);
    }

    bool Core::executePrimitiveEvent(event::GameEvent event) {
        bool isPrimitive = true;

        if (_menu->isGameOver() || _settings->isGameOver())
            return false;
        switch (event.type) {
            case event::GameEventType::NEXT_GAME: changeGame(true); break;
            case event::GameEventType::PREV_GAME: changeGame(false); break;
            case event::GameEventType::NEXT_GRAPHICAL: changeGraphic(true); break;
            case event::GameEventType::PREV_GRAPHICAL: changeGraphic(false); break;
            default:
                isPrimitive = false;
                break;
        }
        return isPrimitive;
    }

    VGameEvent &Core::getEvents() {
        for (auto event : _graphic->getEvents()) {
            auto it = _controls.begin();
            for (auto &[control, key] : _controls) {
                if (event == control)
                    break;
                it++;
            }
            if (it != _controls.end() && it->first.evKey.type == event.evKey.type) {
                if (executePrimitiveEvent(it->second))
                    break;
                _events.push_back(it->second);
            } else {
                if (event.type == event::EventType::KEYBOARD) {
                    _events.push_back(event::GameEvent {.type = event::GameEventType::KEYBOARD,.state = event.evKey.type,.options = {.key = event.evKey.key}});
                } else if (event.type == event::EventType::WINDOW) {
                    if (event.evWindow.type == event::window::type::RESIZE)
                        _events.push_back(event::GameEvent {.type = event::GameEventType::WINDOW,.state = event::Type::PRESSED,.options = {.windowEv = { .width = event.evWindow.width, .height = event.evWindow.height, .type = event::window::type::RESIZE}}});
                    if (event.evWindow.type == arcade::event::window::type::CLOSE) {
                        _state = State::EXIT;
                        break;
                    }
                } else if (event.type == event::EventType::MOUSE) {
                    _events.push_back(event::GameEvent {.type = event::GameEventType::CLICK,.state = event::Type::PRESSED,.options = {.mouse = { .x = event.evMouse.x, .y = event.evMouse.y}}});
                } else {
                    _events.push_back(event::GameEvent{event::GameEventType::NONE, event::Type::PRESSED, {}});
                }
            }
        }
        return _events;
    }
}