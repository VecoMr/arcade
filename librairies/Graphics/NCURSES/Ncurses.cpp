/*
** EPITECH PROJECT, 2024
** B-OOP-400-LYN-4-1-arcade-alexandre.douard
** File description:
** Ncurses
*/

#include "Ncurses.hpp"
#include <functional>


namespace arcade {
    namespace ncurses {
        Ncurses::Ncurses() : _windowParameters(nullptr), _defBackColor(' '), _pair(1){
            _window = newwin(0, 0, 0, 0);
        }

        Ncurses::~Ncurses() {
            endwin();
        }

        void Ncurses::initWindow(const PtrWindowP windowP) {
            _windowParameters = windowP;
            initscr();
            raw();
            keypad(stdscr, TRUE);
            noecho();
            nodelay(stdscr, TRUE);
            curs_set(0);
            start_color();
        }

        void Ncurses::destroyWindow() {
        }

        void Ncurses::clearWindow(const color_t &color) {
            init_pair(_pair, COLOR_BLACK, getColor(color));
            _defBackColor = ' ' | COLOR_PAIR(1);
            attron(COLOR_PAIR(_pair));
            for (int y = 0; y < LINES; y++) {
                for (int x = 0; x < COLS; x++) {
                    mvaddch(y, x, _defBackColor);
                }
            }
            attroff(COLOR_PAIR(_pair));
            incPair();
        }

        bool Ncurses::isOpen() const {
            return _window != nullptr;
        }

        void Ncurses::setWindowParameters(windowParameters_t &windowParameters) {
            _windowParameters = std::make_shared<windowParameters_t>(windowParameters);
        }

        windowParameters_t &Ncurses::getWindowParameters() {
            return *_windowParameters;
        }

        void Ncurses::setWindowWidth(int width) {
            _windowParameters->width = width;
        }

        void Ncurses::setWindowHeight(int height) {
            _windowParameters->height = height;
        }

        void Ncurses::setWindowTitle(std::string &title) {
            _windowParameters->title = title;
        }

        int &Ncurses::getWindowWidth() {
            return _windowParameters->width;
        }

        int &Ncurses::getWindowHeight() {
            return _windowParameters->height;
        }

        std::string &Ncurses::getWindowTitle() {
            return _windowParameters->title;
        }

        VArcadeEvent &Ncurses::getEvents() {
            _events.clear();
            int ch = getch();
            _events.push_back(getEventsNcurses(ch));
            return _events;
        }

        event::ArcadeEvent Ncurses::getEventsNcurses(int &ch) {
            event::ArcadeEvent arcadeEvent;
            switch (ch) {
                case 27:
                case KEY_EXIT:
                    arcadeEvent.type = event::EventType::KEYBOARD;
                    arcadeEvent.evKey.type = event::Type::PRESSED;
                    arcadeEvent.evKey.key = event::keys::ESCAPE;
                    return arcadeEvent;
                case KEY_UP:
                    arcadeEvent.type = event::EventType::KEYBOARD;
                    arcadeEvent.evKey.type = event::Type::PRESSED;
                    arcadeEvent.evKey.key = event::keys::UP;
                    return arcadeEvent;
                case KEY_DOWN:
                    arcadeEvent.type = event::EventType::KEYBOARD;
                    arcadeEvent.evKey.type = event::Type::PRESSED;
                    arcadeEvent.evKey.key = event::keys::DOWN;
                    return arcadeEvent;
                case KEY_LEFT:
                    arcadeEvent.type = event::EventType::KEYBOARD;
                    arcadeEvent.evKey.type = event::Type::PRESSED;
                    arcadeEvent.evKey.key = event::keys::LEFT;
                    return arcadeEvent;
                case KEY_RIGHT:
                    arcadeEvent.type = event::EventType::KEYBOARD;
                    arcadeEvent.evKey.type = event::Type::PRESSED;
                    arcadeEvent.evKey.key = event::keys::RIGHT;
                    return arcadeEvent;
                case ' ':
                    arcadeEvent.type = event::EventType::KEYBOARD;
                    arcadeEvent.evKey.type = event::Type::PRESSED;
                    arcadeEvent.evKey.key = event::keys::SPACE;
                    return arcadeEvent;
                case 'A':
                case 'a':
                    arcadeEvent.type = event::EventType::KEYBOARD;
                    arcadeEvent.evKey.type = event::Type::PRESSED;
                    arcadeEvent.evKey.key = event::keys::A;
                    return arcadeEvent;
                case 'B':
                case 'b':
                    arcadeEvent.type = event::EventType::KEYBOARD;
                    arcadeEvent.evKey.type = event::Type::PRESSED;
                    arcadeEvent.evKey.key = event::keys::B;
                    return arcadeEvent;
                case 'C':
                case 'c':
                    arcadeEvent.type = event::EventType::KEYBOARD;
                    arcadeEvent.evKey.type = event::Type::PRESSED;
                    arcadeEvent.evKey.key = event::keys::C;
                    return arcadeEvent;
                case 'D':
                case 'd':
                    arcadeEvent.type = event::EventType::KEYBOARD;
                    arcadeEvent.evKey.type = event::Type::PRESSED;
                    arcadeEvent.evKey.key = event::keys::D;
                    return arcadeEvent;
                case 'E':
                case 'e':
                    arcadeEvent.type = event::EventType::KEYBOARD;
                    arcadeEvent.evKey.type = event::Type::PRESSED;
                    arcadeEvent.evKey.key = event::keys::E;
                    return arcadeEvent;
                case 'F':
                case 'f':
                    arcadeEvent.type = event::EventType::KEYBOARD;
                    arcadeEvent.evKey.type = event::Type::PRESSED;
                    arcadeEvent.evKey.key = event::keys::F;
                    return arcadeEvent;
                case 'G':
                case 'g':
                    arcadeEvent.type = event::EventType::KEYBOARD;
                    arcadeEvent.evKey.type = event::Type::PRESSED;
                    arcadeEvent.evKey.key = event::keys::G;
                    return arcadeEvent;
                case 'H':
                case 'h':
                    arcadeEvent.type = event::EventType::KEYBOARD;
                    arcadeEvent.evKey.type = event::Type::PRESSED;
                    arcadeEvent.evKey.key = event::keys::H;
                    return arcadeEvent;
                case 'I':
                case 'i':
                    arcadeEvent.type = event::EventType::KEYBOARD;
                    arcadeEvent.evKey.type = event::Type::PRESSED;
                    arcadeEvent.evKey.key = event::keys::I;
                    return arcadeEvent;
                case 'J':
                case 'j':
                    arcadeEvent.type = event::EventType::KEYBOARD;
                    arcadeEvent.evKey.type = event::Type::PRESSED;
                    arcadeEvent.evKey.key = event::keys::J;
                    return arcadeEvent;
                case 'K':
                case 'k':
                    arcadeEvent.type = event::EventType::KEYBOARD;
                    arcadeEvent.evKey.type = event::Type::PRESSED;
                    arcadeEvent.evKey.key = event::keys::K;
                    return arcadeEvent;
                case 'L':
                case 'l':
                    arcadeEvent.type = event::EventType::KEYBOARD;
                    arcadeEvent.evKey.type = event::Type::PRESSED;
                    arcadeEvent.evKey.key = event::keys::L;
                    return arcadeEvent;
                case 'M':
                case 'm':
                    arcadeEvent.type = event::EventType::KEYBOARD;
                    arcadeEvent.evKey.type = event::Type::PRESSED;
                    arcadeEvent.evKey.key = event::keys::M;
                    return arcadeEvent;
                case 'N':
                case 'n':
                    arcadeEvent.type = event::EventType::KEYBOARD;
                    arcadeEvent.evKey.type = event::Type::PRESSED;
                    arcadeEvent.evKey.key = event::keys::N;
                    return arcadeEvent;
                case 'O':
                case 'o':
                    arcadeEvent.type = event::EventType::KEYBOARD;
                    arcadeEvent.evKey.type = event::Type::PRESSED;
                    arcadeEvent.evKey.key = event::keys::O;
                    return arcadeEvent;
                case 'P':
                case 'p':
                    arcadeEvent.type = event::EventType::KEYBOARD;
                    arcadeEvent.evKey.type = event::Type::PRESSED;
                    arcadeEvent.evKey.key = event::keys::P;
                    return arcadeEvent;
                case 'Q':
                case 'q':
                    arcadeEvent.type = event::EventType::KEYBOARD;
                    arcadeEvent.evKey.type = event::Type::PRESSED;
                    arcadeEvent.evKey.key = event::keys::Q;
                    return arcadeEvent;
                case 'R':
                case 'r':
                    arcadeEvent.type = event::EventType::KEYBOARD;
                    arcadeEvent.evKey.type = event::Type::PRESSED;
                    arcadeEvent.evKey.key = event::keys::R;
                    return arcadeEvent;
                case 'S':
                case 's':
                    arcadeEvent.type = event::EventType::KEYBOARD;
                    arcadeEvent.evKey.type = event::Type::PRESSED;
                    arcadeEvent.evKey.key = event::keys::S;
                    return arcadeEvent;
                case 'T':
                case 't':
                    arcadeEvent.type = event::EventType::KEYBOARD;
                    arcadeEvent.evKey.type = event::Type::PRESSED;
                    arcadeEvent.evKey.key = event::keys::T;
                    return arcadeEvent;
                case 'U':
                case 'u':
                    arcadeEvent.type = event::EventType::KEYBOARD;
                    arcadeEvent.evKey.type = event::Type::PRESSED;
                    arcadeEvent.evKey.key = event::keys::U;
                    return arcadeEvent;
                case 'V':
                case 'v':
                    arcadeEvent.type = event::EventType::KEYBOARD;
                    arcadeEvent.evKey.type = event::Type::PRESSED;
                    arcadeEvent.evKey.key = event::keys::V;
                    return arcadeEvent;
                case 'W':
                case 'w':
                    arcadeEvent.type = event::EventType::KEYBOARD;
                    arcadeEvent.evKey.type = event::Type::PRESSED;
                    arcadeEvent.evKey.key = event::keys::W;
                    return arcadeEvent;
                case 'X':
                case 'x':
                    arcadeEvent.type = event::EventType::KEYBOARD;
                    arcadeEvent.evKey.type = event::Type::PRESSED;
                    arcadeEvent.evKey.key = event::keys::X;
                    return arcadeEvent;
                case 'Y':
                case 'y':
                    arcadeEvent.type = event::EventType::KEYBOARD;
                    arcadeEvent.evKey.type = event::Type::PRESSED;
                    arcadeEvent.evKey.key = event::keys::Y;
                    return arcadeEvent;
                case 'Z':
                case 'z':
                    arcadeEvent.type = event::EventType::KEYBOARD;
                    arcadeEvent.evKey.type = event::Type::PRESSED;
                    arcadeEvent.evKey.key = event::keys::Z;
                    return arcadeEvent;
                case KEY_BACKSPACE:
                    arcadeEvent.type = event::EventType::KEYBOARD;
                    arcadeEvent.evKey.type = event::Type::PRESSED;
                    arcadeEvent.evKey.key = event::keys::BACKSPACE;
                    return arcadeEvent;
                case KEY_IC:
                    arcadeEvent.type = event::EventType::KEYBOARD;
                    arcadeEvent.evKey.type = event::Type::PRESSED;
                    arcadeEvent.evKey.key = event::keys::INSERT;
                    return arcadeEvent;
                case KEY_HOME:
                    arcadeEvent.type = event::EventType::KEYBOARD;
                    arcadeEvent.evKey.type = event::Type::PRESSED;
                    arcadeEvent.evKey.key = event::keys::HOME;
                    return arcadeEvent;
                case KEY_END:
                    arcadeEvent.type = event::EventType::KEYBOARD;
                    arcadeEvent.evKey.type = event::Type::PRESSED;
                    arcadeEvent.evKey.key = event::keys::END;
                    return arcadeEvent;
                case KEY_NPAGE:
                    arcadeEvent.type = event::EventType::KEYBOARD;
                    arcadeEvent.evKey.type = event::Type::PRESSED;
                    arcadeEvent.evKey.key = event::keys::PAGEUP;
                    return arcadeEvent;
                case KEY_PPAGE:
                    arcadeEvent.type = event::EventType::KEYBOARD;
                    arcadeEvent.evKey.type = event::Type::PRESSED;
                    arcadeEvent.evKey.key = event::keys::PAGEDOWN;
                    return arcadeEvent;
                case '\n':
                    arcadeEvent.type = event::EventType::KEYBOARD;
                    arcadeEvent.evKey.type = event::Type::PRESSED;
                    arcadeEvent.evKey.key = event::keys::RETURN;
                    return arcadeEvent;
                default:
                    arcadeEvent.type = event::EventType::NONE;
                    return arcadeEvent;
            }
        }

        void Ncurses::loadTextures(const VPtrTexture &textures) {
            _textures.clear();
            for (auto &texture : textures) {
                PtrTextObject text = texture->getTextureText();
                _textures.push_back({texture->getId(), text->getContent(), text->getColor(), text->getBackGroundColor()});
            }
        }

        void Ncurses::loadFonts(const std::vector<std::string> &fonts) {}

        void Ncurses::displayObjects(const VPtrObject &objects) {
            clearWindow();
            for (const auto &object : objects) {
                if (!object->isDisplay())
                    continue;
                switch (object->getType()) {
                    case ObjectType::TEXT:
                        displayTexts(std::static_pointer_cast<ITextObject>(object));
                        break;
                    case ObjectType::SPRITE:
                        displaySprites(std::static_pointer_cast<ISpriteObject>(object));
                        break;
                    case ObjectType::RECT:
                        displayRect(std::static_pointer_cast<IRect>(object));
                        break;
                    case ObjectType::BACKGROUND:
                        clearWindow(std::static_pointer_cast<IBackground>(object)->getColor());
                        break;
                    default:
                        break;
                }
            }
            refresh();
        }

        void Ncurses::displayTexts(const PtrTextObject &obj) {
            init_pair(_pair, getColor(obj->getColor()), getColor(obj->getBackGroundColor()));
            attron(COLOR_PAIR(_pair));
            mvprintw(getHeight(obj->getPos().y), getWidth(obj->getPos().x), obj->getContent().c_str());
            attroff(COLOR_PAIR(_pair));
            incPair();
        }

        void Ncurses::displaySprites(const PtrSpriteObject &objects) {
            NcursesTexture text = _textures[objects->getIdTexture()];
            init_pair(_pair, getColor(text.color), getColor(text.backColor));
            attron(COLOR_PAIR(_pair));
            for (int y = objects->getPos().y; y < objects->getPos().y + objects->getShape().width; y++) {
                for (int x = objects->getPos().x; x < objects->getPos().x + objects->getShape().height; x++) {
                    mvprintw(getHeight(y), getWidth(x), text.str.c_str());
                }
            }
            attroff(COLOR_PAIR(_pair));
            incPair();
        }

        void Ncurses::displayRect(const PtrRect &objects) {
            init_pair(_pair, getColor(objects->getColor()), getColor(objects->getColor()));
            attron(COLOR_PAIR(_pair));
            for (int y = objects->getPos().y; y < objects->getPos().y + objects->getShape().height; y++) {
                for (int x = objects->getPos().x; x < objects->getPos().x + objects->getShape().width; x++) {
                    mvprintw(getHeight(y), getWidth(x), " ");
                }
            }
            attroff(COLOR_PAIR(_pair));
            incPair();
        }

        chtype Ncurses::getColor(const color_t &color) const {
            chtype allColors[] = {COLOR_BLACK, COLOR_RED, COLOR_GREEN, COLOR_YELLOW, COLOR_BLUE, COLOR_MAGENTA, COLOR_CYAN, COLOR_WHITE};
            color_t allColorsNcurses[] = {{0, 0, 0, 255}, {255, 0, 0, 255}, {0, 255, 0, 255}, {255, 255, 0, 255}, {0, 0, 255, 255}, {255, 0, 255, 255}, {0, 255, 255, 255}, {255, 255, 255, 255}};
            int min = 1000;
            int ind = 0;

            for (int i = 0; i < 8; i++) {
                int diff = abs(allColorsNcurses[i].r - color.r) + abs(allColorsNcurses[i].g - color.g) + abs(allColorsNcurses[i].b - color.b);
                if (diff < min) {
                    min = diff;
                    ind = i;
                }
            }
            return allColors[ind];
        }

        chtype Ncurses::getTexture(const ITexture &texture) const {
            PtrTextObject text = texture.getTextureText();
            chtype ch = ' ';
            if (text == nullptr || text->getColor().a == 255)
                return ch;
            ch = text->getContent()[0];
            init_pair(1, getColor(text->getColor()), getColor(text->getBackGroundColor()));
            return ch | COLOR_PAIR(1);
        }

        void Ncurses::getWindowDimensions() {
            getWindowDimensions(_width, _height);
        }

        void Ncurses::getWindowDimensions(int &width, int &height) {
            getmaxyx(_window, height, width);
        }

        int Ncurses::getWidth(int x) const {
            return x * COLS / _windowParameters->width;
        }

        int Ncurses::getHeight(int y) const {
            return y * LINES / (_windowParameters->height);
        }

        void Ncurses::incPair() {
            _pair = (_pair % 255) + 1;
        }
    }
}

extern "C" arcade::ncurses::Ncurses *createLib()
{
    return new arcade::ncurses::Ncurses();
}

extern "C" arcade::LibType getType()
{
    return arcade::LibType::GRAPHIC;
}

extern "C" std::string getName()
{
    return std::string("nCurses");
}