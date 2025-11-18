/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-arcade-alexandre.douard
** File description:
** Nibbler.cpp
*/

#include "Nibbler.hpp"

#define ASSET "assets/Nibbler/"

static std::vector<std::string> path = {
    ASSET"wall.png",
    ASSET"apple.png",
    ASSET"head_right.png",
    ASSET"head_down.png",
    ASSET"head_left.png",
    ASSET"head_up.png",
    ASSET"body_horizontal.png",
    ASSET"body_vertical.png",
    ASSET"body_bottomleft.png",
    ASSET"body_topleft.png",
    ASSET"body_topright.png",
    ASSET"body_bottomright.png",
    ASSET"tail_right.png",
    ASSET"tail_down.png",
    ASSET"tail_left.png",
    ASSET"tail_up.png",
};

static std::vector<arcade::AText> text = {
    arcade::AText(0, std::string(" "), {0, 0}, 1, {255, 0, 0, 255}, {255, 0, 0, 255}),
    arcade::AText(0, std::string("o"), {0, 0}, 1, {255, 0, 0, 255}),
    arcade::AText(0, std::string(">"), {0, 0}, 1, {0, 0, 255, 255}),
    arcade::AText(0, std::string("v"), {0, 0}, 1, {0, 255, 0, 255}),
    arcade::AText(0, std::string("<"), {0, 0}, 1, {0, 0, 255, 255}),
    arcade::AText(0, std::string("^"), {0, 0}, 1, {0, 0, 255, 255}),
    arcade::AText(0, std::string("#"), {0, 0}, 1, {0, 255, 0, 255}),
    arcade::AText(0, std::string("#"), {0, 0}, 1, {0, 0, 255, 255}),
    arcade::AText(0, std::string("#"), {0, 0}, 1, {0, 0, 255, 255}),
    arcade::AText(0, std::string("#"), {0, 0}, 1, {0, 0, 255, 255}),
    arcade::AText(0, std::string("#"), {0, 0}, 1, {0, 255, 0, 255}),
    arcade::AText(0, std::string("#"), {0, 0}, 1, {0, 0, 255, 255}),
    arcade::AText(0, std::string("#"), {0, 0}, 1, {0, 0, 255, 255}),
    arcade::AText(0, std::string("#"), {0, 0}, 1, {0, 0, 255, 255}),
    arcade::AText(0, std::string("#"), {0, 0}, 1, {0, 255, 0, 255}),
    arcade::AText(0, std::string("#"), {0, 0}, 1, {0, 0, 255, 255}),
};

namespace arcade {
    Nibbler::Nibbler() : Snake()
    {
    }

    void Nibbler::initGame(const PtrWindowP windowP) {
        _windowParameters = windowP;
        for (int id = 0; id < NB_TEXTURE; id++) {
            PtrTexture texture = std::make_shared<ATexture>(id, path[id], std::make_shared<AText>(text[id]));
            _textures.push_back(texture);
        }
        _fontPaths.push_back("assets/fonts/ITCAvantGardeStd-Demi.ttf");
        addInfo("Score", 0, {255, 255, 255, 255});
        addInfo("Timer", 1000, {255, 255, 100, 255});
        _winBanner.initBanner("You Win !", "R to continue, ESC to return to menu", color_t {255, 255, 51, 255});
        _loseBanner.initBanner("L n00b xD BOZO", "R to restart, ESC to return to menu", color_t {255, 51, 51, 255});
        _pauseBanner.initBanner("Paused", "ESC to continue, R to return to menu", color_t {255, 51, 255, 255});
        restartGame();
    }

    void Nibbler::_loadLevel() {
        _state = State::GAME;
        _size = 0;
        _timer = 1000;
        _start = 5;
        _loadMap(_level);
        _setSize(_row, _col, color_t {30, 144, 255, 255});
        updateInfo("Timer", _timer, *_windowParameters);

        _apple = 0;
        pos_t head = {static_cast<int>(_col) / 2, static_cast<int>(_row) / 2};
        for (size_t i = 0; i < _row; i++) {
            for (size_t j = 0; j < _col; j++) {
                if (_map[j][i] == H_RIGHT)
                    head = {static_cast<int>(j), static_cast<int>(i)};
                else
                    _grid[j][i] = _map[j][i];
                if (_grid[j][i] == APPLE)
                    _apple++;
            }
        }
        _generateSnake(head);
        _turn = _direction;
        _startTick = std::chrono::steady_clock::now();
    }

    void Nibbler::restartGame() {
        _winBanner.isDisplay(false);
        if (_state == State::WIN) {
            _level = (_level + 1) % 32;
            _loadLevel();
            _tickTime = std::chrono::milliseconds(_tickTime - _tickTime / 10);
            return;
        }
        _tickTime = std::chrono::milliseconds(120);
        _score = 0;
        _printedScore = 0;
        _level = 0;
        _loadLevel();
        updateInfo("Score", _printedScore, *_windowParameters);
        _loseBanner.isDisplay(false);
        _pauseBanner.isDisplay(false);
    }

    State Nibbler::execute(VGameEvent &events) {
        _executeEvent(events);
        if (_state == State::MENU || isGameOver() || _state == State::WIN || _state == State::PAUSE)
            return _state;

        std::chrono::steady_clock::time_point currentTick = std::chrono::steady_clock::now();
        if (std::chrono::duration_cast<std::chrono::milliseconds>(currentTick - _startTick) > _tickTime) {
            if (_start)
                _start--;
            else {
                _move();
                if (_state == State::GAME) {
                    _timer -= 5;
                    updateInfo("Timer", _timer, *_windowParameters);
                    if (_timer <= 0) {
                        _state = State::LOSE;
                        _loseBanner.isDisplay(true);
                    }
                }
            }
            _startTick = std::chrono::steady_clock::now();
        }
        return _state;
    }
}
