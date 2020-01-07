/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** Menu Display
*/

#include <sstream>
#include "Menu.hpp"
#include "Network.hpp"
#include "Protocol.hpp"

rtype::Menu::Menu(rtype::SFML &resources)
    :   _graph(resources)
{
    _graph.setEntity("WALLPAPER", WALLPAPER_MENU, std::pair<float, float>(0, 0), SPRITE);
    _graph.setEntity("PLAY", "Play", std::pair<float, float>(70, 60), BUTTON);
    _graph.setEntity("QUIT", "Quit", std::pair<float, float>(70, 80), BUTTON);
}

rtype::Menu::Menu(rtype::SFML &resources, rtype::IScene *scene)
    :   _graph(resources)
{
    delete(scene);
    _graph.setEntity("WALLPAPER", WALLPAPER_MENU, std::pair<float, float>(0, 0), SPRITE);
    _graph.setEntity("PLAY", "Play", std::pair<float, float>(70, 60), BUTTON);
    _graph.setEntity("QUIT", "Quit", std::pair<float, float>(70, 80), BUTTON);
}

rtype::Menu::~Menu()
{
    _graph.clear();
}

rtype::action rtype::Menu::getEvent() const
{
    if (_graph.getAction() == QUIT)
        return QUIT_GAME;
    return _graph.getAction();
}

rtype::IScene *rtype::Menu::update()
{
    if (_graph.getAction() == ENTER)
        return new rtype::Game(_graph, this);
    return this;
}

void rtype::Menu::display()
{
    _graph.display();
}