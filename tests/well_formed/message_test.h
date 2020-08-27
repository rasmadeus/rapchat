#include <gtest/gtest.h>
#include <message.h>

class MessageUnitTest : public testing::TestWithParam<std::string>
{
protected:
    void SetUp() override;

protected:
    std::string m_action;
};
