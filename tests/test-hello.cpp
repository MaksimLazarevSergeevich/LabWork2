#include <gtest/gtest.h>
#include "include/hello.h"

TEST(hello, sayHello)
{
    Hello a;
    ASSERT_EQ("Hello", a.sayHello());
}

TEST(HelloTest, BasicAssertion)
{
    EXPECT_EQ(1, 1);
}

TEST(HelloTest, Base)
{
    EXPECT_EQ(2, 1 + 1);
}