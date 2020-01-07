/*
** EPITECH PROJECT, 2018
** CPP_rtype_2019
** File description:
** description
*/

#ifndef CPP_RTYPE_2019_SERVEUR_HPP
#define CPP_RTYPE_2019_SERVEUR_HPP

#include <ctime>
#include <iostream>
#include <string>
#include <chrono>
#include <ctime>
#include <boost/bind.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/asio.hpp>
#include "Protocol.hpp"
#include "../../game/Game.hpp"

class Server {
    public:
        Server(boost::asio::io_service& io_service, int port);
        bool getLaunch();
        int getnbPlayer();
    private:
        void start_recv();
        void handle_recv(const boost::system::error_code& error, std::size_t bytes_transferred);
        void handle_send(boost::shared_ptr<std::string> message, const boost::system::error_code& error, std::size_t bytes_transferred);

        boost::asio::ip::udp::socket _socket;
        boost::asio::ip::udp::endpoint _remote_endpoint;
        std::vector<boost::asio::ip::udp::endpoint> _endpointVector;
        std::array<unsigned char, 4096> _recv_buffer;
        bool _isGameLaunched;
        std::vector<protocol::InputType> _inputVect;
        Game *_game;
};

#endif //CPP_RTYPE_2019_SERVEUR_HPP
