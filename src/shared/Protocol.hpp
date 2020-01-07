/*
** EPITECH PROJECT, 2018
** CPP_rtype_2019
** File description:
** description
*/

#ifndef CPP_RTYPE_2019_PROTOCOLE_HPP
#define CPP_RTYPE_2019_PROTOCOLE_HPP

#define COM_PORT 10001

#include <string>
#include <vector>

namespace protocol {
  typedef enum {
        UNDEFINED,
        UP,
        DOWN,
        LEFT,
        RIGHT,
        SHOOT
  } InputType;

  typedef enum {
        CONNECTION,
        QUIT,
        MESSAGE,
        START_GAME,
        INPUT,
        ENTITIES
    } PacketType;

    typedef struct {
        PacketType type;
        char name[64];
    } Connection;

    typedef struct {
        PacketType type;
        char info[64];
    } Quit;

    typedef struct {
        PacketType type;
        char message[1024];
    } Message;

    typedef struct {
        PacketType type;
        char info[64];
    } StartGame;

    typedef struct {
        PacketType type;
        int input;
    } Input;

    typedef struct {
        PacketType type;
        char json[4096];
    } Entities;

    namespace build {
        protocol::Connection *Connection(const std::string &name);
        protocol::Quit *Quit(const std::string &info);
        protocol::Message *Message(const std::string &info);
        protocol::StartGame *StartGame(const std::string &info);
        protocol::Input *Input(const int input);
        protocol::Entities *Entities(const std::string &json);
    }
}

#endif //CPP_RTYPE_2019_PROTOCOLE_HPP
