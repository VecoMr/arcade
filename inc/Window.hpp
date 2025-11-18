/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-arcade-alexandre.douard
** File description:
** Window.hpp
*/

#pragma once

#include <string>
#include <memory>

#define DEF_WIDTH 800.0
#define DEF_HEIGHT 600.0

namespace arcade {
    typedef struct windowParameters_s {
        int width;
        int height;
        std::string title;
        float soundVolume;
        int fps;
        int tps;
    } windowParameters_t;

    using PtrWindowP = std::shared_ptr<windowParameters_t>;
}
