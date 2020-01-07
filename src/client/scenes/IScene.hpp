/*
** EPITECH PROJECT, 2022
** r-type_client
** File description:
** Interface for all scenes,
*/

#ifndef R_TYPE_CLIENT_ISCENE_HPP
#define R_TYPE_CLIENT_ISCENE_HPP

#include "SFML.hpp"

namespace rtype {
    class IScene {
    public:
        virtual ~IScene() = default;

        virtual rtype::action getEvent() const = 0;
        virtual IScene *update() = 0;
        virtual void display() = 0;
    };
}

#endif //R_TYPE_CLIENT_ISCENE_HPP
