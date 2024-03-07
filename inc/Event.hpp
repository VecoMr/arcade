/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** Event
*/

#pragma once

#include <vector>

namespace arcade {
    using VAcradeEvent = std::vector<event::ArcadeEvent>;
    using VGameEvent = std::vector<event::GameEvent>;

    namespace event {

        enum class type {
            PRESSED,
            RELEASED
        };

        struct keyboard {
            type type;
            enum class key {
                A,
                B,
                C,
                D,
                E,
                F,
                G,
                H,
                I,
                J,
                K,
                L,
                M,
                N,
                O,
                P,
                Q,
                R,
                S,
                T,
                U,
                V,
                W,
                X,
                Y,
                Z,
                NUM0,
                NUM1,
                NUM2,
                NUM3,
                NUM4,
                NUM5,
                NUM6,
                NUM7,
                NUM8,
                NUM9,
                ESCAPE,
                LCONTROL,
                LSHIFT,
                LALT,
                LSYSTEM,
                RCONTROL,
                RSHIFT,
                RALT,
                RSYSTEM,
                MENU,
                LBRACKET,
                RBRACKET,
                SEMICOLON,
                COMMA,
                PERIOD,
                QUOTE,
                SLASH,
                BACKSLASH,
                TILDE,
                EQUAL,
                DASH,
                SPACE,
                RETURN,
                BACKSPACE,
                TAB,
                PAGEUP,
                PAGEDOWN,
                END,
                HOME,
                INSERT,
                DELETE,
                ADD,
                SUBTRACT,
                MULTIPLY,
                DIVIDE,
                LEFT,
                RIGHT,
                UP,
                DOWN,
                NUMPAD0,
                NUMPAD1,
                NUMPAD2,
                NUMPAD3,
                NUMPAD4,
                NUMPAD5,
                NUMPAD6,
                NUMPAD7,
                NUMPAD8,
                NUMPAD9,
                F1,
                F2,
                F3,
                F4,
                F5,
                F6,
                F7,
                F8,
                F9,
                F10,
                F11,
                F12,
                F13,
                F14,
                F15,
                PAUSE,
            };
        };

        struct mouse {
            type type;
            int x;
            int y;
            int wheel;
        };

        struct window {
            int width;
            int height;
            enum class type {
                CLOSE,
                RESIZE,
                FOCUS,
                LOSTFOCUS
            };
        };
        
        enum class EventType {
            NONE,
            KEYBOARD,
            MOUSE,
            WINDOW,
            JOYSTICK
        };

        struct ArcadeEvent {
            EventType type;
            union {
                keyboard key;
                mouse mouse;
                window window;
            };
        };

        enum class GameEventType {
            UP,
            DOWN,
            LEFT,
            RIGHT,
            PREV_GAME,
            NEXT_GAME,
            PREV_GRAPHICAL,
            NEXT_GRAPHICAL,
            CLICK,
            WINDOW,
            CLOSE,
            EXIT
        };

        struct GameEvent {
            GameEventType type;
            union options {
                struct mouse {
                    event::type type;
                    float x;
                    float y;
                };
                struct window {
                    int width;
                    int height;
                };
            };
        };
    }
}
