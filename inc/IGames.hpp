/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** IGames
*/

#pragma once

#include <iostream>
#include <memory>
#include <vector>

#include "IObject.hpp"
#include "Core.hpp"
#include "Event.hpp"

namespace arcade {

    class IGames {
        public:
            virtual ~IGames() = default;

            virtual void initGame() = 0;
            virtual void destroyGame() = 0;
            virtual void restartGame() = 0;
            virtual bool isGameOver() = 0;

            virtual State execute(VGameEvent &event) = 0;
            virtual VPtrTextObject &getTextures() = 0;
            virtual VPtrObject &getObjects() = 0;

            
        private:
    };
}