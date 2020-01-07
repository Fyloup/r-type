/*
** EPITECH PROJECT, 2022
** r-type_client
** File description:
** Network for client
*/

#include <regex>
#include "Network.hpp"
#include "Protocol.hpp"

rtype::Network *rtype::Network::network = nullptr;

rtype::Network *rtype::Network::getNetwork()
{
    if (network == nullptr) {
        network = new Network();
    }
    return network;
}

rtype::Network::Network() : _serverPort(COM_PORT), _isConnected(false), _message(""), _packet(-1)
{
    if (_socket.bind(0) != sf::Socket::Done) {
        std::cerr << "Couldn't bind socket" << std::endl;
        exit(84);
    }
    _socket.setBlocking(false);
}

rtype::Network::~Network()
{
    delete network;
}

void rtype::Network::setIp(const std::string &ip)
{
    _serverIp = sf::IpAddress(ip);
    _saveIp = _serverIp;
}

int rtype::Network::send(sf::Packet packet)
{
    auto status = _socket.send(packet, _serverIp, _serverPort);
    return status;
}

void rtype::Network::receive()
{
    char data[4096];
    std::size_t received;

    if (_socket.receive(data, 4096, received, _serverIp, _serverPort) != sf::Socket::Done) {
        _serverIp = _saveIp;
        _serverPort = COM_PORT;
    } else {
        std::string str(data);
        handle_receive(str);
    }
}

void rtype::Network::handle_receive(const std::string &str)
{
    std::regex expr(R"(([0-6]):((.+)?).?$)");
    std::smatch match;

    if (regex_match(str, match, expr)) {
        switch (std::stoi(match[1])) {
        case protocol::CONNECTION: {
            if (match[2] == "Hello!")
                _isConnected = true;
            break;
        }
        case protocol::ENTITIES: {
            _packet = protocol::ENTITIES;
            _message = match[2];
            break;
        }
        case protocol::MESSAGE: {
            _packet = protocol::MESSAGE;
            _message = match[2];
            break;
        }
        case protocol::START_GAME: {
            _packet = protocol::START_GAME;
            _message = match[2];
            break;
        }
        default:
            break;
        }
    } else {
        _packet = -1;
    }
}

bool rtype::Network::getConnection() const
{
    return _isConnected;
}

int rtype::Network::getPacket() const
{
    return _packet;
}

std::string rtype::Network::getMessage() const
{
    return _message;
}