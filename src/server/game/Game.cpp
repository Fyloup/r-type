/*
** EPITECH PROJECT, 2022
** CPP_rtype_2019
** File description:
** Created by Philippe Sirvente,
*/

//Players position x = 100  y = 500
//Enemies position x = 1000 y = 100

#include "Game.hpp"

Game::Game(int numOfPlayers) : _numOfPlayers(numOfPlayers)
{
    int players = _numOfPlayers;
    _engine = new Engine;

    if (_numOfPlayers > 4)
        players = 4;
    else if(_numOfPlayers < 1)
        players = 1;
    std::cout << players << std::endl;
    for (int i = 0; i < players; i++) {
        Entity player(entity::type::PLAYER, entity::killable::KILLABLE, getPosX(100), getPosY(500));
        _engine->addEntity(player);
    }

    int x = 1000;
    int y = 100;

    for (int i = 0; i < NUM_OF_MONSTERS; i++) {
        Entity enemy(entity::type::ENEMY, entity::killable::KILLABLE, getPosX(x), getPosY(y));
        _engine->addEntity(enemy);
        x += 100;
        y += 100;
    }
}

Game::~Game() = default;

void Game::update(const std::vector<protocol::InputType> &inputs)
{
  for (auto &it : getEngine().getEnemyEntityVector()) {

        it.setCoords(it.getCoords().first + float(1), it.getCoords().second);
    }
}

Engine Game::getEngine()
{
    return *_engine;
}

std::string Game::getEntitiesBufferStringify()
{
    std::stringstream ss;

    for (auto it = getEngine().getEntityVector().begin(); it != getEngine().getEntityVector().end(); it++) {
        std::cout << it->stringify() << std::endl;
        ss << it->stringify() + "#";
    }
    std::cout << ss.str() << std::endl;
    return ss.str();
}