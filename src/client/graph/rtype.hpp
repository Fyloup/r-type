/*
** EPITECH PROJECT, 2018
** CPP_rtype_2019
** File description:
** description
*/

#ifndef CPP_RTYPE_2019_RTYPE_HPP
#define CPP_RTYPE_2019_RTYPE_HPP

#include <string>

namespace rtype {
    enum type {
        SPRITE,
        SPRITESHEET,
        TEXT,
        BUTTON,
        TEXT_ERROR,
        INPUT_TYPE
    };

    enum action {
        RESUME,
        UNDEFINED,
        UP,
        DOWN,
        LEFT,
        RIGHT,
        SHOOT,
        QUIT,
        START_GAME,
        QUIT_GAME,
        ENTER,
        MENU
    };
}

#endif //CPP_RTYPE_2019_RTYPE_HPP
