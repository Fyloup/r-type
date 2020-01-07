/*
** EPITECH PROJECT, 2022
** CPP_rtype_2019
** File description:
** Created by Philippe Sirvente,
*/

#ifndef CPP_RTYPE_2019_ENGINE_HPP
#define CPP_RTYPE_2019_ENGINE_HPP

#include <iostream>
#include <vector>
#include "../entity/Entity.hpp"

class Engine {

    public:

        Engine();
        ~Engine();

        void addEntity(Entity newEntity);
        void addEntities() {}
        template<typename First, typename ... Entities>
        void addEntities(First arg, const Entities&... rest) {
            addEntity(arg);
            addEntities(rest...);
        }
        std::vector<Entity> getEntityVector();
        std::vector<Entity> getPlayerEntityVector();
        std::vector<Entity> getEnemyEntityVector();
        std::vector<Entity> getOtherEntityVector();

        //Network methods
        void Send();
        void Receive();
        void setReceivedData(std::string data);

        void DestroyEntity(Entity entity);
        void DestroyAllEntities();

    private:

        std::vector<Entity> _entityVector;
        std::vector<Entity> _playerEntityVector;
        std::vector<Entity> _enemyEntityVector;
        std::vector<Entity> _otherEntityVector;
        std::string _receivedData;
};

#endif //CPP_RTYPE_2019_ENGINE_HPP
