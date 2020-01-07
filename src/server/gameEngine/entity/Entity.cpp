/*
** EPITECH PROJECT, 2022
** CPP_rtype_2019
** File description:
** Created by Philippe Sirvente,
*/

#include "Entity.hpp"

Entity::Entity(entity::type type, entity::killable isKillable, float posX, float posY)
    : _type(type), _killable(isKillable), _posX(posX), _posY(posY)
{
    _Id = _numOfEntities;
    _numOfEntities++;
    if (type == entity::type::PLAYER) {
        _prop1 = entity::physicalProperty::SOLID;
        _prop2 = entity::spatialProperty::MOVABLE;
        for (int it = entity::color::BLUE; it != entity::color::BLACK; it++) {
            if (it == _numOfColors) {
                _color = static_cast<entity::color>(it);
                break;
            }
        }
        _numOfColors++;
    } else {
        _prop1 = entity::physicalProperty::SOLID;
        _prop2 = entity::spatialProperty::MOVABLE;
        _color = entity::color::BLACK;
    }
}

Entity::~Entity()
{
}

void Entity::setCoords(float vectorX, float vectorY)
{
    _posX = vectorX;
    _posY = vectorY;
}

int Entity::getId()
{
    return _Id;
}

entity::type Entity::getType()
{
    return _type;
}

entity::killable Entity::getKillableProperty()
{
    return _killable;
}

entity::color Entity::getColor()
{
    return _color;
}

std::pair<int, int> Entity::getCoords()
{
    std::pair<int, int> coords;

    coords.first = _posX;
    coords.second = _posY;
    return coords;
}

int Entity::getNumOfColors()
{
    return _numOfColors;
}

int Entity::getNumOfEntities()
{
    return _numOfEntities;
}

void Entity::printInfo()
{
    std::cout << "-------------------" << std::endl;
    std::cout << "ID: " << _Id << std::endl;
    std::cout << "Type: " << _type << std::endl;
    std::cout << "Physical property: " << _prop1 << std::endl;
    std::cout << "Spatial property: " << _prop2 << std::endl;
    std::cout << "Is entity killable: " << _killable << std::endl;
    std::cout << "Color: " << _color << std::endl;
    std::cout << "Spawned at: " << _posX << ", " << _posY << std::endl;
    std::cout << "-------------------" << std::endl;
}

std::string Entity::stringify()
{
    std::stringstream ss;

    ss << _Id << ";" << _type << ";" << _color << ";" << _posX << ";" << _posY;
    return ss.str();
}