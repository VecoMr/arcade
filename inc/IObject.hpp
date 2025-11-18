/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** IObject
*/

#pragma once

#include <vector>
#include <iostream>
#include <memory>

namespace arcade {
    /**
     * @enum LibType
     * @brief Enumeration for library types.
     *
     * This enumeration defines two types of libraries: GRAPHIC and GAME.
     * It's likely used to distinguish between graphical libraries (e.g., SFML, SDL2) and game libraries (e.g., Pacman, Snake).
     */
    enum class LibType {
        GRAPHIC,
        GAME
    };

    /**
     * @enum LibGraphic
     * @brief Enumeration for supported graphic libraries.
     *
     * This enumeration lists various graphic libraries that the arcade library might potentially support.
     * The actual supported libraries may depend on the implementation.
     */
    enum class LibGraphic {
        SFML,
        NCURSES,
        SDL2,
        NDK,
        AALIB,
        ALLEGRO,
        XLIB,
        GTK,
        IRRLICHT,
        OPENGL,
        VULKAN,
        QT,
        OTHER
    };

    /**
     * @enum LibGame
     * @brief Enumeration for supported game libraries.
     *
     * This enumeration lists various game libraries that the arcade library might potentially support.
     * The actual supported libraries may depend on the implementation.
     */
    enum class LibGame {
        PACMAN,
        NIBBLER,
        CENTIPEDE,
        SOLARFOX,
        QIX,
        SNAKE,
        OTHER
    };

    /**
     * @typedef pos_t
     * @brief Structure representing a position in 2D space.
     *
     * This structure defines a position with integer coordinates (x, y).
     */
    typedef struct {
        int x;
        int y;
    } pos_t;

    /**
     * @typedef color_t
     * @brief Structure representing a color.
     *
     * This structure defines a color with integer values for red (r), green (g), blue (b), and alpha (a) channels.
     */
    typedef struct {
        int r;
        int g;
        int b;
        int a;
    } color_t;

    /**
     * @typedef shape_t
     * @brief Structure representing a rectangle shape.
     *
     * This structure defines a rectangle with its position (x, y), width, and height.
     */
    typedef struct {
        int x;
        int y;
        int width;
        int height;
    } shape_t;

    /**
     * @enum ObjectType
     * @brief Enumeration for types of game objects.
     *
     * This enumeration defines different types of game objects supported by the arcade library: TEXT, SPRITE, BACKGROUND, and RECT.
     */
    enum class ObjectType {
        TEXT,
        SPRITE,
        BACKGROUND,
        RECT
    };

    /**
     * @class IObject
     * @brief Base interface for all game objects.
     *
     * This interface defines common functionalities for various graphical objects used in the arcade library.
     * Implementations of this interface provide specific rendering behaviors for different object types (text, sprite, etc.).
     */
    class IObject {
        public:
            /**
             * @brief Destructor for IObject.
             *
             * Virtual destructor to ensure proper cleanup in derived classes.
             */
            virtual ~IObject() = default;

            /**
             * @brief Sets the type of the object.
             *
             * This function sets the object type (TEXT, SPRITE, BACKGROUND, or RECT) based on the `ObjectType` enumeration.
             *
             * @param type The new object type.
             */
            virtual void setType(ObjectType type) = 0;

            /**
             * @brief Gets the type of the object.
             *
             * This function returns the current object type as an `ObjectType` enum value.
             *
             * @return The current object type.
             */
            virtual ObjectType getType() const = 0;

            /**
             * @brief Sets the visibility of the object.
             *
             * This function controls whether the object is displayed or hidden.
             *
             * @param isDisplay True to show the object, false to hide it.
             */
            virtual void isDisplay(bool isDisplay) = 0;
            /**
             * @brief Gets the visibility of the object.
             *
             * This function returns a boolean indicating whether the object is currently displayed.
             *
             * @param isDisplay True if the object is show, false else.
             */
            virtual bool isDisplay() const = 0;

            /**
             * @brief Sets the position of the object.
             *
             * This function sets the object's position on the screen using a `pos_t` structure.
             *
             * @param pos The new position for the object.
             */
            virtual void setPos(pos_t pos) = 0;

            /**
             * @brief Gets the position of the object.
             *
             * This function returns the current position of the object as a `pos_t` structure.
             *
             * @return The current position of the object.
             */
            virtual pos_t getPos() const = 0;

            /**
             * @brief Sets the bounding rectangle of the object.
             *
             * This function sets the shape (x, y, width, height) of the object's bounding rectangle using a `shape_t` structure.
             *
             * @param bounds The new bounding rectangle for the object.
             */
            virtual void setBounds(shape_t bounds) = 0;

            /**
             * @brief Gets the bounding rectangle of the object.
             *
             * This function returns the current bounding rectangle of the object as a `shape_t` structure.
             *
             * @return The current bounding rectangle of the object.
             */
            virtual shape_t getBounds() const = 0;
    };

    using PtrObject = std::shared_ptr<IObject>;
    using VPtrObject = std::vector<std::shared_ptr<IObject>>;

    /**
     * @class ITextObject
     * @brief Interface for text objects.
     *
     * This interface inherits from `IObject` and defines functionalities specific to text objects.
     */
    class ITextObject: public IObject {
        public:
            /**
             * @brief Destructor for ITextObject.
             *
             * Virtual destructor to ensure proper cleanup in derived classes.
             */
            virtual ~ITextObject() = default;

            /**
             * @brief Sets the text content to be displayed.
             *
             * This function sets the string content that will be displayed as text.
             *
             * @param str The new text content for the object.
             */
            virtual void setContent(const std::string str) = 0;

            /**
             * @brief Gets the text content of the object.
             *
             * This function returns the current string content displayed by the text object.
             *
             * @return The current text content of the object.
             */
            virtual std::string getContent() const = 0;

            /**
             * @brief Sets the font size for the text.
             *
             * This function sets the size of the font used to render the text.
             *
             * @param size The new font size for the text.
             */
            virtual void setSize(const int size) = 0;

            /**
             * @brief Gets the font size of the text.
             *
             * This function returns the current font size used to render the text.
             *
             * @return The current font size of the text.
             */
            virtual int getSize() const = 0;

            /**
             * @brief Sets the color of the text.
             *
             * This function sets the color of the text using a `color_t` structure with red, green, blue, and alpha channels.
             *
             * @param color The new color for the text.
             */
            virtual void setColor(const color_t color) = 0;

            /**
             * @brief Gets the color of the text.
             *
             * This function returns the current color of the text as a `color_t` structure.
             *
             * @return The current color of the text.
             */
            virtual color_t getColor() const = 0;

            /**
             * @brief Sets the ID of the font family to use (optional).
             *
             * This function allows setting an identifier for the desired font family.
             * The interpretation and usage of this ID depend on the specific implementation of the arcade library.
             * It's possible that the library manages font resources and uses this ID to retrieve the appropriate font.
             *
             * @param id The ID of the font family.
             */
            virtual void setIdFontFamily(const int id) = 0;

            /**
             * @brief Gets a reference to the ID of the font family (optional).
             *
             * This function returns a reference to the integer ID set for the font family.
             * It may return a reference to a temporary variable if the ID is internally managed.
             * Modifications made through this reference might not persist.
             *
             * @return Reference to the ID of the font family (if applicable).
             */
            virtual int &getIdFontFamily() = 0;

            /**
             * @brief Sets the background color of the text object (optional).
             *
             * This function allows setting a background color for the text object.
             * Not all implementations might support text background rendering.
             *
             * @param color The new background color for the text.
             */
            virtual void setBackGroundColor(const color_t color) = 0;

            /**
             * @brief Gets the background color of the text object (optional).
             *
             * This function returns the current background color of the text object as a `color_t` structure.
             * If background rendering is not supported, this function might return a default color.
             *
             * @return The current background color of the text (if applicable).
             */
            virtual color_t getBackGroundColor() const = 0;
    };

    using PtrTextObject = std::shared_ptr<ITextObject>;
    using VPtrTextObject = std::vector<std::shared_ptr<ITextObject>>;

    /**
     * @class ISpriteObject
     * @brief Interface for sprite objects.
     *
     * This interface inherits from `IObject` and defines functionalities specific to sprite objects.
     * Sprites are graphical elements typically rendered using textures.
     */
    class ISpriteObject: public IObject {
        public:
            /**
             * @brief Destructor for ISpriteObject.
             *
             * Virtual destructor to ensure proper cleanup in derived classes.
             */
            virtual ~ISpriteObject() = default;

            /**
             * @brief Sets the ID of the texture associated with the sprite.
             *
             * This function sets an identifier for the texture used to render the sprite.
             * The interpretation and usage of this ID depend on the specific implementation of the arcade library.
             * It's likely that the library manages texture resources and uses this ID to retrieve the appropriate texture for the sprite.
             *
             * @param id The ID of the texture to associate with the sprite.
             */
            virtual void setIdTexture(int id) = 0;

            /**
             * @brief Gets the ID of the texture associated with the sprite.
             *
             * This function returns the current ID of the texture used to render the sprite.
             *
             * @return The ID of the texture associated with the sprite.
             */
            virtual int getIdTexture() const = 0;

            /**
             * @brief Sets the shape (position, width, and height) of the sprite.
             *
             * This function defines the position, width, and height of the rectangular area occupied by the sprite on the screen.
             * It uses a `shape_t` structure containing position, width, and height.
             *
             * @param shape The new shape definition for the sprite.
             */
            virtual void setShape(shape_t shape) = 0;

            /**
             * @brief Gets the shape (position, width, and height) of the sprite.
             *
             * This function returns the current shape definition of the sprite as a `shape_t` structure.
             *
             * @return The current shape definition of the sprite.
             */
            virtual shape_t getShape() const = 0;
    };


    using PtrSpriteObject = std::shared_ptr<ISpriteObject>;
    using VPtrSpriteObject = std::vector<std::shared_ptr<ISpriteObject>>;

    /**
     * @class ITexture
     * @brief Interface for texture objects.
     *
     * This interface defines functionalities for managing textures used in rendering sprites and other graphical elements.
     */
    class ITexture {
        public:
            /**
             * @brief Destructor for ITexture.
             *
             * Virtual destructor to ensure proper cleanup in derived classes.
             */
            virtual ~ITexture() = default;

            /**
             * @brief Sets the ID of the texture.
             *
             * This function sets an identifier for the texture, likely used for internal management within the library.
             * This ID might be used to retrieve the texture data or associate it with other objects.
             *
             * @param id The new ID for the texture.
             */
            virtual void setId(int id) = 0;

            /**
             * @brief Gets the ID of the texture.
             *
             * This function returns the current ID assigned to the texture.
             *
             * @return The ID of the texture.
             */
            virtual int getId() const = 0;

            /**
             * @brief Sets the path to the texture file.
             *
             * This function specifies the file path of the image file containing the texture data.
             *
             * @param texturePath The path to the texture file.
             */
            virtual void setTexturePath(std::string texturePath) = 0;

            /**
             * @brief Gets the path to the texture file.
             *
             * This function returns the current file path associated with the texture.
             *
             * @return The path to the texture file.
             */
            virtual std::string getTexturePath() const = 0;

            /**
             * @brief Sets a text object to be used as the texture source (optional).
             *
             * This function allows using text content as a texture source.
             * Not all implementations might support this functionality.
             *
             * @param text Shared pointer to a text object used as the texture source.
             */
            virtual void setTextureText(PtrTextObject text) = 0;

            /**
             * @brief Gets the text object used as the texture source (optional).
             *
             * This function returns a shared pointer to the text object used as the texture source, if applicable.
             * If text textures are not supported, this function might return nullptr.
             *
             * @return Shared pointer to the text object used as texture source (if applicable).
             */
            virtual PtrTextObject getTextureText() const = 0;
    };

    using PtrTexture = std::shared_ptr<ITexture>;
    using VPtrTexture = std::vector<std::shared_ptr<ITexture>>;

    /**
     * @class IBackground
     * @brief Interface for background objects.
     *
     * This interface defines functionalities for managing background elements within the game.
     */
    class IBackground: public IObject {
        public:
            /**
             * @brief Destructor for IBackground.
             *
             * Virtual destructor to ensure proper cleanup in derived classes.
             */
            virtual ~IBackground() = default;

            /**
             * @brief Sets the background color.
             *
             * This function sets the color used to fill the background element.
             *
             * @param color The new color for the background.
             */
            virtual void setColor(color_t color) = 0;

            /**
             * @brief Gets the background color.
             *
             * This function returns the current color used for the background.
             *
             * @return The current background color.
             */
            virtual color_t getColor() const = 0;
    };

    using PtrBackground = std::shared_ptr<IBackground>;

    /**
     * @class IRect
     * @brief Interface for rectangle objects.
     *
     * This interface defines functionalities for managing rectangular shapes used in the game.
     */
    class IRect: public IObject {
        public:
            /**
             * @brief Destructor for IRect.
             *
             * Virtual destructor to ensure proper cleanup in derived classes.
             */
            virtual ~IRect() = default;

            /**
             * @brief Sets the color of the rectangle.
             *
             * This function sets the color used to fill or outline the rectangle.
             *
             * @param color The new color for the rectangle.
             */
            virtual void setColor(color_t color) = 0;
            /**
             * @brief Gets the color of the rectangle.
             *
             * This function returns the current color used for the rectangle.
             *
             * @return The current color of the rectangle.
             */
            virtual color_t getColor() const = 0;

            /**
             * @brief Sets the shape (position, width, and height) of the rectangle.
             *
             * This function defines the position, width, and height of the rectangle using a `shape_t` structure.
             *
             * @param shape The new shape definition for the rectangle.
             */
            virtual void setShape(shape_t shape) = 0;

            /**
             * @brief Gets the shape (position, width, and height) of the rectangle.
             *
             * This function returns the current shape definition of the rectangle as a `shape_t` structure.
             *
             * @return The current shape definition of the rectangle.
             */
            virtual shape_t getShape() const = 0;
    };

    using PtrRect = std::shared_ptr<IRect>;
}
