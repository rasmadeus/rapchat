#pragma once

#include "feature_test.h"

#include <boost/asio/io_service.hpp>
#include <boost/asio/steady_timer.hpp>
#include <chrono>
#include <iostream>

namespace rapchat
{
    class IoServiceTimer: public FeatureTest
    {
    public:
        IoServiceTimer()
            : FeatureTest{"IoServiceTimer"}
        {
        }

    protected:
        void job() override
        {
            boost::asio::io_service ioService;
            boost::asio::steady_timer timer1{ioService, std::chrono::seconds{3}};
            boost::asio::steady_timer timer2{ioService, std::chrono::seconds{4}};

            timer2.async_wait([](boost::system::error_code const &ec) {
                std::cout << "4 seconds timer fired. Message: " << ec.message() << "\n";
            });

            timer1.async_wait([](boost::system::error_code const &ec) {
                std::cout << "3 seconds timer fired. Message: " << ec.message() << "\n";
            });

            ioService.run();
        }
    };
} // namespace rapchat
