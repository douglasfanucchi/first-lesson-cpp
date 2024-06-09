#ifndef TESTS_H
# define TESTS_H
#include <iostream>
void ASSERT_STREQ(std::string expected, std::string result)
{
    if (expected == result) {
        std::cout << ".";
    } else {
        std::cerr << "E";
    }
}

void ASSERT_EQ(int expected, int result)
{
    if (expected == result) {
        std::cout << ".";
    } else {
        std::cerr << "E";
    }
}
#endif