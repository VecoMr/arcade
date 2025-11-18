    /*
** EPITECH PROJECT, 2024
** arcade
** File description:
** Sfml
*/

#pragma once

#include <SFML/Graphics.hpp>

#include <memory>

#include "IGraphics.hpp"
#include "IObject.hpp"
#include "Event.hpp"

namespace arcade {
    namespace sfml {
        class Sfml : public IGraphics {
            public:
                Sfml();
                ~Sfml();

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

                sf::Color getColor(const color_t &color);

                event::ArcadeEvent getEventsSfml(sf::Event &event);
                arcade::event::keys getKey(sf::Keyboard::Key key);

                std::shared_ptr<sf::RenderWindow> _window;
                std::shared_ptr<sf::View> _view;
                PtrWindowP _windowParameters;

                std::vector<std::shared_ptr<sf::Texture>> _textures;
                std::vector<std::shared_ptr<sf::Font>> _fonts;

                VArcadeEvent _events;
        };
    }
}
