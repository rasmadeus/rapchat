#include <gtest/gtest.h>
#include <message.h>

class MessageUnitTest : public testing::TestWithParam<std::string>
{
protected:
    void SetUp() override
    {
        m_action = GetParam();
    }

protected:
    std::string m_action;
};

TEST_P(MessageUnitTest, Check_Action_Via_Message_Constructor)
{
    auto const message = rapchat::Message{ m_action };
    ASSERT_EQ(m_action, message.action());
}

TEST_P(MessageUnitTest, Check_Action_Via_Message_Set_Method)
{
    auto message = rapchat::Message{};
    message.setAction(m_action);
    ASSERT_EQ(m_action, message.action());
}

INSTANTIATE_TEST_SUITE_P
(
    MessageUnitTestCases,
    MessageUnitTest,
    ::testing::Values(
        "NotEmptyAction",
        ""
    )
);
