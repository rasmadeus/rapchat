#pragma once

#include <boost/asio/io_service.hpp>
#include <boost/asio/steady_timer.hpp>
#include <chrono>
#include <iostream>

namespace rapchat
{
    inline void wait_timer()
    {
        boost::asio::io_service ioService;
        boost::asio::steady_timer timer{ioService, std::chrono::seconds{3}};

        timer.async_wait([](boost::system::error_code const &ec) {
            std::cout << "3 seconds timer fired\n";
        });

        ioService.run();
    }
} // namespace rapchat
