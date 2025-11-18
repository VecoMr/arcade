/*
** EPITECH PROJECT, 2024
** B-OOP-400-LYN-4-1-arcade-alexandre.douard
** File description:
** DLObject
*/

#include "DLObject.hpp"

namespace arcade {
    DLObject::DLObject(const std::string &path)
    : _lib(dlopen(path.c_str(), RTLD_LAZY), [](void *lib) {
        if (lib && dlclose(lib)) {
            throw ErrorH(dlerror());
        }
    }) {
        if (!this->_lib.get())
            throw ErrorH(path + ": " + dlerror());
    }
}