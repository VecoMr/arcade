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

#include "IGraphics.hpp"
#include "IObject.hpp"
#include "Event.hpp"
#include "IGames.hpp"

namespace arcade {

    enum class ObjectType {
        GAME,
        LIB
    };

    enum class State {
        MENU,
        GAME,
        SETTINGS,
        PAUSE,
        WIN,
        LOSE,
        EXIT
    };

    class Core {
        public:
            Core();
            ~Core();

            void run();

        private:
            void loadGame(const std::string &path);
            void loadLib(const std::string &path);

            void execGame();
            void execLib();

            std::vector<std::string> &getGamesName();
            std::vector<std::string> &getGraphicsName();

            std::shared_ptr<IGraphics> _lib;
            // std::shared_ptr<IGames> _game;
            
            VPtrObject _objects;
            VPtrTexture _textures;
            std::map<event::ArcadeEvent, event::GameEvent> _controls;
            State _state;
            windowParameters_t _windowParameters;
    };
}