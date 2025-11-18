/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-arcade-alexandre.douard
** File description:
** ABanner.cpp
*/

#include "ABanner.hpp"

namespace arcade {
    ABanner::ABanner() {
    }

    void ABanner::initBanner(std::string title, std::string description, color_t background) {
        shape_t shape {0, 0, 0, 0};
        pos_t pos {0, 0};

        _rectObjects.first = std::make_shared<ARect>(shape, background, pos);
        _rectObjects.second = std::make_shared<ARect>(shape, color_t {0, 0, 0, 150}, pos);
        _objects.push_back(_rectObjects.first);
        _objects.push_back(_rectObjects.second);

        pos.x = 30;
        pos.y = DEF_HEIGHT / 2 - 40;
        PtrTextObject text = std::make_shared<AText>(0, title, pos, 50, background);
        _textObjects.push_back(std::make_tuple(text, pos, 50));
        _objects.push_back(text);

        pos.x = 40;
        pos.y = DEF_HEIGHT / 2 + 20;
        text = std::make_shared<AText>(0, description, pos, 20, background);
        _textObjects.push_back(std::make_tuple(text, pos, 20));
        _objects.push_back(text);
        isDisplay(false);
    }

    VPtrObject &ABanner::getObjects() {
        return _objects;
    }

    void ABanner::setObjectPositionAndScale(const windowParameters_t windowP) {
        _rectObjects.first->setPos({0, windowP.height / 3});
        _rectObjects.first->setBounds({0, 0, windowP.width, windowP.height / 3});

        _rectObjects.second->setPos({0, windowP.height / 3 + 10});
        _rectObjects.second->setBounds({0, 0, windowP.width, windowP.height / 3 - 20});

        float xScale = windowP.width / DEF_WIDTH;
        float yScale = windowP.height / DEF_HEIGHT;

        for (auto &[text, pos, size] : _textObjects) {
            float xNewPos = pos.x * xScale;
            float yNewPos = pos.y * yScale;
            text->setPos({(int)xNewPos, (int)yNewPos});
            text->setSize(size * yScale);
        }
    }

    void ABanner::isDisplay(const bool display) {
        for (auto &object : _objects)
            object->isDisplay(display);
    }
}