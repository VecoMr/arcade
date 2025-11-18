/*
** EPITECH PROJECT, 2024
** B-OOP-400-LYN-4-1-arcade-alexandre.douard
** File description:
** Event
*/

#include "Event.hpp"

namespace arcade {
    namespace event {
        bool operator<(const ArcadeEvent& lhs, const ArcadeEvent& rhs) {
            if (lhs.type < rhs.type)
                return true;
            if (lhs.type == rhs.type) {
                if (lhs.type == EventType::KEYBOARD)
                    return lhs.evKey.key < rhs.evKey.key;
            }
            return false;
        }
        bool ArcadeEvent::operator==(const ArcadeEvent &other) const {
            if (type != other.type)
                return false;
            if (type == EventType::KEYBOARD)
                return evKey.type == other.evKey.type && evKey.key == other.evKey.key;
            return true;
        };
    }
}

std::ostream& operator<<(std::ostream& os, const arcade::event::GameEvent &event)
{
    if (event.type == arcade::event::GameEventType::KEYBOARD)
        os << "Keyboard";
    else if (event.type ==  arcade::event::GameEventType::WINDOW)
        os << "Window";
    else if (event.type ==  arcade::event::GameEventType::CLICK)
        os << "Click";
    else if (event.type ==  arcade::event::GameEventType::EXIT)
        os << "Exit";
    else if (event.type ==  arcade::event::GameEventType::RESTART_GAME)
        os << "Restart";
    else if (event.type ==  arcade::event::GameEventType::NEXT_GAME)
        os << "Next Game";
    else if (event.type ==  arcade::event::GameEventType::PREV_GAME)
        os << "Prev Game";
    else if (event.type ==  arcade::event::GameEventType::NEXT_GRAPHICAL)
        os << "Next Graphical";
    else if (event.type ==  arcade::event::GameEventType::PREV_GRAPHICAL)
        os << "Prev Graphical";
    else if (event.type ==  arcade::event::GameEventType::UP)
        os << "Up";
    else if (event.type ==  arcade::event::GameEventType::DOWN)
        os << "Down";
    else if (event.type ==  arcade::event::GameEventType::LEFT)
        os << "Left";
    else if (event.type ==  arcade::event::GameEventType::RIGHT)
        os << "Right";
    else
        os << "Type";
    return os;
}

std::string toString(arcade::event::keys k) {
    if (k == arcade::event::keys::A)
        return "A";
    if (k == arcade::event::keys::B)
        return "B";
    if (k == arcade::event::keys::C)
        return "C";
    if (k == arcade::event::keys::D)
        return "D";
    if (k == arcade::event::keys::E)
        return "E";
    if (k == arcade::event::keys::F)
        return "F";
    if (k == arcade::event::keys::G)
        return "G";
    if (k == arcade::event::keys::H)
        return "H";
    if (k == arcade::event::keys::I)
        return "I";
    if (k == arcade::event::keys::J)
        return "J";
    if (k == arcade::event::keys::K)
        return "K";
    if (k == arcade::event::keys::L)
        return "L";
    if (k == arcade::event::keys::M)
        return "M";
    if (k == arcade::event::keys::N)
        return "N";
    if (k == arcade::event::keys::O)
        return "O";
    if (k == arcade::event::keys::P)
        return "P";
    if (k == arcade::event::keys::Q)
        return "Q";
    if (k == arcade::event::keys::R)
        return "R";
    if (k == arcade::event::keys::S)
        return "S";
    if (k == arcade::event::keys::T)
        return "T";
    if (k == arcade::event::keys::U)
        return "U";
    if (k == arcade::event::keys::V)
        return "V";
    if (k == arcade::event::keys::W)
        return "W";
    if (k == arcade::event::keys::X)
        return "X";
    if (k == arcade::event::keys::Y)
        return "Y";
    if (k == arcade::event::keys::Z)
        return "Z";
    if (k == arcade::event::keys::NUM0 || k == arcade::event::keys::NUMPAD0)
        return "0";
    if (k == arcade::event::keys::NUM1 || k == arcade::event::keys::NUMPAD1)
        return "1";
    if (k == arcade::event::keys::NUM2 || k == arcade::event::keys::NUMPAD2)
        return "2";
    if (k == arcade::event::keys::NUM3 || k == arcade::event::keys::NUMPAD3)
        return "3";
    if (k == arcade::event::keys::NUM4 || k == arcade::event::keys::NUMPAD4)
        return "4";
    if (k == arcade::event::keys::NUM5 || k == arcade::event::keys::NUMPAD5)
        return "5";
    if (k == arcade::event::keys::NUM6 || k == arcade::event::keys::NUMPAD6)
        return "6";
    if (k == arcade::event::keys::NUM7 || k == arcade::event::keys::NUMPAD7)
        return "7";
    if (k == arcade::event::keys::NUM8 || k == arcade::event::keys::NUMPAD8)
        return "8";
    if (k == arcade::event::keys::NUM9 || k == arcade::event::keys::NUMPAD9)
        return "9";
    return "";
}

std::string toStringSpecial(arcade::event::keys k) {
    std::string str;
    switch (k) {
        case arcade::event::keys::SPACE: str = "SPACE"; break;
        case arcade::event::keys::BACKSLASH: str = "\\"; break;
        case arcade::event::keys::BACKSPACE: str = "BACKSPACE"; break;
        case arcade::event::keys::RETURN: str = "ENTER"; break;
        case arcade::event::keys::SUBTRACT: str = "-"; break;
        case arcade::event::keys::ADD: str = "+"; break;
        case arcade::event::keys::COMMA: str = ","; break;
        case arcade::event::keys::ESCAPE: str = "ESC"; break;
        case arcade::event::keys::EQUAL: str = "="; break;
        case arcade::event::keys::RSHIFT: str = "RSHIFT"; break;
        case arcade::event::keys::LSHIFT: str = "LSHIFT"; break;
        case arcade::event::keys::TAB: str = "TAB"; break;
        case arcade::event::keys::PERIOD: str = "."; break;
        case arcade::event::keys::QUOTE: str = "\""; break;
        case arcade::event::keys::SEMICOLON: str = "'\'"; break;
        case arcade::event::keys::DIVIDE:
        case arcade::event::keys::SLASH: str = "/"; break;
        case arcade::event::keys::MULTIPLY: str = "*"; break;
        case arcade::event::keys::LEFT: str = "LEFT"; break;
        case arcade::event::keys::RIGHT: str = "RIGHT"; break;
        case arcade::event::keys::UP: str = "UP"; break;
        case arcade::event::keys::DOWN: str = "DOWN"; break;
        default: str = ""; break;
    }
    return str;
}
