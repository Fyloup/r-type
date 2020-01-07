/*
** EPITECH PROJECT, 2018
** CPP_rtype_2019
** File description:
** description
*/

#include "TestGame.hpp"

int main()
{
    TestGame game();
    game.initAllEntities();
    game.loop();
    game.destroyAllEntities();
    return 0;
}