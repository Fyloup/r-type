/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** Interface for the graph
*/

#ifndef OOP_RTYPE_2018_IGRAPH_HPP
#define OOP_RTYPE_2018_IGRAPH_HPP

#include "rtype.hpp"

namespace rtype {
    class IGraph {
    public:
        virtual ~IGraph() = default;

        virtual void setEntity(const std::string &name, const std::string &content, const std::pair<float, float> &pos,
            rtype::type type, float resize, const std::pair<float, float> &rect_size, int nbSprite, int nbSpriteToStartX, int nbSpriteToStartY) = 0;
        virtual void deleteEntity(const std::string &) = 0;
        virtual rtype::action getAction() = 0;
        virtual void updatePos(const std::string &name, const std::pair <float, float> &) = 0;
        virtual void clear() = 0;

        virtual void display() = 0;
    };
}

#endif //OOP_RTYPE_2018_IGRAPH_HPP