/*
** EPITECH PROJECT, 2022
** CPP_rtype_2019
** File description:
** Created by Philippe Sirvente,
*/

#ifndef CPP_RTYPE_2019_ENTITY_HPP
#define CPP_RTYPE_2019_ENTITY_HPP

#include <string>
#include <iostream>
#include <sstream>
#include <vector>

#include <chrono>
#include <thread>

template <typename x>
float getPosX(x position) {
    float tmp = position;
    float res = (tmp / 1920) * 100;
    return res;
}

template <typename y>
float getPosY(y position) {
    float tmp = position;
    float res = (tmp / 1080) * 100;
    return res;
}

namespace entity {

    enum type {
        PLAYER, // 0
        ENEMY,  // 1
        OTHER   // 2
    };

    enum physicalProperty {
        SOLID, // 0
        FLUID  // 1
    };

    enum spatialProperty {
        MOVABLE, // 0
        STATIC   // 1
    };

    enum killable {
        NOT_KILLABLE, // 0
        KILLABLE      // 1
    };

    enum color {
        BLUE,   // 0
        RED,    // 1
        YELLOW, // 2
        GREEN,  // 3
        BLACK   // 4
    };
};

class Entity {

    public:

        Entity(
            entity::type type = entity::type::OTHER,
            entity::killable isKillable = entity::killable::KILLABLE,
            float posX = 0, float posY = 0);
        ~Entity();

        void setCoords(float vectorX, float vectorY);

        int getId();
        entity::type getType();
        entity::killable getKillableProperty();
        entity::color getColor();
        std::pair<int, int> getCoords();
        static int getNumOfColors();
        static int getNumOfEntities();

        void printInfo();

        std::string stringify();

    private:

        int _Id;
        entity::type _type;
        entity::physicalProperty _prop1;
        entity::spatialProperty _prop2;
        entity::killable _killable;
        entity::color _color;
        float _posX;
        float _posY;
        static int _numOfEntities;
        static int _numOfColors;
};

#endif //CPP_RTYPE_2019_ENTITY_HPP