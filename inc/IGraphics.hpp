/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** IGraphics
*/

#pragma once

#include <iostream>

#include "IObject.hpp"
#include "Event.hpp"

namespace arcade {

    /**
     * @struct windowParameters_t
     * @brief Structure to hold window parameters.
     *
     * This structure likely contains members for width, height, title, and other window-related properties.
     * The exact definition is not provided in the given code snippet.
     */
    typedef struct windowParameters_s windowParameters_t;
    using PtrWindowP = std::shared_ptr<windowParameters_t>;

    /**
     * @def defBackColor
     * @brief Default background color for the window.
     *
     * This constant defines the default background color used by the `clearWindow` function if no color is specified.
     */
    static color_t defBackColor = {25, 25, 25, 255};

    /**
     * @class IGraphics
     * @brief Interface for graphics functionalities in the arcade library.
     *
     * This interface defines the essential functions for graphics operations within the arcade library.
     * Implementations of this interface provide the actual rendering capabilities for the application.
     */
    class IGraphics {
        public:
            /**
             * @brief Destructor for IGraphics.
             *
             * Virtual destructor to ensure proper cleanup in derived classes.
             */
            virtual ~IGraphics() = default;

            /**
             * @brief Initializes the graphics window.
             *
             * This function initializes the graphics window based on the provided parameters.
             * The `windowP` argument likely points to a `windowParameters_t` object containing window configuration details.
             *
             * @param windowP Shared pointer to a windowParameters_t object.
             */
            virtual void initWindow(const PtrWindowP windowP) = 0;

            /**
             * @brief Destroys the graphics window.
             *
             * This function destroys the initialized graphics window and releases associated resources.
             */
            virtual void destroyWindow() = 0;

            /**
             * @brief Clears the graphics window with a specific color.
             *
             * This function clears the entire window content with the provided color.
             * If no color is specified, it uses the default background color defined in `defBackColor`.
             *
             * @param color The color to use for clearing (optional).
             */
            virtual void clearWindow(const color_t &color = defBackColor) = 0;

            /**
             * @brief Checks if the graphics window is open.
             *
             * This function returns a boolean indicating whether the graphics window is currently open and active.
             *
             * @return True if the window is open, false otherwise.
             */
            virtual bool isOpen() const = 0;

            /**
             * @brief Sets the window parameters.
             *
             * This function allows modifying the window configuration parameters.
             * The `windowParameters` argument is likely a reference to a `windowParameters_t` object where the changes are applied.
             *
             * @param windowParameters Reference to a windowParameters_t object to modify.
             */
            virtual void setWindowParameters(windowParameters_t &windowParameters) = 0;

            /**
             * @brief Gets the window parameters.
             *
             * This function provides access to the current window configuration parameters.
             * It returns a reference to a `windowParameters_t` object containing the window properties.
             *
             * @return Reference to a windowParameters_t object holding window parameters.
             */
            virtual windowParameters_t &getWindowParameters() = 0;

            /**
             * @brief Sets the window width.
             *
             * This function sets the width of the graphics window.
             *
             * @param width The new width for the window.
             */
            virtual void setWindowWidth(int height) = 0;

            /**
             * @brief Sets the window height.
             *
             * This function sets the height of the graphics window.
             *
             * @param height The new height for the window.
             */
            virtual void setWindowHeight(int height) = 0;

            /**
             * @brief Sets the window title.
             *
             * This function sets the title displayed on the window's title bar.
             *
             * @param title The new title string for the window.
             */
            virtual void setWindowTitle(std::string &title) = 0;

            /**
             * @brief Gets the window width.
                 *
             * This function provides access to the current window width.
             * It returns a reference to an integer variable holding the window's width.
             *
             * @return Reference to an integer holding the window width.
             */
            virtual int &getWindowWidth() = 0;

            /**
             * @brief Gets the window height.
             *
             * This function provides access to the current window height.
             * It returns a reference to an integer variable holding the window's height.
             *
             * @return Reference to an integer holding the window height.
             */
            virtual int &getWindowHeight() = 0;

            /**
             * @brief Gets the window title.
             *
             * This function provides access to the current window title.
             * It returns a reference to a string object holding the window's title.
             *
             * @return Reference to a string object holding the window title.
             */
            virtual std::string &getWindowTitle() = 0;

            /**
             * @brief Gets the accumulated arcade events.
             *
             * This function provides access to the events that have occurred since the last call.
             * It returns a reference to a container (likely a vector) of `VArcadeEvent` objects representing the events.
             *
             * @return Reference to a container holding VArcadeEvent objects (events).
             */
            virtual VArcadeEvent &getEvents() = 0;

            /**
             * @brief Loads textures for use in rendering.
             *
             * This function allows loading textures from files or other sources.
             * The `textures` argument likely points to a container (e.g., vector) of `VPtrTexture` objects representing the textures to load.
             *
             * @param textures Container holding pointers to Texture objects (textures to load).
             */
            virtual void loadTextures(const VPtrTexture &textures) = 0;

            /**
             * @brief Loads fonts for use in text rendering.
             *
             * This function allows loading font files for displaying text.
             * The `fonts` argument is likely a vector of strings representing the font file paths to load.
             *
             * @param fonts Vector of strings containing font file paths.
             */
            virtual void loadFonts(const std::vector<std::string> &fonts) = 0;

            /**
             * @brief Displays a collection of game objects on the screen.
             *
             * This function is responsible for rendering the provided game objects onto the graphics window.
             * The `objects` argument likely points to a container (e.g., vector) of `VPtrObject` objects representing the game objects to display.
             *
             * @param objects Container holding pointers to IObject objects (game objects to display).
             */
            virtual void displayObjects(const VPtrObject &objects) = 0;

        private:
            /**
             * @brief Internal function for displaying text objects.
             *
             * This private function is likely used internally by `displayObjects` to handle text rendering specifically.
             * The `objects` argument points to a `PtrTextObject` object representing the text object to display.
             *
             * @param objects Pointer to a TextObject object (text object to display).
             */
            virtual void displayTexts(const PtrTextObject &objects) = 0;

            /**
             * @brief Internal function for displaying sprite objects.
             *
             * This private function is likely used internally by `displayObjects` to handle sprite rendering specifically.
             * The `objects` argument points to a `PtrSpriteObject` object representing the sprite object to display.
             *
             * @param objects Pointer to a SpriteObject object (sprite object to display).
             */
            virtual void displaySprites(const PtrSpriteObject &objects) = 0;

            /**
             * @brief Internal function for displaying rectangles.
             *
             * This private function is likely used internally by `displayObjects` to handle rectangle rendering specifically.
             * The `objects` argument points to a `PtrRect` object representing the rectangle to display.
             *
             * @param objects Pointer to a Rect object (rectangle to display).
             */
            virtual void displayRect(const PtrRect &objects) = 0;
    };
}

#include "Window.hpp"
