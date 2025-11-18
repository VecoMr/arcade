/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-arcade-alexandre.douard
** File description:
** Load.cpp
*/

#include "Core.hpp"

namespace arcade {
    void Core::loadLibPath() {
        std::string path = "./lib/";
        DIR *dir;
        struct dirent *ent;
        if ((dir = opendir(path.c_str())) != NULL) {
            while ((ent = readdir(dir)) != NULL) {
                std::string file = ent->d_name;
                std::cout << path + file << std::endl;
                if (file.find(".so") != std::string::npos) {
                    _libPath.push_back(path + file);
                    LibType lib = DLObject(path + file).getCall<LibType>("getType");
                    if (lib == LibType::GRAPHIC)
                        _graphicsLib.push_back(std::make_pair(path + file, DLObject(path + file).getCall<std::string>("getName")));
                    else if (lib == LibType::GAME)
                        _gamesLib.push_back(std::make_pair(path + file, DLObject(path + file).getCall<std::string>("getName")));

                }
            }
            closedir(dir);
        } else {
            std::cerr << "Could not open \"./lib\" directory." << std::endl;
        }
        if (!_graphicsLib.size() || !_gamesLib.size())
            throw ErrorH("No game libs were found.");
    }

    void Core::loadControls()
    {
        _controls.push_back({event::ArcadeEvent{.type = event::EventType::KEYBOARD,.evKey = {.type = event::Type::PRESSED,.key = event::keys::Z}}, event::GameEvent{event::GameEventType::UP, event::Type::PRESSED, {.key = event::keys::Z}}});
        _controls.push_back({event::ArcadeEvent{.type = event::EventType::KEYBOARD,.evKey = {.type = event::Type::PRESSED,.key = event::keys::S}}, event::GameEvent{event::GameEventType::DOWN, event::Type::PRESSED, {.key = event::keys::S}}});
        _controls.push_back({event::ArcadeEvent{.type = event::EventType::KEYBOARD,.evKey = {.type = event::Type::PRESSED,.key = event::keys::Q}}, event::GameEvent{event::GameEventType::LEFT, event::Type::PRESSED, {.key = event::keys::Q}}});
        _controls.push_back({event::ArcadeEvent{.type = event::EventType::KEYBOARD,.evKey = {.type = event::Type::PRESSED,.key = event::keys::D}}, event::GameEvent{event::GameEventType::RIGHT, event::Type::PRESSED, {.key = event::keys::D}}});
        _controls.push_back({event::ArcadeEvent{.type = event::EventType::KEYBOARD,.evKey = {.type = event::Type::PRESSED,.key = event::keys::SPACE}}, event::GameEvent{event::GameEventType::CLICK, event::Type::PRESSED, {.key = event::keys::SPACE}}});
        _controls.push_back({event::ArcadeEvent{.type = event::EventType::KEYBOARD,.evKey = {.type = event::Type::PRESSED,.key = event::keys::R}}, event::GameEvent{event::GameEventType::RESTART_GAME, event::Type::PRESSED, {.key = event::keys::R}}});
        _controls.push_back({event::ArcadeEvent{.type = event::EventType::KEYBOARD,.evKey = {.type = event::Type::PRESSED,.key = event::keys::ESCAPE}}, event::GameEvent{event::GameEventType::EXIT, event::Type::PRESSED, {.key = event::keys::ESCAPE}}});
        _controls.push_back({event::ArcadeEvent{.type = event::EventType::KEYBOARD,.evKey = {.type = event::Type::PRESSED,.key = event::keys::RIGHT}}, event::GameEvent{event::GameEventType::NEXT_GAME, event::Type::PRESSED, {.key = event::keys::RIGHT}}});
        _controls.push_back({event::ArcadeEvent{.type = event::EventType::KEYBOARD,.evKey = {.type = event::Type::PRESSED,.key = event::keys::LEFT}}, event::GameEvent{event::GameEventType::PREV_GAME, event::Type::PRESSED, {.key = event::keys::LEFT}}});
        _controls.push_back({event::ArcadeEvent{.type = event::EventType::KEYBOARD,.evKey = {.type = event::Type::PRESSED,.key = event::keys::UP}}, event::GameEvent{event::GameEventType::NEXT_GRAPHICAL, event::Type::PRESSED, {.key = event::keys::UP}}});
        _controls.push_back({event::ArcadeEvent{.type = event::EventType::KEYBOARD,.evKey = {.type = event::Type::PRESSED,.key = event::keys::DOWN}}, event::GameEvent{event::GameEventType::PREV_GRAPHICAL, event::Type::PRESSED, {.key = event::keys::DOWN}}});
    }

    void Core::loadLib(__attribute__((unused)) const std::string &path)
    {
        _graphic->initWindow(_windowParameters);
    }

    void Core::loadPrimitiveGame()
    {
        _menu = std::make_unique<menu::Menu>(menu::Menu(_graphicsLib, _gamesLib, _graphic, _game, _graphicName, _gameName, _playerName, _scoreboard));
        _menu->initGame(_windowParameters);
        _settings = std::make_unique<settings::Settings>(settings::Settings(_controls));
        _settings->initGame(_windowParameters);
    }

    void Core::loadGraphic(const std::string &path) {
        _graphic = DLObject(path).getInst<IGraphics>("createLib");
        _graphic->initWindow(_windowParameters);
        _graphic->loadFonts(getGame()->getFontPaths());
        _graphic->loadTextures(getGame()->getTextures());
    }

    void Core::loadGame(const std::string &path) {
        _game = DLObject(path).getInst<IGames>("createLib");
        _game->initGame(_windowParameters);
        _graphic->loadFonts(getGame()->getFontPaths());
        _graphic->loadTextures(getGame()->getTextures());
    }
}
