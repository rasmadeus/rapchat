#pragma once

#include "feature_test.h"

#include <array>
#include <boost/asio/buffer.hpp>
#include <boost/asio/io_service.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <boost/asio/write.hpp>
#include <iostream>
#include <string>

namespace rapchat
{
    class PageDownloader: public FeatureTest
    {
    public:
        PageDownloader()
            : FeatureTest{"PageDownloader"}
        {
        }

    protected:
        void job() override
        {
            boost::asio::ip::tcp::resolver::query query{"theboostcpplibraries.com", "80"};
            m_resolver.async_resolve(query, std::bind(&PageDownloader::resolveHandler, this, std::placeholders::_1, std::placeholders::_2));
            m_ioService.run();
        }

    private:
        void readHandler(boost::system::error_code const &ec, std::size_t bytesTransferred)
        {
            if (ec) {
                std::cout << "ReadHandler error: " << ec.message() << "\n";
            }
            else {
                std::cout.write(m_bytes.data(), bytesTransferred);
                m_tcpSocket.async_read_some(boost::asio::buffer(m_bytes), std::bind(&PageDownloader::readHandler, this, std::placeholders::_1, std::placeholders::_2));
            }
        }

        void resolveHandler(boost::system::error_code const &ec, boost::asio::ip::tcp::resolver::results_type endpoints)
        {
            if (ec) {
                std::cout << "ResolveHandler error: " << ec.message() << "\n";
            }
            else {
                m_tcpSocket.async_connect(*endpoints.begin(), std::bind(&PageDownloader::connectHandler, this, std::placeholders::_1));
            }
        }

        void connectHandler(boost::system::error_code const &ec)
        {
            if (ec) {
                std::cout << "ConnectHandler error: " << ec.message() << "\n";
            }
            else {
                std::string const request{"GET / HTTP/1.1\r\nHost: theboostcpplibraries.com\r\n\r\n"};
                boost::asio::write(m_tcpSocket, boost::asio::buffer(request));
                m_tcpSocket.async_read_some(boost::asio::buffer(m_bytes), std::bind(&PageDownloader::readHandler, this, std::placeholders::_1, std::placeholders::_2));
            }
        }

    private:
        boost::asio::io_service m_ioService;
        boost::asio::ip::tcp::resolver m_resolver{m_ioService};
        boost::asio::ip::tcp::socket m_tcpSocket{m_ioService};
        std::array<char, 4096> m_bytes;
    };
} // namespace rapchat
