#include <message.h>

using namespace rapchat;

Message::Message(std::string&& action)
    : m_action{ std::move(action) }
{
}

void Message::setAction(std::string&& action)
{
    m_action = std::move(action);
}

std::string const& Message::action() const
{
    return m_action;
}
