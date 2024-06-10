#ifndef TESTS_H
# define TESTS_H
#include <iostream>
void ASSERT_STREQ(std::string expected, std::string result)
{
    if (expected == result) {
        std::cout << "✅";
    } else {
        std::cerr << "❌";
    }
}

void ASSERT_EQ(int expected, int result)
{
    if (expected == result) {
        std::cout << "✅";
    } else {
        std::cerr << "❌";
    }
}

void ASSERT_TRUE(bool value) {
    if (value) {
        std::cout << "✅";
    } else {
        std::cerr << "❌";
    }
}
#endif