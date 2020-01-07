/*
** EPITECH PROJECT, 2018
** CPP_rtype_2019
** File description:
** Main client
*/

#include <exception>
#include <iostream>
#include <IScene.hpp>
#include "Menu.hpp"
#include "Network.hpp"

int main(int ac, char *av[])
{
    rtype::SFML resources;
    rtype::IScene *current_scene;
    rtype::Network *network = rtype::Network::getNetwork();

    network->setIp("127.0.0.1");
    try {
        current_scene = new rtype::Menu(resources);
        while (current_scene->getEvent() != rtype::QUIT_GAME) {
            network->receive();
            current_scene = current_scene->update();
            current_scene->display();
        }
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
        return 84;
    }
    delete current_scene;
    return 0;
}