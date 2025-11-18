/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** IGames
*/

#pragma once

#include <iostream>
#include <memory>
#include <vector>
#include <chrono>

#include "IObject.hpp"
#include "Event.hpp"

namespace arcade {

    /**
     * @struct windowParameters_t
     * @brief Structure to hold window parameters (likely for window creation).
     *
     * This structure likely contains members for width, height, title, and other window-related properties.
     * The exact definition is not provided in the given code snippet.
     */
    typedef struct windowParameters_s windowParameters_t;
    using PtrWindowP = std::shared_ptr<windowParameters_t>;

    /**
     * @namespace menu
     * @brief Namespace likely containing classes related to game menus.
     *
     * The provided code snippet only references the `Menu` class within this namespace. It's assumed the namespace holds menu-related functionalities.
     */
    namespace menu {
        class Menu;
    }

    /**
     * @enum State
     * @brief Enumeration representing different game states.
     *
     * This enumeration defines various states the game can be in, such as menu, game, settings, pause, win, lose, and exit.
     */
    enum class State {
        MENU,
        GAME,
        SETTINGS,
        PAUSE,
        WIN,
        LOSE,
        EXIT
    };

    /**
     * @class IGames
     * @brief Interface for game functionalities in the arcade library.
     *
     * This interface defines essential functions for game logic and management within the arcade library.
     * Implementations of this interface provide the core gameplay functionalities for specific games.
     */
    class IGames {
        public:
            /**
             * @brief Destructor for IGames.
             *
             * Virtual destructor to ensure proper cleanup in derived classes.
             */
            virtual ~IGames() = default;

            /**
             * @brief Initializes the game with the provided window parameters.
             *
             * This function initializes the game using the specified window configuration.
             * The `windowP` argument likely points to a `windowParameters_t` object containing window creation details.
             *
             * @param windowP Shared pointer to a windowParameters_t object.
             */
            virtual void initGame(const PtrWindowP windowP) = 0;

            /**
             * @brief Destroys the game and releases associated resources.
             *
             * This function cleans up the game resources and terminates the game instance.
             */
            virtual void destroyGame() = 0;

            /**
             * @brief Restarts the current game.
             *
             * This function resets the game state and starts a new game session.
             */
            virtual void restartGame() = 0;

            /**
             * @brief Checks if the game is over.
             *
             * This function returns a boolean indicating whether the game has reached an ending state (win, lose, etc.).
             *
             * @return True if the game is over, false otherwise.
             */
            virtual bool isGameOver() = 0;

            /**
             * @brief Processes game events and updates the game state.
             *
             * This function takes a reference to a container (likely a vector) of `VGameEvent` objects representing the events that have occurred.
             * It processes these events and updates the game state accordingly.
             *
             * @param events Reference to a container holding VGameEvent objects (game events).
             * @return The current game state after processing events.
             */
            virtual State execute(VGameEvent &events) = 0;

            /**
             * @brief Gets the current game score.
             *
             * This function returns the current score achieved in the game.
             *
             * @return The current game score (integer value).
             */
            virtual int getScore() = 0;

            /**
             * @brief Gets the list of font paths used by the game.
             *
             * This function provides a reference to a vector of strings containing the file paths for the fonts used in the game.
             * These fonts are likely loaded for displaying text elements.
             *
             * @return Reference to a vector containing font file paths (strings).
             */
            virtual std::vector<std::string> &getFontPaths() = 0;
            /**
             * @brief Gets a reference to the game's textures.
             *
             * This function provides a reference to a container (likely a vector) of "`VPtrTexture` objects representing the textures used in the game.
             * These textures are likely used for rendering sprites.
             *
             * @return Reference to a container holding VPtrTexture objects (game textures).
             */
            virtual VPtrTexture &getTextures() = 0;

            /**
             * @brief Gets a reference to the game objects.
             *
             * This function provides a reference to a container (likely a vector) of `VPtrObject` objects representing the game objects managed by the game.
             * These objects may include sprites, backgrounds, rect or text components.
             *
             * @return Reference to a container holding VPtrObject objects (game objects).
             */
            virtual VPtrObject &getObjects() = 0;
    };
}

#include "Window.hpp"
