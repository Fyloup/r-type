/*
** EPITECH PROJECT, 2018
** CPP_rtype_2019
** File description:
** Main server
*/

//#include <string>
//#include <boost/asio.hpp>
//#include "gameEngine/engine/engine.hpp"
//#include "gameEngine/entity/entity.hpp"
//
//int main(void)
//{
//    try {
//        boost::asio::io_service io_service;
//        std::cout << "hello server" << std::endl;
//        io_service.run();
//    }
//    catch (std::exception& e) {
//        std::cerr << e.what() << std::endl;
//        return 84;
//    }
//    return 0;
//}

/* Engine demo code
 *
 * int id = 0;
    Engine engine;

    Entity player(id, entityProperty::type::PLAYER, entityProperty::physicalProperty::SOLID, entityProperty::spatialProperty::MOVABLE, entityProperty::killable::KILLABLE, entityProperty::color::BLUE, 50, 30);
    id++;
    Entity enemy(id, entityProperty::type::ENEMY, entityProperty::physicalProperty::SOLID, entityProperty::spatialProperty::MOVABLE, entityProperty::killable::KILLABLE, entityProperty::color::BLACK, 200, 40);
    id++;
    Entity obstacle(id, entityProperty::type::OTHER, entityProperty::physicalProperty::SOLID, entityProperty::spatialProperty::STATIC, entityProperty::killable::NOT_KILLABLE, entityProperty::color::WHITE, 200, 50);
    engine.addEntity(player);
    engine.addEntity(enemy);
    engine.addEntity(obstacle);

    std::vector<Entity> tmp = engine.getEntityVector();
    for (auto it = tmp.begin(); it != tmp.end(); it++) {
        it->printInfo();
    }
    engine.DestroyAllEntities();
    std::cout << "////////" << std::endl;
    tmp = engine.getEntityVector();
    for (auto it = tmp.begin(); it != tmp.end(); it++) {
        it->printInfo();
    }
 */

//  =================================test server network UDP=================================

#include <iostream>
#include <string>
#include <boost/asio.hpp>
#include "game/Game.hpp"
#include "Protocol.hpp"
#include "gameEngine/network/Server.hpp"

int Entity::_numOfEntities = 0;
int Entity::_numOfColors = 0;

int main(void)
{
    try {
        boost::asio::io_service io_service;
        Server server(io_service, COM_PORT);
        io_service.run();
    }
    catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 84;
    }
    return 0;
}