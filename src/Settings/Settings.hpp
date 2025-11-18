/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** Settings
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

#define NB_SET 11

namespace arcade {
    enum class State;
    class IGames;
    class Core;

    namespace settings {

        class Settings : public IGames {
            public:
                enum Category {
                    GRAPHIC,
                    GAME,
                    USERNAME,
                    END
                };

                Settings(std::vector<std::pair<event::ArcadeEvent, event::GameEvent>> &controls);
                ~Settings() = default;

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

                void _initObjects();
                void _initTextures();
                void _initFontPaths();

                void _setObjectPositionAndScale(const windowParameters_t windowP);

                void _executeEvent(VGameEvent &events);

                void _beginPrompt();
                void _executePromptEvent(event::GameEvent &events);

                std::vector<std::pair<event::ArcadeEvent, event::GameEvent>> &_controls;
                const std::vector<std::pair<event::ArcadeEvent, event::GameEvent>> _default;

                int _index;
                void _resetCursor();
                void _moveCursor(bool next);

                bool _prompt = false;

                void _resetControl();
        };

        using SettingsBackground = ABackground;
        using SettingsText = AText;
        using SettingsRect = ARect;
    }
}

