#include <gtest/gtest.h>
#include "include/hello.h"

TEST(hello, sayHello)
{
    Hello a;
    ASSERT_EQ("Hello", a.sayHello());
    
}

TEST(HelloTest, BasicAssertion) {
    EXPECT_EQ(1, 1);
}