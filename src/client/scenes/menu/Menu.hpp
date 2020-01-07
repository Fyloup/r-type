/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** Menu Class Prototype
*/

#ifndef OOP_RTYPE_2018_MENU_HPP
#define OOP_RTYPE_2018_MENU_HPP

#include <string>
#include "Game.hpp"
#include "SFML.hpp"
#include "IScene.hpp"

namespace rtype {
    class Game;
    class Menu : public IScene {
    public:
        explicit Menu(rtype::SFML &resources);
        Menu(rtype::SFML &resources, rtype::IScene *scene);
        ~Menu() override;

        rtype::action getEvent() const override;
        IScene *update() override;
        void display() override;
    private:
        rtype::SFML &_graph;
    };
}

#endif //OOP_RTYPE_2018_MENU_HPP