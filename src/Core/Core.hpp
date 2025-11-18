/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** Core
*/

#pragma once

#include <iostream>
#include <memory>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <dirent.h>
#include <dlfcn.h>
#include <chrono>
#include <fstream>
#include <sstream>
#include <set>

#include "DLObject.hpp"
#include "IGraphics.hpp"
#include "IGames.hpp"
#include "IObject.hpp"
#include "Window.hpp"
#include "Event.hpp"
#include "ErrorHandling.hpp"
#include "Menu.hpp"
#include "Settings.hpp"
#include "Multiset.hpp"

namespace arcade {
    enum class State;
    class IGames;

    static std::string defaultName("___________");

    class Core {
        public:
            Core(const std::string &path);
            ~Core();

            void run();

        private:
            void loadLibPath();
            void loadControls();
            void loadLib(const std::string &path);
            void loadGraphic(const std::string &path);
            void loadGame(const std::string &path);
            void loadPrimitiveGame();

            std::unique_ptr<IGames> &getGame();
            IGraphics &getGraphic();

            void execGraphic();
            void execGame();

            bool executePrimitiveEvent(event::GameEvent event);
            void changeGraphic(bool next);
            void changeGame(bool next);

            void getScoreboard();
            void setScoreboard();

            VPtrObject &getObjects();

            std::vector<std::string> &getGamesName();
            std::vector<std::string> &getGraphicsName();

            VGameEvent &getEvents();

            std::vector<std::string> _libPath;
            std::vector<std::pair<std::string,std::string>> _gamesLib;
            std::vector<std::pair<std::string,std::string>> _graphicsLib;

            Library<IGraphics> _graphic;
            Library<IGames> _game;
            std::string _graphicName;
            std::string _gameName;
            std::unique_ptr<IGames> _menu;
            std::unique_ptr<IGames> _settings;

            VPtrTexture _textures;
            std::vector<std::pair<event::ArcadeEvent, event::GameEvent>> _controls;
            State _state;
            PtrWindowP _windowParameters;
            VGameEvent _events;

            void _addScoreToScoreboard();
            std::map<std::string, std::multiset<std::pair<std::string, int>, CustomComparator>> _scoreboard;
            bool _scoreIsUploaded = false;

            std::string _playerName = defaultName;

    };
}
