/*
** EPITECH PROJECT, 2018
** CPP_rtype_2019
** File description:
** description
*/

#ifndef CPP_RTYPE_2019_IMONSTER_HPP
#define CPP_RTYPE_2019_IMONSTER_HPP

#include <iostream>

class IMonster {
    public:
        ~IMonster() = default;


        virtual std::pair<int, int> move() = 0;
    private:
        int _lifePoint;

};

#endif //CPP_RTYPE_2019_IMONSTER_HPP
