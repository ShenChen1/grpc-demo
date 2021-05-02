#include "demo_api.h"
#include <gmock/gmock.h>
#include <gtest/gtest.h>

TEST(DummyTest, CheckNothing)
{
    ASSERT_EQ(0, 0);
}

TEST(DummyRun, CheckReturnedValue)
{
    const char *request = "Peter";
    char *response = nullptr;
    ASSERT_EQ(0, demo_run(request, &response));
    ASSERT_NE(nullptr, response);
    EXPECT_STREQ("Hello Peter", response);
    free(response);
}