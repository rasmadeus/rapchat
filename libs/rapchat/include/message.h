#pragma once
#pragma warning(disable: 4251)

#include <shared_export.h>
#include <string>

namespace rapchat
{
    class RAPCHAT_SHARED_EXPORT Message
    {
    public:
        Message() = default;
        Message(std::string&& action);
        Message(std::string const& action);

        void setAction(std::string&& action);
        void setAction(std::string const& action);
        std::string const& action() const;

    private:
        std::string m_action;
    };
}