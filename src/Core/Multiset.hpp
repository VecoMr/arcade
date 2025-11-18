/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-arcade-alexandre.douard
** File description:
** Custom.hpp
*/

#pragma once

#include <string>

struct CustomComparator {
    bool operator()(const std::pair<std::string, int>& pair1, const std::pair<std::string, int>& pair2) const {
        return pair1.second > pair2.second;
    }
};
