/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** Sfml
*/

#include "Sfml.hpp"

namespace arcade {
    namespace sfml {
        Sfml::Sfml()
        : _window(), _view(), _windowParameters(nullptr), _textures(), _fonts(), _events()
        {
        }

        Sfml::~Sfml()
        {
        }

        void Sfml::initWindow(const PtrWindowP windowP) {
            _windowParameters = windowP;
            this->_window = std::make_shared<sf::RenderWindow>(sf::VideoMode(this->_windowParameters->width, this->_windowParameters->height), this->_windowParameters->title);
            this->_view = std::make_shared<sf::View>(_window->getDefaultView());
            this->_window->setFramerateLimit(this->_windowParameters->fps);
            this->clearWindow({0, 0, 0, 255});
            this->_window->display();
        }

        void Sfml::destroyWindow() {
            this->_window->close();
        }

        void Sfml::clearWindow(const color_t &color) {
            this->_window->clear(sf::Color(color.r, color.g, color.b, color.a));
        }

        bool Sfml::isOpen() const {
            return this->_window->isOpen();
        }

        void Sfml::setWindowParameters(windowParameters_t &windowParameters) {
            *_windowParameters = windowParameters;
        }

        windowParameters_t &Sfml::getWindowParameters() {
            return *_windowParameters;
        }

        void Sfml::setWindowWidth(int width) {
            this->_windowParameters->width = width;
        }

        void Sfml::setWindowHeight(int height) {
            this->_windowParameters->height = height;
        }

        void Sfml::setWindowTitle(std::string &title) {
            this->_windowParameters->title = title;
        }

        int &Sfml::getWindowWidth() {
            return this->_windowParameters->width;
        }

        int &Sfml::getWindowHeight() {
            return this->_windowParameters->height;
        }

        std::string &Sfml::getWindowTitle() {
            return this->_windowParameters->title;
        }

        VArcadeEvent &Sfml::getEvents() {
            this->_events.clear();
            for (sf::Event event; this->_window->pollEvent(event);) {
                this->_events.push_back(this->getEventsSfml(event));
            }
            return _events;
        }

        void Sfml::loadTextures(const VPtrTexture &textures) {
            std::shared_ptr<sf::Texture> PtrTexture;

            this->_textures.clear();
            for (auto &texture : textures) {
                PtrTexture = std::make_shared<sf::Texture>();
                if (!PtrTexture->loadFromFile(texture->getTexturePath())) {
                    std::cerr << texture->getTexturePath() << ": Texture not found." << std::endl;
                    continue;
                }
                this->_textures.push_back(PtrTexture);
            }
        }

        void Sfml::loadFonts(const std::vector<std::string> &fonts) {
            this->_fonts.clear();
            for (auto &font : fonts) {
                std::shared_ptr<sf::Font> PtrFont = std::make_shared<sf::Font>();
                if (!PtrFont->loadFromFile(font)) {
                    std::cerr << font << ": Font not found." << std::endl;
                    continue;
                }
                this->_fonts.push_back(PtrFont);
            }
        }

        sf::Color Sfml::getColor(const color_t &color) {
            return sf::Color(color.r, color.g, color.b, color.a);
        }

        event::ArcadeEvent Sfml::getEventsSfml(sf::Event &event) {
            event::ArcadeEvent arcadeEvent;
            switch (event.type) {
                case sf::Event::Closed:
                    arcadeEvent.type = event::EventType::WINDOW;
                    arcadeEvent.evWindow.type = arcade::event::window::type::CLOSE;
                    break;
                case sf::Event::Resized:
                    arcadeEvent.type = event::EventType::WINDOW;
                    arcadeEvent.evWindow.type = arcade::event::window::type::RESIZE;
                    arcadeEvent.evWindow.width = event.size.width;
                    arcadeEvent.evWindow.height = event.size.height;
                    break;
                case sf::Event::GainedFocus:
                    arcadeEvent.type = event::EventType::WINDOW;
                    arcadeEvent.evWindow.type = arcade::event::window::type::FOCUS;
                    break;
                case sf::Event::LostFocus:
                    arcadeEvent.type = event::EventType::WINDOW;
                    arcadeEvent.evWindow.type = arcade::event::window::type::LOSTFOCUS;
                    break;
                case sf::Event::KeyPressed:
                    arcadeEvent.type = event::EventType::KEYBOARD;
                    arcadeEvent.evKey.type = arcade::event::Type::PRESSED;
                    arcadeEvent.evKey.key = this->getKey(event.key.code);
                    break;
                default:
                    arcadeEvent.type = event::EventType::NONE;
                    break;
            }
            return arcadeEvent;
        }
    }
}

extern "C" arcade::sfml::Sfml *createLib()
{
    return new arcade::sfml::Sfml();
}

extern "C" arcade::LibType getType()
{
    return arcade::LibType::GRAPHIC;
}

extern "C" std::string getName()
{
    return std::string("SFML");
}
