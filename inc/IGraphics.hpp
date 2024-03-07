/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** IGraphics
*/

#pragma once

#include <iostream>

#include "IObject.hpp"
#include "Event.hpp"

namespace arcade {

    typedef struct {
        int width;
        int height;
        std::string title;
        float soundVolume;
        int fps;
        int tps;
    } windowParameters_t;

    class IGraphics {
        public:
            virtual ~IGraphics() = default;

            virtual void initWindow() = 0;
            virtual void destroyWindow() = 0;
            virtual void clearWindow() = 0;
            virtual bool isOpen() = 0;

            virtual void setWindowParameters(windowParameters_t windowParameters) = 0;
            virtual windowParameters_t getWindowParameters() = 0;

            virtual void setWindowWidth(int width) = 0;
            virtual void setWindowHeight(int height) = 0;
            virtual void setWindowTitle(std::string title) = 0;
            virtual int getWindowWidth() = 0;
            virtual int getWindowHeight() = 0;
            virtual std::string getWindowTitle() = 0;

            virtual VAcradeEvent &getEvents() = 0;

            virtual void loadTextures(VPtrTexture &textures) = 0;
            virtual void displayObjects(VPtrObject &objects) = 0;

        private:
            virtual void displayTexts(PtrObject &objects) = 0;
            virtual void displaySprites(PtrObject &objects) = 0;
    };
}
