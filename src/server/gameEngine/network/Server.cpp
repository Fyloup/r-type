/*
** EPITECH PROJECT, 2018
** CPP_rtype_2019
** File description:
** description
*/

#include <regex>
#include "Server.hpp"
#include "Protocol.hpp"
#include "../../game/Game.hpp"

Server::Server(boost::asio::io_service& io_service, int port) : _socket(io_service, boost::asio::ip::udp::endpoint(boost::asio::ip::udp::v4(), port)), _isGameLaunched(false)
{
    start_recv();
}

void Server::start_recv()
{
    if (getLaunch()) {
        boost::shared_ptr<std::string> message(new std::string(std::to_string(protocol::ENTITIES) + ":" + _game->getEntitiesBufferStringify()));
        for (auto &it : _endpointVector) {
            _socket.async_send_to(boost::asio::buffer(*message), it,
                boost::bind(&Server::handle_send, this, message,
                    boost::asio::placeholders::error,
                    boost::asio::placeholders::bytes_transferred));
        }
        _game->update(_inputVect);
    }
    _socket.non_blocking(true);
    _socket.async_receive_from(boost::asio::buffer(_recv_buffer), _remote_endpoint,
        boost::bind(&Server::handle_recv, this, boost::asio::placeholders::error,
            boost::asio::placeholders::bytes_transferred));
}

void Server::handle_recv(const boost::system::error_code& error, std::size_t bytes_transferred)
{
    if (!error || error == boost::asio::error::message_size)
    {
        std::regex expr(R"(([0-6]):((.+)?).?$)");
        std::smatch match;
        std::string buff(_recv_buffer.begin()+4, _recv_buffer.begin()+bytes_transferred);

        if (regex_match(buff, match, expr)) {
            switch (std::stoi(match[1])) {
            case protocol::CONNECTION: {
                if (match[2] == "Hello!") {
                    _endpointVector.push_back(_remote_endpoint);
                    std::cout << "packet received : Connection" << std::endl
                        << "Message : " << match[2] << std::endl
                        << "remote endpoint ip : "
                        << _remote_endpoint.address().to_string() << std::endl
                        << "remote endpoint port : " << _remote_endpoint.port()
                        << std::endl;
                    boost::shared_ptr<std::string> message(new std::string(buff));
                    _socket.async_send_to(boost::asio::buffer(*message), _remote_endpoint,
                        boost::bind(&Server::handle_send, this, message,
                            boost::asio::placeholders::error,
                            boost::asio::placeholders::bytes_transferred));
                }
                break;
            }
            case protocol::QUIT: {
                auto tmp = _endpointVector.begin();
                for (auto &it: _endpointVector) {
                    if (it.address() == _remote_endpoint.address() && it.port() == _remote_endpoint.port()) {
                        _endpointVector.erase(tmp);
                        break;
                    }
                    tmp++;
                }
                std::cout << "packet received : Quit" << std::endl
                    << "Message : " << match[2] << std::endl
                    << "remote endpoint ip : "
                    << _remote_endpoint.address().to_string() << std::endl
                    << "remote endpoint port : " << _remote_endpoint.port()
                    << std::endl;
                break;
            }
            case protocol::INPUT: {
                int i = 0;
                auto tmp = _endpointVector.begin();
                for (auto &it: _endpointVector) {
                    if (it.address() == _remote_endpoint.address() && it.port() == _remote_endpoint.port()) {
                        _inputVect.at(i) = static_cast<protocol::InputType>(std::stoi(match[2]));
                        break;
                    }
                    tmp++;
                    i++;
                }
                std::cout << "packet received : Input" << std::endl
                    << "Message : " << match[2] << std::endl
                    << "remote endpoint ip : "
                    << _remote_endpoint.address().to_string() << std::endl
                    << "remote endpoint port : " << _remote_endpoint.port()
                    << std::endl;
                break;
            }
            case protocol::START_GAME: {
                _isGameLaunched = true;
                for (int i = 0; i <= getnbPlayer(); i++) {
                    _inputVect.push_back(protocol::UNDEFINED);
                }
                _game = new Game(getnbPlayer());
                std::cout << "packet received : Start Game" << std::endl
                    << "Message : " << match[2] << std::endl
                    << "remote endpoint ip : "
                    << _remote_endpoint.address().to_string() << std::endl
                    << "remote endpoint port : " << _remote_endpoint.port()
                    << std::endl;
                boost::shared_ptr<std::string> message(new std::string(
                    std::to_string(protocol::START_GAME) + ":" +
                        std::to_string(_endpointVector.size())));
                for (auto &it : _endpointVector) {
                    _socket.async_send_to(boost::asio::buffer(*message), it,
                        boost::bind(&Server::handle_send, this, message,
                            boost::asio::placeholders::error,
                            boost::asio::placeholders::bytes_transferred));
                }
              break;
            }
            default: {
                std::cout << "packet received : Unknown" << std::endl
                    << "remote endpoint ip : "
                    << _remote_endpoint.address().to_string() << std::endl
                    << "remote endpoint port : " << _remote_endpoint.port()
                    << std::endl;
                break;
            }
            }
        }
    }
    start_recv();
}

void Server::handle_send(boost::shared_ptr<std::string> message,
    const boost::system::error_code &error, std::size_t bytes_transferred)
{
    start_recv();
}

bool Server::getLaunch()
{
    return _isGameLaunched;
}

int Server::getnbPlayer()
{
    return _endpointVector.size();
}
