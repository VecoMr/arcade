/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** object
*/

#include "Sfml.hpp"

namespace arcade {
    namespace sfml {
        void Sfml::displayObjects(const VPtrObject &objects) {
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
            _view->setSize(_windowParameters->width, _windowParameters->height);
            _view->setCenter(_windowParameters->width / 2, _windowParameters->height / 2);
            this->_window->setView(*_view);
            this->_window->display();
        }

        void Sfml::displayTexts(const PtrTextObject &textObject) {
            sf::Text text;
            text.setFont(*this->_fonts[textObject->getIdFontFamily()]);
            text.setString(textObject->getContent());
            text.setCharacterSize(textObject->getSize());
            text.setFillColor(this->getColor(textObject->getColor()));
            text.setPosition(textObject->getPos().x, textObject->getPos().y);
            sf::FloatRect textBounds = text.getGlobalBounds();
            textObject->setBounds({(int) textBounds.left, (int) textBounds.top, (int) textBounds.width, (int) textBounds.height});
            if (textObject->getBackGroundColor().a != 0) {
                sf::RectangleShape rectangle;
                rectangle.setSize(sf::Vector2f(textBounds.width, textBounds.height));
                rectangle.setFillColor(this->getColor(textObject->getBackGroundColor()));
                rectangle.setPosition(textBounds.left, textBounds.top);
                this->_window->draw(rectangle);
            }
            this->_window->draw(text);
            return;
        }

        void Sfml::displaySprites(const PtrSpriteObject &spriteObject) {
            sf::Sprite sprite;
            sprite.setTexture(*this->_textures[spriteObject->getIdTexture()]);
            sprite.setPosition(spriteObject->getPos().x, spriteObject->getPos().y);

            sf::FloatRect spriteSize = sprite.getGlobalBounds();
            float scaleX = spriteObject->getShape().width / spriteSize.width;
            float scaleY = spriteObject->getShape().height / spriteSize.height;
            sprite.setScale(scaleX, scaleY);
            this->_window->draw(sprite);
            return;
        }

        void Sfml::displayRect(const PtrRect &rect) {
            sf::RectangleShape rectangle;
            rectangle.setSize(sf::Vector2f(rect->getBounds().width, rect->getBounds().height));
            rectangle.setFillColor(this->getColor(rect->getColor()));
            rectangle.setPosition(rect->getPos().x, rect->getPos().y);
            this->_window->draw(rectangle);
            return;
        }
    }
}