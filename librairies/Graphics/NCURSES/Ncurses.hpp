/*
** EPITECH PROJECT, 2024
** B-OOP-400-LYN-4-1-arcade-alexandre.douard
** File description:
** Ncurses
*/

#pragma once

#include "IGraphics.hpp"
#include <ncurses.h>

namespace arcade {
    namespace ncurses {
        struct NcursesTexture {
            int id;
            std::string str;
            color_t color;
            color_t backColor;
        };

        class Ncurses : public IGraphics {
            public:
                Ncurses();
                ~Ncurses();

                void initWindow(const PtrWindowP windowP) override;
                void destroyWindow() override;
                void clearWindow(const color_t &color = defBackColor) override;
                bool isOpen() const override;

                void setWindowParameters(windowParameters_t &windowParameters) override;
                windowParameters_t &getWindowParameters() override;

                void setWindowWidth(int width) override;
                void setWindowHeight(int height) override;
                void setWindowTitle(std::string &title) override;
                int &getWindowWidth() override;
                int &getWindowHeight() override;
                std::string &getWindowTitle() override;

                VArcadeEvent &getEvents() override;

                void loadTextures(const VPtrTexture &textures) override;
                void loadFonts(const std::vector<std::string> &fonts) override;
                void displayObjects(const VPtrObject &objects) override;

            private:
                void displayTexts(const PtrTextObject &objects) override;
                void displaySprites(const PtrSpriteObject &objects) override;
                void displayRect(const PtrRect &objects) override;

                chtype getColor(const color_t &color) const;
                event::ArcadeEvent getEventsNcurses(int &ch);

                chtype getTexture(const ITexture &texture) const;

                void getWindowDimensions();
                void getWindowDimensions(int &width, int &height);

                int getWidth(int x) const;
                int getHeight(int y) const;

                void incPair();

                WINDOW *_window;
                PtrWindowP _windowParameters;

                std::vector<NcursesTexture> _textures;

                VArcadeEvent _events;
                int _height;
                int _width;
                chtype _defBackColor;
                int _pair;
        };
    }
}
