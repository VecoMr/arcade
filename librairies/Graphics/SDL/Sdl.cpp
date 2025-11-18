/*
** EPITECH PROJECT, 2024
** B-OOP-400-LYN-4-1-arcade-alexandre.douard
** File description:
** Sdl
*/

#include "Sdl.hpp"

namespace arcade {
    namespace sdl2 {
        Sdl2::Sdl2() : _windowParameters() {}

        Sdl2::~Sdl2() {
            destroyWindow();
            SDL_Quit();
        }

        void Sdl2::initWindow(const PtrWindowP windowP) {
            if (_window.get()) {
                destroyWindow();
            }
            _windowParameters = windowP;
            if (SDL_Init(SDL_INIT_VIDEO) < 0) {
                throw std::runtime_error(std::string("SDL_Init Error: ") + SDL_GetError());
            }
            if (TTF_Init() < 0) {
                throw std::runtime_error(std::string("TTF_Init Error: ") + TTF_GetError());
            }
            _window.reset(SDL_CreateWindow(_windowParameters->title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, _windowParameters->width, _windowParameters->height, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE));
            if (!_window.get()) {
                throw std::runtime_error(std::string("SDL_CreateWindow Error: ") + SDL_GetError());
            }
            _renderer.reset(SDL_CreateRenderer(_window.get(), -1, SDL_RENDERER_SOFTWARE));
            if (!_renderer.get()) {
                throw std::runtime_error(std::string("SDL_CreateRenderer Error: ") + SDL_GetError());
            }
        }

        void Sdl2::destroyWindow() {
            _window.reset();
        }

        void Sdl2::clearWindow(const color_t &color) {
            SDL_SetRenderDrawColor(_renderer.get(), (Uint8) color.r, (Uint8) color.g, (Uint8) color.b, (Uint8) color.a);
            SDL_RenderClear(_renderer.get());
        }

        bool Sdl2::isOpen() const {
            return _window.get();
        }

        void Sdl2::setWindowParameters(windowParameters_t &windowParameters) {
            _windowParameters = std::make_shared<windowParameters_t>(windowParameters);
        }

        windowParameters_t &Sdl2::getWindowParameters() {
            return *_windowParameters;
        }

        void Sdl2::setWindowWidth(int width) {
            _windowParameters->width = width;
        }

        void Sdl2::setWindowHeight(int height) {
            _windowParameters->height = height;
        }

        void Sdl2::setWindowTitle(std::string &title) {
            _windowParameters->title = title;
        }

        int &Sdl2::getWindowWidth() {
            return _windowParameters->width;
        }

        int &Sdl2::getWindowHeight() {
            return _windowParameters->height;
        }

        std::string &Sdl2::getWindowTitle() {
            return _windowParameters->title;
        }

        VArcadeEvent &Sdl2::getEvents() {
            _events.clear();
            SDL_Event event;
            while (SDL_PollEvent(&event)) {
                _events.push_back(getEventsSdl(event));
            }
            return _events;
        }

        event::ArcadeEvent Sdl2::getEventsSdl(SDL_Event &event) {
            event::ArcadeEvent arcadeEvent;
            switch (event.type) {
                case SDL_QUIT:
                    arcadeEvent.type = event::EventType::WINDOW;
                    arcadeEvent.evWindow.type = event::window::type::CLOSE;
                    break;
                case SDL_WINDOWEVENT:
                    arcadeEvent.type = event::EventType::WINDOW;
                    if (event.window.event == SDL_WINDOWEVENT_RESIZED) {
                        arcadeEvent.evWindow.type = arcade::event::window::type::RESIZE;
                    } else
                        arcadeEvent.evWindow.type = arcade::event::window::type::FOCUS;
                    arcadeEvent.type = event::EventType::WINDOW;
                    arcadeEvent.evWindow.width = event.window.data1;
                    arcadeEvent.evWindow.height = event.window.data2;
                    break;
                case SDL_KEYDOWN:
                    arcadeEvent.type = event::EventType::KEYBOARD;
                    arcadeEvent.evKey.type = event::Type::PRESSED;
                    arcadeEvent.evKey.key = getKey(event.key.keysym.sym);
                    break;
                case SDL_KEYUP:
                    arcadeEvent.type = event::EventType::KEYBOARD;
                    arcadeEvent.evKey.type = event::Type::RELEASED;
                    arcadeEvent.evKey.key = getKey(event.key.keysym.sym);
                    break;
                case SDL_MOUSEBUTTONDOWN:
                    arcadeEvent.type = event::EventType::MOUSE;
                    arcadeEvent.evMouse.type = event::Type::PRESSED;
                    arcadeEvent.evMouse.x = event.button.x;
                    arcadeEvent.evMouse.y = event.button.y;
                    break;
                case SDL_MOUSEBUTTONUP:
                    arcadeEvent.type = event::EventType::MOUSE;
                    arcadeEvent.evMouse.type = event::Type::RELEASED;
                    arcadeEvent.evMouse.x = event.button.x;
                    arcadeEvent.evMouse.y = event.button.y;
                    break;
                default:
                    arcadeEvent.type = event::EventType::NONE;
                    break;
            }
            return arcadeEvent;
        }

        void Sdl2::loadTextures(const VPtrTexture &textures) {
            this->_textures.clear();
            for (const auto& texturePath : textures) {
                std::shared_ptr<SDL_Texture> texture(IMG_LoadTexture(_renderer.get(), texturePath->getTexturePath().c_str()), SDL_DestroyTexture);
                if (!texture.get()) {
                    throw std::runtime_error(std::string("IMG_LoadTexture Error: ") + IMG_GetError());
                }
                _textures.push_back(texture);
            }
        }

        void Sdl2::loadFonts(const std::vector<std::string> &fonts) {
            this->_fonts.clear();
            for (const auto& fontPath : fonts) {
                std::shared_ptr<TTF_Font> font(TTF_OpenFont(fontPath.c_str(), 24), [](TTF_Font* font) {TTF_CloseFont(font);});
                if (!font.get()) {
                    throw std::runtime_error(std::string("TTF_OpenFont Error: ") + TTF_GetError());
                }
                _fonts.push_back(font);
            }
        }

        void Sdl2::displayObjects(const VPtrObject &objects) {
            this->clearWindow({0, 0, 0, 255});
            for (auto &object : objects) {
                if (!object->isDisplay())
                    continue;
                switch (object->getType()) {
                    case ObjectType::TEXT:
                    {
                        auto textObject = std::dynamic_pointer_cast<ITextObject>(object);
                        this->displayTexts(textObject);
                        break;
                    }
                    case ObjectType::SPRITE:
                    {
                        auto spriteObject = std::dynamic_pointer_cast<ISpriteObject>(object);
                        this->displaySprites(spriteObject);
                        break;
                    }
                    case ObjectType::BACKGROUND:
                    {
                        auto backgroundObject = std::dynamic_pointer_cast<IBackground>(object);
                        this->clearWindow(backgroundObject->getColor());
                        break;
                    }
                    case ObjectType::RECT:
                    {
                        auto rect = std::dynamic_pointer_cast<IRect>(object);
                        this->displayRect(rect);
                        break;
                    }
                }
            }
            SDL_RenderPresent(_renderer.get());
        }

        void Sdl2::displayTexts(const PtrTextObject &obj) {
            SDL_Color color = getColor(obj->getColor());
            std::unique_ptr<SDL_Surface, decltype(&SDL_FreeSurface)> surface(
                TTF_RenderText_Solid(_fonts[obj->getIdFontFamily()].get(), obj->getContent().c_str(), color),
                &SDL_FreeSurface
            );
            std::unique_ptr<SDL_Texture, decltype(&SDL_DestroyTexture)> texture(
                SDL_CreateTextureFromSurface(_renderer.get(), surface.get()),
                &SDL_DestroyTexture
            );

            float wScale = surface->w * obj->getSize() / 25;
            float hScale = surface->h * obj->getSize() / 25;

            SDL_Rect src = {0, 0, surface->w, surface->h};
            SDL_Rect dest = {obj->getPos().x, obj->getPos().y, (int)wScale, (int)hScale};

            obj->setBounds({dest.x, dest.y, dest.w, dest.h});

            if (obj->getBackGroundColor().a != 0) {
                SDL_Rect bgRect = {dest.x, dest.y, dest.w, dest.h};
                SDL_SetRenderDrawColor(_renderer.get(), obj->getBackGroundColor().r, obj->getBackGroundColor().g, obj->getBackGroundColor().b, obj->getBackGroundColor().a);
                SDL_RenderFillRect(_renderer.get(), &bgRect);
            }
            SDL_RenderCopy(_renderer.get(), texture.get(), &src, &dest);
        }

        void Sdl2::displaySprites(const PtrSpriteObject &obj) {
            int width;
            int height;
            SDL_QueryTexture(_textures[obj->getIdTexture()].get(), NULL, NULL, &width, &height);
            SDL_Rect src = {0, 0, width, height};
            SDL_Rect dest = {obj->getPos().x, obj->getPos().y, obj->getShape().width, obj->getShape().height};
            SDL_RenderCopy(_renderer.get(), _textures[obj->getIdTexture()].get(), &src, &dest);
        }

        void Sdl2::displayRect(const PtrRect &obj) {
            SDL_Rect rect = {obj->getPos().x, obj->getPos().y, obj->getShape().width, obj->getShape().height};
            SDL_SetRenderDrawColor(_renderer.get(), obj->getColor().r, obj->getColor().g, obj->getColor().b, obj->getColor().a);
            SDL_RenderFillRect(_renderer.get(), &rect);
        }

        SDL_Color Sdl2::getColor(const arcade::color_t &color) const {
            return {(Uint8) color.r, (Uint8) color.g, (Uint8) color.b, (Uint8) color.a};
        }

    }
}

extern "C" arcade::sdl2::Sdl2 *createLib()
{
    return new arcade::sdl2::Sdl2();
}

extern "C" arcade::LibType getType()
{
    return arcade::LibType::GRAPHIC;
}

extern "C" std::string getName()
{
    return std::string("SDL2");
}
