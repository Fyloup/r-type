/*
** EPITECH PROJECT, 2022
** CPP_rtype_2019
** File description:
** Created by Philippe Sirvente,
*/

#ifndef CPP_RTYPE_2019_GAME_HPP
#define CPP_RTYPE_2019_GAME_HPP

#define NUM_OF_MONSTERS 10

#include "../gameEngine/engine/Engine.hpp"
#include "../gameEngine/entity/Entity.hpp"
#include "../../shared/Protocol.hpp"

class Game {

    public:

        Game(int numOfPlayers = 1);
        ~Game();

        void update(const std::vector<protocol::InputType>& inputs);

        Engine getEngine();

        std::string getEntitiesBufferStringify();

    private:
        Engine *_engine;
        int _numOfPlayers;
};

#endif //CPP_RTYPE_2019_GAME_HPP
