/*
** EPITECH PROJECT, 2024
** B-OOP-400-LYN-4-1-arcade-alexandre.douard
** File description:
** Menu
*/

#include "Menu.hpp"

namespace arcade::menu {
    Menu::Menu(std::vector<std::pair<std::string, std::string>> &graphics, std::vector<std::pair<std::string, std::string>> &games, Library<IGraphics> &graphic, Library<IGames> &game, std::string &graphicName, std::string &gameName, std::string &playerName, std::map<std::string, std::multiset<std::pair<std::string, int>, CustomComparator>> &scoreboard)
    :  _graphics(graphics), _games(games), _graphic(graphic), _game(game), _graphicName(graphicName), _gameName(gameName), _playerName(playerName), _scoreboard(scoreboard)
    {
    }

    void Menu::initGame(const PtrWindowP windowP)
    {
        _state = State::MENU;
        _windowParameters = windowP;

        _initTextures();
        _initFontPaths();
        _initObjects();
        _selected = {0, 0, 0};
        for (auto [path, name] : _graphics) {
            if (name == _graphicName)
                break;
            _selected[GRAPHIC]++;
        }
        restartGame();
    }

    void Menu::_initObjects()
    {
        pos_t pos = {20, 20};
        color_t color = {255, 255, 255, 255};

        _objects.push_back(std::make_shared<MenuBackground>(color_t{0, 0, 0, 255}));
        PtrTextObject text = std::make_shared<MenuText>(0, "Graphic Libs:", pos, 50, color);
        _textObjects.push_back(std::make_tuple(text, pos, 50));
        _objects.push_back(text);
        pos.x = 60;
        pos.y += 40;
        for (auto &[path, name] : _graphics) {
            pos.y += 30;
            text = std::make_shared<MenuText>(0, path, pos, 25, color);
            _textObjects.push_back(std::make_tuple(text, pos, 25));
            _objects.push_back(text);
        }
        pos.x = 20;
        pos.y += 70;
        text = std::make_shared<MenuText>(0, "Game Libs:", pos, 50, color);
        _textObjects.push_back(std::make_tuple(text, pos, 50));
        _objects.push_back(text);
        pos.x = 60;
        pos.y += 40;
        for (auto &[path, name] : _games) {
            pos.y += 30;
            text = std::make_shared<MenuText>(0, path, pos, 25, color);
            _textObjects.push_back(std::make_tuple(text, pos, 25));
            _objects.push_back(text);
        }
        pos.x = 20;
        pos.y += 70;
        text = std::make_shared<MenuText>(0, "Username:", pos, 50, color);
        _textObjects.push_back(std::make_tuple(text, pos, 50));
        _objects.push_back(text);
        pos.x = 70;
        pos.y += 80;
        text = std::make_shared<MenuText>(0, _playerName, pos, 50, color);
        _textObjects.push_back(std::make_tuple(text, pos, 35));
        _objects.push_back(text);
        pos.x = 40;
        pos.y = 93;
        text = std::make_shared<MenuText>(0, ">", pos, 20, color_t{255, 255, 51, 255});
        _textObjects.push_back(std::make_tuple(text, pos, 20));
        _objects.push_back(text);
        for (auto object : _leaderboard.getObjects())
            _objects.push_back(object);
    }

    void Menu::_initTextures()
    {
    }

    void Menu::_initFontPaths()
    {
        _fontPaths.push_back("./assets/fonts/ITCAvantGardeStd-Demi.ttf");
    }

    void Menu::destroyGame()
    {
    }

    void Menu::restartGame()
    {
        _index = _graphics.size() + _selected[GAME] + 2;
        std::get<0>(_textObjects[_index])->setBackGroundColor({0, 0, 0, 255});
        std::get<0>(_textObjects[_index])->setColor({255, 255, 255, 255});
        _category = GRAPHIC;
        _moveCursor();
    }

    bool Menu::isGameOver()
    {
        return _prompt;
    }

    State Menu::execute(VGameEvent &events)
    {
        _executeEvent(events);
        if (_category == END) {
            if (_playerName == "H4CK3UR") {
                restartGame();
                return State::SETTINGS;
            }
            if (_graphics[_selected[GRAPHIC] % _graphics.size()].second != _graphicName) {
                _graphicName = _graphics[_selected[GRAPHIC] % _graphics.size()].second;
                _graphic = DLObject(_graphics[_selected[GRAPHIC] % _graphics.size()].first).getInst<IGraphics>("createLib");
                _graphic->initWindow(_windowParameters);
            }
            _gameName = _games[_selected[GAME] % _games.size()].second;
            _game = DLObject(_games[_selected[GAME] % _games.size()].first).getInst<IGames>("createLib");
            _game->initGame(_windowParameters);
            _graphic->loadFonts(_game->getFontPaths());
            _graphic->loadTextures(_game->getTextures());
            restartGame();
            return State::GAME;
        }
        return _state;
    }

    int Menu::getScore()
    {
        return 0;
    }

    std::vector<std::string> &Menu::getFontPaths()
    {
        return this->_fontPaths;
    }

    VPtrTexture &Menu::getTextures()
    {
        return this->_textures;
    }

    VPtrObject &Menu::getObjects()
    {
        return this->_objects;
    }
}
