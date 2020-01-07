/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** SFML Display
*/

#include "SFML.hpp"

rtype::SFML::SFML()
{
    _isDeleting = false;
    _isShooting = false;
    _entities = std::vector<SFMLEntity *>();
    _window = new sf::RenderWindow(sf::VideoMode(WIN_W, WIN_H),
        "RType", sf::Style::Fullscreen);
    _event = new sf::Event;
    _window->setFramerateLimit(FRAMERATE);
    _clock = sf::Clock();
}

rtype::SFML::~SFML()
{
    clear();
    _window->close();
    delete _event;
}

void rtype::SFML::deleteEntity(const std::string &name)
{
    auto toDestroy = _entities.begin();

    for (auto entity : _entities) {
        if (entity->getName() == name) {
            delete(*toDestroy);
            _entities.erase(toDestroy);
        }
        toDestroy++;
    }
}

rtype::action rtype::SFML::getAction()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        return QUIT;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
        return ENTER;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        return SHOOT;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        for (auto &entity : _entities) {
            if (entity->getType() == SPRITESHEET)
                if (_clock.getElapsedTime().asSeconds() > 0.5f) {
                    entity->nextSprite(true);
                    _clock.restart();
                }
        }
        return UP;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        for (auto &entity : _entities) {
            if (entity->getType() == SPRITESHEET)
                if (_clock.getElapsedTime().asSeconds() > 0.2f) {
                    entity->nextSprite(false);
                    _clock.restart();
                }
        }
        return DOWN;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        return LEFT;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        return RIGHT;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace))
        _isDeleting = true;
    while (_window->pollEvent(*_event)) {
        if (_event->type == sf::Event::TextEntered)
            for (auto &entity : _entities)
                if (entity->getType() == INPUT_TYPE &&
                    ((_event->text.unicode >= '0' && _event->text.unicode <= '9') || _event->text.unicode == '.') &&
                    entity->getContent().size() < 16)
                    entity->changeContent(entity->getContent() + char(_event->text.unicode));
        if (sf::Event::KeyReleased == _event->type && _isDeleting) {
            for (auto &entity : _entities)
                if (entity->getType() == INPUT_TYPE)
                    entity->changeContent(entity->getContent().substr(0, entity->getContent().size() - 1));
            _isDeleting = false;
        }
    }
    for (auto &entity : _entities) {
        if (entity->getType() == BUTTON && entity->getName() == "QUIT" && entity->isClick())
            return QUIT;
        if (entity->getType() == BUTTON && entity->getName() == "START_GAME" && entity->isClick())
            return START_GAME;
        else if (entity->getType() == BUTTON && entity->getName() == "PLAY" && entity->isClick())
            return ENTER;
        else if (entity->getType() == BUTTON && entity->getName() == "MENU" && entity->isClick())
            return MENU;
        else if (entity->getType() == BUTTON && entity->getName() == "RESUME" && entity->isClick())
            return RESUME;
        else if (entity->getType() == BUTTON) {
            if (entity->isHover())
                entity->getText().setFillColor(sf::Color(255, 255, 255));
            else
                entity->getText().setFillColor(sf::Color(0, 49, 196));
        }
    }
    return UNDEFINED;
}

void rtype::SFML::updatePos(const std::string &name,
    const std::pair<float, float> &pos)
{
    for (auto &entity : _entities)
        if (entity->getName() == name)
            entity->setPos(pos);
}

void rtype::SFML::setEntity(const std::string& name, const std::string& content,
    const std::pair<float, float> &pos, rtype::type type, float resize, const std::pair<float, float> &rectSize,
    int nbSprite, int nbSpriteStartX, int nbSpriteStartY)
{
    bool setNew = true;

    for (auto &entity : _entities)
        if (entity->getName() == name) {
            updatePos(name, pos);
            entity->changeContent(content);
            setNew = false;
            break;
        }
    if (setNew)
        _entities.push_back(new SFMLEntity(name, content, pos, type, resize, rectSize, nbSprite, nbSpriteStartX, nbSpriteStartY));
}

void rtype::SFML::clear()
{
    while (!_entities.empty()) {
        delete(*_entities.begin());
        _entities.erase(_entities.begin());
    }
}

void rtype::SFML::display()
{
    _window->clear(sf::Color::Black);
    for (auto entity : _entities) {
        entity->resizePos(_window->getSize());
        if (entity->getType() == SPRITE || entity->getType() == SPRITESHEET)
            _window->draw(entity->getSprite());
        else if (entity->getType() == TEXT || entity->getType() == TEXT_ERROR || entity->getType() == BUTTON || entity->getType() == INPUT_TYPE)
            _window->draw(entity->getText());
    }
    _window->display();
}

std::string rtype::SFML::getContentEntity(const std::string &name)
{
    for (auto entity : _entities)
        if (entity->getName() == name)
            return entity->getContent();
    return "";
}
