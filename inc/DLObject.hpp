/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** DLObject
*/

#pragma once

#include <iostream>
#include <dlfcn.h>
#include <memory>
#include <functional>

#include "ErrorHandling.hpp"
#include "Library.hpp"

namespace arcade {
    class DLObject {
        public:
            DLObject(std::string const &path);
            ~DLObject() = default;

            template <typename T>
            Library<T> getInst(const std::string &func);

            template <typename T, class... Args>
            T getCall(const std::string &func, Args ...args);

        protected:
        private:
            std::shared_ptr<void> _lib;
    };

    template <typename T>
    Library<T> DLObject::getInst(const std::string &func) {
        if (!this->_lib)
            throw ErrorH(func + ": didn't have a valid lib");
        return Library<T>(this->_lib, func);
    }

    template <typename T, class... Args>
    T DLObject::getCall(const std::string &func, Args ...args) {
        if (!this->_lib)
            throw ErrorH(func + ": didn't have a valid lib");
        auto f = reinterpret_cast<T(*)()>(dlsym(this->_lib.get(), func.c_str()));
        if (!f)
            throw ErrorH(func + ": didn't have a valid function");
        return f();
    }
}
