/*
** EPITECH PROJECT, 2024
** B-OOP-400-LYN-4-1-arcade-alexandre.douard
** File description:
** Settings
*/

#include "Settings.hpp"

static std::vector<std::pair<std::string, std::string>> keyMapString = {
    {"UP", "Z"},
    {"DOWN", "S"},
    {"LEFT", "Q"},
    {"RIGHT", "D"},
    {"CLICK", "SPACE"},
    {"RESTART", "R"},
    {"EXIT", "ESC"},
    {"NEXT_GAME", "RIGHT"},
    {"PREV_GAME", "LEFT"},
    {"NEXT_GRAPHIC", "UP"},
    {"PREV_GRAPHIC", "DOWN"}
};

namespace arcade::settings {
    Settings::Settings(std::vector<std::pair<event::ArcadeEvent, event::GameEvent>> &controls)
    :  _controls(controls), _default(controls)
    {
    }

    void Settings::initGame(const PtrWindowP windowP)
    {
        _state = State::SETTINGS;
        _windowParameters = windowP;

        _initTextures();
        _initFontPaths();
        _initObjects();
        _index = 0;
    }

    void Settings::_initObjects()
    {
        pos_t pos = {20, 40};
        color_t color = {255, 255, 255, 255};

        _objects.push_back(std::make_shared<SettingsBackground>(color_t{0, 0, 0, 255}));
        PtrTextObject text = std::make_shared<SettingsText>(0, "o_O SUP3R S3CR3T S3TT!NGS O_o", pos, 50, color_t{255, 0, 0, 255});
        _textObjects.push_back(std::make_tuple(text, pos, 50));
        _objects.push_back(text);
        pos.x += 195;
        pos.y += 95;

        text = std::make_shared<SettingsText>(0, ">", pos, 25, color_t{255, 255, 51, 255});
        _textObjects.push_back(std::make_tuple(text, pos, 25));
        _objects.push_back(text);
        pos.x += 25;

        size_t i = 0;
        for (auto [control, key] : keyMapString) {
            text = std::make_shared<SettingsText>(0, control, pos, 25, color);
            _textObjects.push_back(std::make_tuple(text, pos, 25));
            _objects.push_back(text);
            pos.x += 210;
            text = std::make_shared<SettingsText>(0, key, pos, 25, color_t{200, 200, 200, 255});
            _textObjects.push_back(std::make_tuple(text, pos, 25));
            _objects.push_back(text);
            pos.x -= 205;
            pos.y += 30;
            if (++i == 7)
                pos.y += 30;
        }
        pos.y += 50;
        text = std::make_shared<SettingsText>(0, "RIGHT to prompt, LEFT to reset", pos, 20, color_t{51, 51, 255, 255});
        _textObjects.push_back(std::make_tuple(text, pos, 20));
        _objects.push_back(text);
    }

    void Settings::_initTextures()
    {
    }

    void Settings::_initFontPaths()
    {
        _fontPaths.push_back("./assets/fonts/ITCAvantGardeStd-Demi.ttf");
    }

    void Settings::destroyGame()
    {
    }

    void Settings::restartGame()
    {
        for (_index = 0; _index < NB_SET; _index++)
            _resetControl();
        _resetCursor();
    }

    bool Settings::isGameOver()
    {
        return _prompt;
    }

    State Settings::execute(VGameEvent &events)
    {
        _executeEvent(events);
        if (_state == State::MENU) {
            _resetCursor();
            _state = State::SETTINGS;
            return State::MENU;
        }
        return _state;
    }

    int Settings::getScore()
    {
        return 0;
    }

    std::vector<std::string> &Settings::getFontPaths()
    {
        return this->_fontPaths;
    }

    VPtrTexture &Settings::getTextures()
    {
        return this->_textures;
    }

    VPtrObject &Settings::getObjects()
    {
        return this->_objects;
    }
}
