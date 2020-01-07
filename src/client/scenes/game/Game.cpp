/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** Game Display
*/

#include <sstream>
#include "Game.hpp"
#include "Protocol.hpp"

rtype::Game::Game(rtype::SFML &resources)
    :   _graph(resources), _inGame(false), _inSelectIp(true), _isLoading(false), _clock(std::clock_t())
{
    _network = rtype::Network::getNetwork();
    initGame();
}

rtype::Game::Game(rtype::SFML &resources, rtype::IScene *scene)
    :   _graph(resources), _inGame(false), _inSelectIp(true), _isLoading(false), _isConnectionPacketSend(false), _clock(std::clock_t())
{
    delete(scene);
    _network = rtype::Network::getNetwork();
    initGame();
}

void rtype::Game::initGame()
{
    _graph.setEntity("WALLPAPER", WALLPAPER_GAME, std::pair<float, float>(0, 0), SPRITE);
    _graph.setEntity("IP", "Enter the server IP:", std::pair<float, float>(33, 35), TEXT);
    _graph.setEntity("INPUT_TYPE", "", std::pair<float, float>(40, 45), INPUT_TYPE);
}

rtype::Game::~Game()
{
    _graph.clear();
}

rtype::action rtype::Game::getEvent() const
{
    return _graph.getAction();
}

void rtype::Game::inGame()
{
    if (_graph.getAction() == SHOOT) {
        sf::Packet sfPacket = _network->preparePacket(protocol::Input(), protocol::INPUT, std::to_string(protocol::SHOOT)); //TODO Last?
        _network->send(sfPacket);
    }  else if (_graph.getAction() == UP) {
        sf::Packet sfPacket = _network->preparePacket(protocol::Input(), protocol::INPUT, std::to_string(protocol::UP)); //TODO Last?
        _network->send(sfPacket);
    } else if (_graph.getAction() == DOWN) {
        sf::Packet sfPacket = _network->preparePacket(protocol::Input(), protocol::INPUT, std::to_string(protocol::DOWN)); //TODO Last?
        _network->send(sfPacket);
    } else if (_graph.getAction() == RIGHT) {
        sf::Packet sfPacket = _network->preparePacket(protocol::Input(), protocol::INPUT, std::to_string(protocol::RIGHT)); //TODO Last?
        _network->send(sfPacket);
    } else if (_graph.getAction() == LEFT) {
        sf::Packet sfPacket = _network->preparePacket(protocol::Input(), protocol::INPUT, std::to_string(protocol::LEFT)); //TODO Last?
        _network->send(sfPacket);
    } else {
        sf::Packet sfPacket = _network->preparePacket(protocol::Input(), protocol::INPUT, std::to_string(protocol::UNDEFINED)); //TODO Last?
        _network->send(sfPacket);
    }
    if (_network->getPacket() == protocol::ENTITIES) {
        std::string msg = _network->getMessage();
        std::string delimiter = "#";
        std::string delimiter2 = ";";

        std::string nameEntity;
        std::string typeEntity;
        std::string colorEntity;
        std::pair<float, float> posEntity = std::pair<float, float>(0, 0);
        int nbTurn = 0;
        size_t pos = 0;
        size_t pos2 = 0;
        std::string token;
        std::string token2;
        while ((pos = msg.find(delimiter)) != std::string::npos) {
            token = msg.substr(0, pos);
            nbTurn = 0;
            while ((pos2 = token.find(delimiter2)) != std::string::npos) {
                token2 = token.substr(0, pos2);
                if (nbTurn == 0)
                    nameEntity = token2;
                else if (nbTurn == 1)
                    typeEntity = token2;
                else if (nbTurn == 2)
                    colorEntity = token2;
                else if (nbTurn == 3)
                    posEntity.first = std::stof(token2);
                token.erase(0, pos2 + delimiter2.length());
                nbTurn++;
            }
            posEntity.second = std::stof(token);
            if (typeEntity == "0") {
                if (colorEntity == "0")
                    _graph.setEntity(nameEntity, SPACESHIP, posEntity, SPRITESHEET, SPACESHIP_RESIZE,
                        std::pair<float, float>(SPACESHIP_RECT_X, SPACESHIP_RECT_Y), SPACESHIP_NB,
                        SPACESHIP_SPRITE_STABILITY, SPACESHIP_COLOR_PLAYER_1);
                else if (colorEntity == "1")
                    _graph.setEntity(nameEntity, SPACESHIP, posEntity, SPRITESHEET, SPACESHIP_RESIZE,
                        std::pair<float, float>(SPACESHIP_RECT_X, SPACESHIP_RECT_Y), SPACESHIP_NB,
                        SPACESHIP_SPRITE_STABILITY, SPACESHIP_COLOR_PLAYER_4);
                else if (colorEntity == "2")
                    _graph.setEntity(nameEntity, SPACESHIP, posEntity, SPRITESHEET, SPACESHIP_RESIZE,
                        std::pair<float, float>(SPACESHIP_RECT_X, SPACESHIP_RECT_Y), SPACESHIP_NB,
                        SPACESHIP_SPRITE_STABILITY, SPACESHIP_COLOR_PLAYER_2);
                else if (colorEntity == "3")
                    _graph.setEntity(nameEntity, SPACESHIP, posEntity, SPRITESHEET, SPACESHIP_RESIZE,
                        std::pair<float, float>(SPACESHIP_RECT_X, SPACESHIP_RECT_Y), SPACESHIP_NB,
                        SPACESHIP_SPRITE_STABILITY, SPACESHIP_COLOR_PLAYER_3);
                else
                    _graph.setEntity(nameEntity, SPACESHIP, posEntity, SPRITESHEET, SPACESHIP_RESIZE,
                        std::pair<float, float>(SPACESHIP_RECT_X, SPACESHIP_RECT_Y), SPACESHIP_NB,
                        SPACESHIP_SPRITE_STABILITY, SPACESHIP_COLOR_PLAYER_5);
            } else if (typeEntity == "1")
                _graph.setEntity(nameEntity, ENNEMY, posEntity, SPRITESHEET, ENNEMY_RESIZE,
                    std::pair<float, float>(ENNEMY_RECT_X, ENNEMY_RECT_Y), 0, ENNEMY_SPRITE_STABILITY);
            else if (typeEntity == "2")
                _graph.setEntity(nameEntity, MISSILE, posEntity, SPRITESHEET, MISSILE_RESIZE,
                    std::pair<float, float>(MISSILE_RECT_X, MISSILE_RECT_Y), 0, MISSILE_SPRITE_STABILITY);
            msg.erase(0, pos + delimiter.length());
        }
    }

}

rtype::IScene *rtype::Game::update()
{
    if (_graph.getAction() == MENU) {
        sf::Packet sfPacket = _network->preparePacket(protocol::Quit(), protocol::QUIT, "");
        _network->send(sfPacket);
        return new rtype::Menu(_graph, this);
    } else if (_graph.getAction() == ENTER && _inSelectIp) {
        _isLoading = true;
    } else if (_graph.getAction() == QUIT) {
        _graph.clear();
        _graph.setEntity("MENU", "Go back to menu", std::pair<float, float>(34, 65), BUTTON);
        _inGame = false;
    } else if (_graph.getAction() == RESUME) {
        _graph.clear();
        initGame();
        _inSelectIp = true;
    } else {
        if (_isLoading) {
            _isLoading = false;
            _graph.deleteEntity("ERROR_IP");
            _graph.setEntity("LOADING", "Loading...", std::pair<float, float>(42, 75), TEXT);
            _network->setIp(_graph.getContentEntity("INPUT_TYPE"));
            sf::Packet sfPacket = _network->preparePacket(protocol::Connection(), protocol::CONNECTION, "Hello!");
            _network->send(sfPacket);
            _clock = clock();
            _isConnectionPacketSend = true;
        }
    }
    if (_isConnectionPacketSend) {
        if (_network->getConnection()) {
            _isConnectionPacketSend = false;
            _inSelectIp = false;
            _graph.clear();
            _graph.setEntity("WALLPAPER", WALLPAPER_GAME, std::pair<float, float>(0, 0), SPRITE);
            _graph.setEntity("LOADING", "Loading...", std::pair<float, float>(42, 45), TEXT);
            _graph.setEntity("START_GAME", "Start game", std::pair<float, float>(40, 75), BUTTON);
        } else if (clock() - _clock > 150000) {
            _isConnectionPacketSend = false;
            _graph.deleteEntity("LOADING");
            _graph.setEntity("ERROR_IP", "Fail, bad ip address.", std::pair<float, float>(33, 75), TEXT_ERROR);
            _graph.setEntity("INPUT_TYPE", "", std::pair<float, float>(40, 45),
                INPUT_TYPE);
        }
    }
    if (_graph.getAction() == START_GAME) {
        sf::Packet sfPacket = _network->preparePacket(protocol::StartGame(), protocol::START_GAME, "");
        _network->send(sfPacket);
        _graph.deleteEntity("START_GAME");
        _graph.deleteEntity("LOADING");
        _inGame = true;
    }
    if (!_inSelectIp && _inGame)
        inGame();
    return this;
}

void rtype::Game::display()
{
    _graph.display();
}
