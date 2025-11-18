/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** Menu
*/

#pragma once

#include "IObject.hpp"
#include "Event.hpp"
#include "IGames.hpp"
#include "ABackground.hpp"
#include "AText.hpp"
#include "ARect.hpp"
#include "Core.hpp"
#include "Multiset.hpp"
#include <array>

#define NB_CAT 3

namespace arcade {
    enum class State;
    class IGames;
    class Core;

    namespace menu {
        class Leaderboard {
            public:
            Leaderboard();
            ~Leaderboard() = default;

            VPtrObject &getObjects();
            void setObjectPositionAndScale(const windowParameters_t windowP);
            void isDisplay(const bool display);

            void updateLeaderboard(size_t line, std::string name, int score);

        private:
            VPtrObject _objects;

            std::vector<std::tuple<PtrTextObject, pos_t, int>> _textObjects;
            std::pair<std::pair<PtrRect, shape_t>, std::pair<PtrRect, shape_t>> _rectObjects;
        };

        class Menu : public IGames {
            public:
                enum Category {
                    GRAPHIC,
                    GAME,
                    USERNAME,
                    END
                };

                Menu(std::vector<std::pair<std::string, std::string>> &graphics, std::vector<std::pair<std::string, std::string>> &games, Library<IGraphics> &graphic, Library<IGames> &game, std::string &graphicName, std::string &gameName, std::string &playerName, std::map<std::string, std::multiset<std::pair<std::string, int>, CustomComparator>> &scoreboard);
                ~Menu() = default;

                void initGame(const PtrWindowP windowP) final;
                void destroyGame() final;
                void restartGame() final;
                bool isGameOver() final;

                arcade::State execute(VGameEvent &events) final;
                int getScore() final;

                std::vector<std::string> &getFontPaths() final;
                VPtrTexture &getTextures() final;
                VPtrObject &getObjects() final;

            private:
                PtrWindowP _windowParameters;
                State _state;

                std::vector<std::string> _fontPaths;
                VPtrTexture _textures;
                VPtrObject _objects;
                std::vector<std::tuple<PtrTextObject, pos_t, int>> _textObjects;

                std::vector<std::pair<std::string, std::string>> &_graphics;
                std::vector<std::pair<std::string, std::string>> &_games;

                Library<IGraphics> &_graphic;
                Library<IGames> &_game;
                std::string &_graphicName;
                std::string &_gameName;
                std::string &_playerName;

                void _initObjects();
                void _initTextures();
                void _initFontPaths();

                void _setObjectPositionAndScale(const windowParameters_t windowP);

                void _executeEvent(VGameEvent &events);
                void _executeEventName(event::GameEvent &events);
                bool _prompt = false;

                void _moveCursor();
                int _index = 0;

                Category _category;
                void _selectCategory(int next);
                std::array<size_t, 3> _selected;
                void _selectLib(int next);

                void _printScoreboard();
                std::map<std::string, std::multiset<std::pair<std::string, int>, CustomComparator>> &_scoreboard;
                Leaderboard _leaderboard;
        };

        using MenuBackground = ABackground;
        using MenuText = AText;
        using MenuRect = ARect;
    }
}

