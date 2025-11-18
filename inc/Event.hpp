/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** E,nt
*/

#pragma once

#include <vector>
#include <iostream>

namespace arcade {
    namespace event {
        /**
         * @enum Type
         * @brief Enumeration for event types.
         *
         * This enumeration defines two types of events: PRESSED and RELEASED.
         * It's likely used to indicate whether a key or button is pressed down (PRESSED) or released (RELEASED).
         */
        enum class Type {
            PRESSED,
            RELEASED
        };

        /**
         * @enum keys
         * @brief Enumeration for keyboard keys.
         *
         * This enumeration lists all supported keyboard keys, including alphanumeric characters, special keys (e.g., arrow keys, function keys), and control keys.
         */
        enum class keys {
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
            UNKNOWN
        };

        /**
         * @struct keyboard
         * @brief Structure representing a keyboard event.
         *
         * This structure holds information about a keyboard event, including the event type (PRESSED or RELEASED) and the specific key that was pressed.
         */
        struct keyboard {
            Type type;
            keys key;
        };

        /**
         * @struct mouse
         * @brief Structure representing a mouse event.
         *
         * This structure holds information about a mouse event, including the event type (PRESSED or RELEASED), the mouse cursor position (x and y), and the mouse wheel movement.
         */
        struct mouse {
            Type type;
            int x;
            int y;
            int wheel;
        };

        /**
         * @struct window
         * @brief Structure representing a window event.
         *
         * This structure holds information about a window event, including the event type (CLOSE, RESIZE, FOCUS, or LOSTFOCUS), the window's width and height, and the window's focus state.
         */
        struct window {
            int width;
            int height;
            enum class type {
                CLOSE,
                RESIZE,
                FOCUS,
                LOSTFOCUS
            } type;
        };

        /**
         * @enum EventType
         * @brief Enumeration for event categories.
         *
         * This enumeration defines different categories of events that can be received by the application:
         *  - NONE: No event.
         *  - KEYBOARD: Keyboard event (key press or release).
         *  - MOUSE: Mouse event (button press or release, movement, wheel).
         *  - WINDOW: Window event (close, resize, focus change).
         *  - JOYSTICK (not implemented yet): Joystick event (likely for future support).
         */
        enum class EventType {
            NONE,
            KEYBOARD,
            MOUSE,
            WINDOW,
            JOYSTICK,
        };

        /**
         * @struct ArcadeEvent
         * @brief Structure representing an arcade event.
         *
         * This structure holds information about an arcade event, including the event type (KEYBOARD, MOUSE, WINDOW, etc.) and the specific event data.
         * This event structure is use to represent events that can be received by the Core to be convert in GameEvent.
         */
        struct ArcadeEvent {
            EventType type;
            union {
                keyboard evKey;
                mouse evMouse;
                window evWindow;
            };

            bool operator==(const ArcadeEvent &other) const;
        };
        
        /**
         * @brief Less-than comparison operator for ArcadeEvent objects (likely for sorting).
         *
         * This function allows sorting ArcadeEvent objects based on a specific criteria (not defined in this code snippet).
         * The actual implementation of this operator might depend on the intended use case for sorting events.
         *
         * @param lhs Left-hand side operand (ArcadeEvent object).
         * @param rhs Right-hand side operand (ArcadeEvent object).
         *
         * @return
        */
        bool operator<(const ArcadeEvent& lhs, const ArcadeEvent& rhs);

        /**
         * @enum GameEventType
         * @brief Enumeration for game event types.
         *
         * This enumeration defines different types of game events that can be triggered by the user:
         *  - UP: Move up.
         *  - DOWN: Move down.
         *  - LEFT: Move left.
         *  - RIGHT: Move right.
         *  - RESTART_GAME: Restart the game.
         *  - PREV_GAME: Switch to the previous game.
         *  - NEXT_GAME: Switch to the next game.
         *  - PREV_GRAPHICAL: Switch to the previous graphical library.
         *  - NEXT_GRAPHICAL: Switch to the next graphical library.
         *  - CLICK: Mouse click event.
         *  - KEYBOARD: Keyboard event.
         *  - WINDOW: Window event.
         *  - CLOSE: Close the game.
         *  - EXIT: Exit the application.
         *  - NONE: No game event.
         */
        enum class GameEventType {
            UP,
            DOWN,
            LEFT,
            RIGHT,
            RESTART_GAME,
            PREV_GAME,
            NEXT_GAME,
            PREV_GRAPHICAL,
            NEXT_GRAPHICAL,
            CLICK,
            KEYBOARD,
            WINDOW,
            CLOSE,
            EXIT,
            NONE
        };

        /**
         * @struct GameEvent
         * @brief Structure representing a game event.
         *
         * This structure holds information about a game event, including the event type (UP, DOWN, LEFT, RIGHT, etc.) and the specific event data.
         * This event structure is used to represent events that can be triggered by the user during gameplay.
         */
        struct GameEvent {
            GameEventType type;
            Type state;
            union options {
                struct mouse {
                    int x;
                    int y;
                } mouse;
                window windowEv;
                keys key;
            } options;
        };
    }
    using VArcadeEvent = std::vector<event::ArcadeEvent>;
    using VGameEvent = std::vector<event::GameEvent>;

}

std::ostream& operator<<(std::ostream& os, const arcade::event::GameEvent &event);
std::string toString(arcade::event::keys key);
std::string toStringSpecial(arcade::event::keys k);
