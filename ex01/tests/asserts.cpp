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

void ERROR_MESSAGE(std::string expected, std::string result)
{
    std::cerr << std::endl << "EXPECTED: " << std::endl;
    std::cerr << expected << std::endl;
    std::cerr << "---------------------------------------";
    std::cerr << std::endl << "RESULT: " << std::endl;
    std::cerr << result << std::endl;
}

void ASSERT_STREQ(std::string expected, std::string result)
{
    ASSERT_TRUE(expected == result);
    if (expected != result) {
        ERROR_MESSAGE(expected, result);
    }
}

void ASSERT_EQ(int expected, int result)
{
    ASSERT_TRUE(expected == result);
    if (expected != result) {
        ERROR_MESSAGE(std::to_string(expected), std::to_string(result));
    }
}
#endif