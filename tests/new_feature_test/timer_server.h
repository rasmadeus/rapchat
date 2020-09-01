#pragma once

#include "feature_test.h"

#include <boost/asio/buffer.hpp>
#include <boost/asio/io_service.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <boost/asio/write.hpp>
#include <ctime>
#include <string>

namespace rapchat
{
    class TimeServer: public FeatureTest
    {
    public:
        TimeServer()
            : FeatureTest{"TimeServer"}
        {
        }

    protected:
        void job() override
        {
            m_tcpAcceptor.listen();
            m_tcpAcceptor.async_accept(m_tcpSocket, std::bind(&TimeServer::acceptHandler, this, std::placeholders::_1));
            m_ioService.run();
        }

    private:
        void writeHandler(boost::system::error_code const &ec, std::size_t bytesTransferred)
        {
            if (ec) {
                std::cout << "WriteHandler error= " << ec.message() << "\n";
            }
            else {
                m_tcpSocket.shutdown(boost::asio::ip::tcp::socket::shutdown_send);
            }
        }

        void acceptHandler(boost::system::error_code const &ec)
        {
            if (ec) {
                std::cout << "AcceptHandler error= " << ec.message() << "\n";
            }
            else {
                auto now = std::time(nullptr);
                m_data = std::ctime(&now);
                boost::asio::async_write(
                    m_tcpSocket,
                    boost::asio::buffer(m_data),
                    std::bind(&TimeServer::writeHandler, this, std::placeholders::_1, std::placeholders::_2));
            }
        }

    private:
        boost::asio::io_service m_ioService;
        boost::asio::ip::tcp::endpoint m_tcpEndpoint{boost::asio::ip::tcp::v4(), 2014};
        boost::asio::ip::tcp::acceptor m_tcpAcceptor{m_ioService, m_tcpEndpoint};
        boost::asio::ip::tcp::socket m_tcpSocket{m_ioService};
        std::string m_data;
    };
} // namespace rapchat
