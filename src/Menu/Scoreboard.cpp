/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-arcade-alexandre.douard
** File description:
** Scoreboard.cpp
*/

#include "Menu.hpp"

namespace arcade::menu {
    void Menu::_printScoreboard() {
        std::string gameName = _games[_selected[GAME]].second;
        size_t i = 1;
        for (auto [name, score] : _scoreboard[gameName]) {
            if (i > 9)
                break;
            _leaderboard.updateLeaderboard(i, name, score);
            i++;
        }
        for (; i <= 9; i++)
            _leaderboard.updateLeaderboard(i, defaultName, 0);
    }

    Leaderboard::Leaderboard() {
        shape_t shape {420, 30, 370, 500};
        pos_t pos {0, 0};

        _rectObjects.first.first = std::make_shared<ARect>(shape, color_t {255, 255, 255, 255}, pos);
        _rectObjects.first.second = shape;
        shape = {shape.x + 5, shape.y + 5, shape.width - 10, shape.height - 10};
        _rectObjects.second.first = std::make_shared<ARect>(shape, color_t {0, 0, 0, 255}, pos);
        _rectObjects.second.second = shape;
        _objects.push_back(_rectObjects.first.first);
        _objects.push_back(_rectObjects.second.first);

        pos.x = 440;
        pos.y = 50;
        PtrTextObject text = std::make_shared<AText>(0, "Leaderboard", pos, 40, color_t {255, 255, 255, 255});
        _textObjects.push_back(std::make_tuple(text, pos, 50));
        _objects.push_back(text);

        pos.y += 70;
        pos.x += 30;
        for (size_t i = 1; i < 10; i++) {
            color_t color = {rand() % 255, rand() % 255, rand() % 255, 255};
            text = std::make_shared<AText>(0, defaultName, pos, 30, color);
            _textObjects.push_back(std::make_tuple(text, pos, 30));
            _objects.push_back(text);
            pos.x += 230;
            text = std::make_shared<AText>(0, "xxx", pos, 30, color);
            _textObjects.push_back(std::make_tuple(text, pos, 30));
            _objects.push_back(text);
            pos.y += 45;
            pos.x -= 230;
        }

        isDisplay(false);
    }

    VPtrObject &Leaderboard::getObjects() {
        return _objects;
    }

    void Leaderboard::setObjectPositionAndScale(const windowParameters_t windowP) {
        float xScale = windowP.width / DEF_WIDTH;
        float yScale = windowP.height / DEF_HEIGHT;

        shape_t shape = _rectObjects.first.second;

        _rectObjects.first.first->setPos({(int)(xScale * shape.x), (int)(yScale * shape.y)});
        _rectObjects.first.first->setBounds({0, 0, (int)(xScale * shape.width), (int)(yScale * shape.height)});

        shape = _rectObjects.second.second;
        _rectObjects.second.first->setPos({(int)(xScale * shape.x), (int)(yScale * shape.y)});
        _rectObjects.second.first->setBounds({0, 0, (int)(xScale * shape.width), (int)(yScale * shape.height)});

        for (auto &[text, pos, size] : _textObjects) {
            float xNewPos = pos.x * xScale;
            float yNewPos = pos.y * yScale;
            text->setPos({(int)xNewPos, (int)yNewPos});
            text->setSize(size * yScale);
        }
    }

    void Leaderboard::isDisplay(const bool display) {
        for (auto &object : _objects)
            object->isDisplay(display);
    }

    void Leaderboard::updateLeaderboard(size_t line, std::string name, int score) {
        line--;
        std::get<0>(_textObjects[1 + line * 2])->setContent(name);
        std::get<0>(_textObjects[1 + line * 2 + 1])->setContent(score ? std::to_string(score) : "xxx");
    }
}