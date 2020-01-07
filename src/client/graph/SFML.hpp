/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** SFML Class Prototype
*/

#ifndef OOP_RTYPE_2018_SFML_HPP
#define OOP_RTYPE_2018_SFML_HPP

#include <zconf.h>

#include "SFMLEntity.hpp"
#include "IGraph.hpp"

namespace rtype {
    class SFML : public rtype::IGraph {
    public:
        SFML();
        ~SFML() override;

        rtype::action getAction() override;
        void setEntity(const std::string &name, const std::string &content, const std::pair<float, float> &pos,
            rtype::type type, float resize = 1, const std::pair<float, float> &rect_size = std::pair<float, float>(0, 0),
                int nbSprite = 0, int nbSpriteStartX = 0, int nbSpriteStartY = 0) override;
        void deleteEntity(const std::string &) override;
        void updatePos(const std::string &name, const std::pair <float, float> &pos) override;
        void clear() override;
        std::string getContentEntity(const std::string &name);

        void display() override;

    private:
        bool _isDeleting;
        bool _isShooting;
        sf::RenderWindow *_window;
        sf::Event *_event;
        std::vector<SFMLEntity *> _entities;
        sf::Clock _clock;
    };
}

#endif //OOP_RTYPE_2018_SFML_HPP