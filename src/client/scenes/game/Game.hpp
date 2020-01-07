/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** Menu Class Prototype
*/

#ifndef OOP_RTYPE_2018_GAME_HPP
#define OOP_RTYPE_2018_GAME_HPP

#include <string>
#include <IScene.hpp>
#include "Menu.hpp"
#include "SFML.hpp"
#include "Network.hpp"

namespace rtype {
    class Menu;
    class Game : public IScene {
    public:
        explicit Game(rtype::SFML &resources);
        Game(rtype::SFML &resources, rtype::IScene *scene);
        ~Game() override;

        rtype::action getEvent() const override;
        IScene *update() override;
        void display() override;
    private:
        void initGame();
        void inGame();
        rtype::SFML &_graph;
        bool _inGame;
        bool _inSelectIp;
        bool _isLoading;
        bool _isConnectionPacketSend;
        rtype::Network *_network;
        std::clock_t _clock;
    };
}

#endif //OOP_RTYPE_2018_GAME_HPP