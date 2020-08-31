#pragma once

#include <chrono>
#include <iostream>

namespace rapchat
{
    class FeatureTest
    {
    public:
        FeatureTest(std::string &&name)
            : m_name{std::move(name)}
        {
        }

        virtual ~FeatureTest() = default;

        void run()
        {
            std::cout << "================================= Start " << m_name << " test\n";
            const auto start = std::chrono::steady_clock::now();
            job();
            const auto end = std::chrono::steady_clock::now();
            const auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
            std::cout << "================================= Stop " << m_name << " test. It took " << duration << "millisec.\n";
        }

    protected:
        virtual void job() = 0;

    private:
        std::string m_name;
    };
} // namespace rapchat