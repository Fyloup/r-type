/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** SFML Entity Class Prototype
*/

#ifndef OOP_RTYPE_2018_SFMLENTITY_HPP
#define OOP_RTYPE_2018_SFMLENTITY_HPP

#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window/Mouse.hpp>

#include "rtype.hpp"
#include "Conf.hpp"

namespace rtype {
    class SFMLEntity {
    public:
        SFMLEntity(std::string name, std::string content, std::pair<float, float> pos, rtype::type type, float resize, std::pair<float, float> rectSize, int nbSprite, int nbSpriteStartX, int nbSpriteStartY);
        ~SFMLEntity();

        void setPos(std::pair <float, float> pos);
        void changeContent(const std::string &context);
        void resizePos(sf::Vector2u);

        std::pair<float, float> getPos() const;
        const std::string &getContent() const;
        sf::Text &getText();
        const sf::Sprite &getSprite() const;
        const std::string &getName() const;
        const rtype::type &getType() const;
        bool isHover() const;
        bool isClick() const;
        void nextSprite(bool);

    private:
        void initText();
        void initSprite();

        std::string _content;
        std::string _name;
        float _resize;
        std::pair<float, float> _pos;
        std::pair<float, float> _posResized;
        std::pair<float, float> _rectSize;
        sf::Texture _texture;
        sf::Sprite _sprite;
        sf::Font _font;
        sf::Text _text;
        rtype::type _type;
        int _nbSprite;
        int _nbSpriteStartX;
        int _nbSpriteStartY;
    };
}

#endif //OOP_RTYPE_2018_SFMLENTITY_HPP