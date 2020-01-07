/*
** EPITECH PROJECT, 2018
** CPP_rtype_2019
** File description:
** description
*/

#include <cstring>
#include <stdexcept>
#include "Protocol.hpp"

protocol::Connection *protocol::build::Connection(const std::string &name)
{
    auto *packet = new protocol::Connection();

    if (!packet)
        throw std::runtime_error(nullptr);
    memset(packet, 0, sizeof(protocol::Connection));
    packet->type = CONNECTION;
    if (!memcpy(packet->name, name.c_str(), name.size()))
        throw std::runtime_error(nullptr);
    return packet;
}

protocol::Quit *protocol::build::Quit(const std::string & info)
{
    auto *packet = new protocol::Quit();

    if (!packet)
        throw std::runtime_error(nullptr);
    memset(packet, 0, sizeof(protocol::Quit));
    packet->type = QUIT;
    if (!memcpy(packet->info, info.c_str(), info.size()))
        throw std::runtime_error(nullptr);
    return packet;
}

protocol::Message *protocol::build::Message(const std::string & info)
{
    auto *packet = new protocol::Message();

    if (!packet)
        throw std::runtime_error(nullptr);
    memset(packet, 0, sizeof(protocol::Message));
    packet->type = MESSAGE;
    if (!memcpy(packet->message, info.c_str(), info.size()))
        throw std::runtime_error(nullptr);
    return packet;
}

protocol::StartGame *protocol::build::StartGame(const std::string & info)
{
    auto *packet = new protocol::StartGame();

    if (!packet)
        throw std::runtime_error(nullptr);
    memset(packet, 0, sizeof(protocol::StartGame));
    packet->type = START_GAME;
    if (!memcpy(packet->info, info.c_str(), info.size()))
        throw std::runtime_error(nullptr);
    return packet;
}

protocol::Input *protocol::build::Input(const int input)
{
    auto *packet = new protocol::Input();

    if (!packet)
        throw std::runtime_error(nullptr);
    memset(packet, 0, sizeof(protocol::Input));
    packet->type = INPUT;
    packet->input = input;
    return packet;
}

protocol::Entities *protocol::build::Entities(const std::string &json)
{
    auto *packet = new protocol::Entities();

    if (!packet)
        throw std::runtime_error(nullptr);
    memset(packet, 0, sizeof(protocol::Entities));
    packet->type = ENTITIES;
    if (!memcpy(packet->json, json.c_str(), json.size()))
        throw std::runtime_error(nullptr);
    return packet;
}