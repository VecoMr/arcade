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

#include "Texture.hpp"

namespace arcade {
    using PtrObject = std::shared_ptr<IObject>;
    using VPtrObject = std::vector<std::shared_ptr<IObject>>;

    typedef struct {
        int x;
        int y;
    } pos_t;

    typedef struct {
        int r;
        int g;
        int b;
        int a;
    } color_t;

    typedef struct {
        int x;
        int y;
        int width;
        int height;
    } shape_t;

    enum class ObjectType {
        TEXT,
        SPRITE
    };

    class IObject {
        public:
            virtual ~IObject() = default;

            virtual void setType(ObjectType type) = 0;
            virtual ObjectType getType() const = 0;

            virtual void setDisplay(bool isDisplay) = 0;
            virtual bool isDisplay() const = 0;

            virtual void setPos(pos_t pos) = 0;
            virtual pos_t getPos() const = 0;
    };

    class ITextObject: public IObject {
        public:
            virtual ~ITextObject() = default;

            virtual void setContent(std::string str) = 0;
            virtual std::string getContent() const = 0;

            virtual void setSize(int size) = 0;
            virtual int getSize() const = 0;

            virtual void setColor(color_t color) = 0;
            virtual color_t getColor() const = 0;

            virtual void setFontFamily(std::string fontPath) = 0;
            virtual std::string getFontFamily() const = 0;
    };

    class ISpriteObject: public IObject {
        public:
            virtual ~ISpriteObject() = default;

            virtual void setIdTexture(int id) = 0;
            virtual int getIdTexture() const = 0;

            virtual void setShape(shape_t shape) = 0;
            virtual shape_t getShape() const = 0;
    };
}
