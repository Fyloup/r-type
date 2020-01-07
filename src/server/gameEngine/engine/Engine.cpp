/*
** EPITECH PROJECT, 2022
** CPP_rtype_2019
** File description:
** Created by Philippe Sirvente,
*/

#include "Engine.hpp"

Engine::Engine()
{
}

Engine::~Engine()
{
}

void Engine::addEntity(Entity newEntity)
{
    if (newEntity.getType() == entity::type::PLAYER) {
        _entityVector.push_back(newEntity);
        _playerEntityVector.push_back(newEntity);
    } else if (newEntity.getType() == entity::type::ENEMY) {
        _entityVector.push_back(newEntity);
        _enemyEntityVector.push_back(newEntity);
    } else {
        _entityVector.push_back(newEntity);
        _otherEntityVector.push_back(newEntity);
    }
}

std::vector<Entity> Engine::getEntityVector()
{
    return _entityVector;
}

std::vector<Entity> Engine::getPlayerEntityVector()
{
    return _playerEntityVector;
}

std::vector<Entity> Engine::getEnemyEntityVector()
{
    return _enemyEntityVector;
}

std::vector<Entity> Engine::getOtherEntityVector()
{
    return _otherEntityVector;
}

void Engine::Send()
{
}

void Engine::Receive()
{
}

void Engine::setReceivedData(std::string data)
{
    _receivedData = data;
}

void Engine::DestroyEntity(Entity entity)
{
    if (entity.getKillableProperty() == entity::killable::KILLABLE) {
        for (auto it = _entityVector.begin(); it != _entityVector.end(); it++) {
            if (it->getId() == entity.getId()) {
                _entityVector.erase(it);
                break;
            }
        }
    }
}

void Engine::DestroyAllEntities()
{
    _entityVector.clear();
    _playerEntityVector.clear();
    _enemyEntityVector.clear();
    _otherEntityVector.clear();
}