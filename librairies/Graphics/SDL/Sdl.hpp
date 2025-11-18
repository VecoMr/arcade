/*
** EPITECH PROJECT, 2024
** B-OOP-400-LYN-4-1-arcade-alexandre.douard
** File description:
** Sdl
*/


#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <functional>
#include <limits>

#include "IGraphics.hpp"


namespace arcade {
    namespace sdl2 {
        class Sdl2 : public IGraphics {
            public:
                Sdl2();
                ~Sdl2();

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

                SDL_Color getColor(const color_t &color) const;
                event::ArcadeEvent getEventsSdl(SDL_Event &event);
                event::keys getKey(SDL_Keycode key);

                std::unique_ptr<SDL_Window, decltype(&SDL_DestroyWindow)> _window = {nullptr, &SDL_DestroyWindow};
                std::unique_ptr<SDL_Renderer, decltype(&SDL_DestroyRenderer)> _renderer  = {nullptr, &SDL_DestroyRenderer};
                PtrWindowP _windowParameters;

                std::vector<std::shared_ptr<SDL_Texture>> _textures;
                std::vector<std::shared_ptr<TTF_Font>> _fonts;

                VArcadeEvent _events;
        };
    }
}
