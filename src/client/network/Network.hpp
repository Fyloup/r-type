/*
** EPITECH PROJECT, 2022
** r-type_client
** File description:
** Network for client
*/

#ifndef R_TYPE_CLIENT_NETWORK_HPP
#define R_TYPE_CLIENT_NETWORK_HPP

#include <sstream>
#include <SFML/Network.hpp>
#include <Protocol.hpp>
#include "SFML.hpp"

namespace rtype {
    class Network {
    public:
        void setIp(const std::string &);
        int send(sf::Packet);
        void receive();
        void handle_receive(const std::string &);
        bool getConnection() const;
        std::string getMessage() const;
        int getPacket() const;
        static Network *getNetwork();
        ~Network();
        template <typename x> sf::Packet preparePacket(x structure, protocol::PacketType protocol, const std::string &message) {
            x *packet = new x();
            packet->type = protocol;
            std::stringstream ss;
            ss << packet->type << ":" << message;
            sf::Packet sfPacket;
            sfPacket << ss.str();
            return (sfPacket);
        };

    private:
        static Network *network;
        Network();
        sf::IpAddress _serverIp;
        sf::IpAddress _saveIp;
        unsigned short _serverPort;
        sf::UdpSocket _socket;
        bool _isConnected;
        std::string _message;
        int _packet;
    };
}

#endif //R_TYPE_CLIENT_NETWORK_HPP
