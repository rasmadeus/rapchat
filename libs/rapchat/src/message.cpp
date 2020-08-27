#include <message.h>

using namespace rapchat;

Message::Message(std::string&& action)
    : m_action{ std::move(action) }
{
}

Message::Message(std::string const& action)
    : m_action{ action }
{
}

void Message::setAction(std::string&& action)
{
    m_action = std::move(action);
}

void Message::setAction(std::string const& action)
{
    m_action = action;
}

std::string const& Message::action() const
{
    return m_action;
}
