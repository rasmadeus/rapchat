#include "message_test.h"

void MessageUnitTest::SetUp()
{
    m_action = GetParam();
}

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

INSTANTIATE_TEST_CASE_P
(
    MessageUnitTestCases,
    MessageUnitTest,
    ::testing::Values(
        "NotEmptyAction",
        ""
    )
);