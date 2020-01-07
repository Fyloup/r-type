/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** SFML Entity
*/

#include <utility>

#include "SFMLEntity.hpp"

rtype::SFMLEntity::SFMLEntity(std::string name,  std::string content, std::pair<float, float> pos, rtype::type type, float resize, const std::pair<float, float> rectSize, int nbSprite, int nbSpriteStartX, int nbSpriteStartY)
    :   _name(std::move(name)), _content(std::move(content)), _pos(std::move(pos)), _type(type), _resize(resize), _rectSize(rectSize), _nbSprite(nbSprite), _nbSpriteStartX(nbSpriteStartX), _nbSpriteStartY(nbSpriteStartY)
{
    if (type == SPRITE || type == SPRITESHEET)
        initSprite();
    else if (type == TEXT || type == BUTTON || type == INPUT_TYPE || type == TEXT_ERROR)
        initText();
}

rtype::SFMLEntity::~SFMLEntity() = default;

void rtype::SFMLEntity::setPos(std::pair <float, float> pos)
{
    _pos = pos;
}

void rtype::SFMLEntity::changeContent(const std::string &text)
{
    if (_type == TEXT || _type == BUTTON || _type == INPUT_TYPE) {
        _content = text;
        _text.setString(_content);
    }
}

void rtype::SFMLEntity::resizePos(sf::Vector2u posWindow)
{
    _posResized.first = posWindow.x * (_pos.first / 100);
    _posResized.second = posWindow.y * (_pos.second / 100);
    _sprite.setPosition(_posResized.first, _posResized.second);
    _text.setPosition(_posResized.first, _posResized.second);
}

std::pair<float, float> rtype::SFMLEntity::getPos() const
{
    return _pos;
}

const std::string &rtype::SFMLEntity::getContent() const
{
    return _content;
}

sf::Text &rtype::SFMLEntity::getText()
{
    return _text;
}

const sf::Sprite &rtype::SFMLEntity::getSprite() const
{
    return _sprite;
}

const std::string &rtype::SFMLEntity::getName() const
{
    return _name;
}

const rtype::type &rtype::SFMLEntity::getType() const
{
    return _type;
}

void rtype::SFMLEntity::initText()
{
    if (!_font.loadFromFile(FONT))
        throw std::runtime_error("Failed to set font from the path : " + std::string(FONT));
    _text.setFont(_font);
    _text.setString(_content);
    _text.setCharacterSize(80);
    if (_type == TEXT_ERROR)
        _text.setFillColor(sf::Color(214, 21, 21));
    else
        _text.setFillColor(sf::Color(0, 49, 196));
    _text.setStyle(sf::Text::Bold);
    _text.setPosition(_pos.first, _pos.second);
}

void rtype::SFMLEntity::initSprite()
{
    if (_content.empty())
        return;
    if (!_texture.loadFromFile(_content))
        throw std::runtime_error("Failed to set texture from the path : " + _content);
    _texture.setSmooth(true);
    _sprite.setTexture(_texture);
    _sprite.setScale(_resize, _resize);
    if (_type == SPRITESHEET)
        _sprite.setTextureRect(sf::Rect<int>(_rectSize.first * float(_nbSpriteStartX), _rectSize.second * float(_nbSpriteStartY), _rectSize.first, _rectSize.second));
}

bool rtype::SFMLEntity::isHover() const
{
    return _text.getGlobalBounds().contains(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y);
}

bool rtype::SFMLEntity::isClick() const
{
    return isHover() && sf::Mouse::isButtonPressed(sf::Mouse::Left);
}

void rtype::SFMLEntity::nextSprite(bool isTop)
{
    if (isTop) {
        if (_sprite.getTextureRect().left + _rectSize.first < _rectSize.first * float(_nbSprite))
            _sprite.setTextureRect(sf::Rect<int>(_sprite.getTextureRect().left + _rectSize.first,
                _rectSize.second * float(_nbSpriteStartY), _rectSize.first, _rectSize.second));
    } else
        if (_sprite.getTextureRect().left - _rectSize.first >= 0)
            _sprite.setTextureRect(sf::Rect<int>(_sprite.getTextureRect().left - _rectSize.first,
                _rectSize.second * float(_nbSpriteStartY), _rectSize.first, _rectSize.second));
}
