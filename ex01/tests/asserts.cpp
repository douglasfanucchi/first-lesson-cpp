#ifndef TESTS_H
# define TESTS_H
#include <iostream>
void ASSERT_TRUE(bool value) {
    if (value) {
        std::cout << "✅";
    } else {
        std::cerr << "❌";
    }
}

void ASSERT_STREQ(std::string expected, std::string result)
{
    ASSERT_TRUE(expected == result);
}

void ASSERT_EQ(int expected, int result)
{
    ASSERT_TRUE(expected == result);
}
#endif