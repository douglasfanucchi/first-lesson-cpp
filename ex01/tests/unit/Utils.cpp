#include <Utils.hpp>
#include <asserts.hpp>

void test_should_call_trim_passing_a_string_with_empty_spaces_at_the_beggining_and_expects_the_string_without_it()
{
    std::string input("            my text");
    std::string expected("my text");

    std::string result = Utils::trim(input);

    ASSERT_STREQ(expected, result);
}

void test_should_call_trim_passing_a_string_with_empty_spaces_at_the_end_and_expects_the_string_without_it()
{
    std::string input("my text             ");
    std::string expected("my text");

    std::string result = Utils::trim(input);

    ASSERT_STREQ(expected, result);
}

void test_should_call_trim_passing_empty_spaces_into_the_middle_of_string_and_expects_the_string_without_it()
{
    std::string input("my            text");
    std::string expected("my text");

    std::string result = Utils::trim(input);

    ASSERT_STREQ(expected, result);
}

void RUN_UTILS_SUITE()
{
    test_should_call_trim_passing_a_string_with_empty_spaces_at_the_beggining_and_expects_the_string_without_it();
    test_should_call_trim_passing_a_string_with_empty_spaces_at_the_end_and_expects_the_string_without_it();
    test_should_call_trim_passing_empty_spaces_into_the_middle_of_string_and_expects_the_string_without_it();
}