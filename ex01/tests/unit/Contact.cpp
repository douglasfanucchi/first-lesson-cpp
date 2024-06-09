#include <Contact.hpp>
#include <iostream>
#include <asserts.hpp>

void test_should_demonstrate_contact_creation()
{
    Contact contact("Douglas", "Fanucchi");

    std::string result = contact.getFirstName();
    std::string expected = "Douglas";
    ASSERT_STREQ(expected, result);

    result = contact.getLastName();
    expected = "Fanucchi";
    ASSERT_STREQ(expected, result);

    contact.setNickName("sementinha do mau");
    result = contact.getNickName();
    expected = "sementinha do mau";
    ASSERT_STREQ(expected, result);

    contact.setDarkestSecret("dei em cima da ex do meu amigo");
    result = contact.getDarkestSecret();
    expected = "dei em cima da ex do meu amigo";
    ASSERT_STREQ(expected, result);

    contact.setPhoneNumber("11999999999");
    result = contact.getPhoneNumber();
    expected = "11999999999";
    ASSERT_STREQ(expected, result);

    contact.setIndex(0);
    int int_result = contact.getIndex();
    int int_expected = 0;
    ASSERT_EQ(int_expected, int_result);
}

void test_should_ensure_formatted_first_name_is_properly_formatted()
{
    Contact firstNametWithLessThan10Chars("Douglas", "Fanucchi");
    std::string expected = "   Douglas";
    std::string result = firstNametWithLessThan10Chars.getFormattedFirstName();
    ASSERT_EQ(10, result.size());
    ASSERT_STREQ(expected, result);

    Contact firstNameWith10Chars("Douglas123", "Fanucchi");
    expected = "Douglas123";
    result = firstNameWith10Chars.getFormattedFirstName();
    ASSERT_EQ(10, result.size());
    ASSERT_STREQ(expected, result);

    Contact firstNameWithMoreThan10Chars("Douglas1234", "Fanucchi");
    expected = "Douglas12.";
    result = firstNameWithMoreThan10Chars.getFormattedFirstName();
    ASSERT_EQ(10, result.size());
    ASSERT_STREQ(expected, result);
}

void test_should_ensure_formatted_last_name_is_properly_formatted()
{
    Contact lastNameWithLessThan10Chars("Douglas", "Fanucchi");
    std::string expected = "  Fanucchi";
    std::string result = lastNameWithLessThan10Chars.getFormattedLastName();
    ASSERT_EQ(10, result.size());
    ASSERT_STREQ(expected, result);

    Contact lastNameWith10Chars("Douglas", "Fanucchi12");
    expected = "Fanucchi12";
    result = lastNameWith10Chars.getFormattedLastName();
    ASSERT_EQ(10, result.size());
    ASSERT_STREQ(expected, result);

    Contact lastNameWithMoreThan10Chars("Douglas", "Fanucchi123");
    expected = "Fanucchi1.";
    result = lastNameWithMoreThan10Chars.getFormattedLastName();
    ASSERT_EQ(10, result.size());
    ASSERT_STREQ(expected, result);
}

void test_should_ensure_formatted_nick_name_is_properly_formatted()
{
    Contact contact("Douglas", "Fanucchi");
    contact.setNickName("fnk");
    std::string expected = "       fnk";
    std::string result = contact.getFormattedNickName();
    ASSERT_EQ(10, result.size());
    ASSERT_STREQ(expected, result);

    contact.setNickName("sementinha");
    expected = "sementinha";
    result = contact.getFormattedNickName();
    ASSERT_EQ(10, result.size());
    ASSERT_STREQ(expected, result);

    contact.setNickName("sementinha do mau");
    expected = "sementinh.";
    result = contact.getFormattedNickName();
    ASSERT_EQ(10, result.size());
    ASSERT_STREQ(expected, result);
}

void test_should_ensure_formatted_index_is_properly_formatted()
{
    Contact contact("Douglas", "Fanucchi");
    contact.setIndex(0);
    std::string expected = "         0";
    std::string result = contact.getFormattedIndex();
    ASSERT_EQ(10, result.size());
    ASSERT_STREQ(expected, result);

    contact.setIndex(01);
    expected = "         1";
    result = contact.getFormattedIndex();
    ASSERT_EQ(10, result.size());
    ASSERT_STREQ(expected, result);

    contact.setIndex(1000000000);
    expected = "1000000000";
    result = contact.getFormattedIndex();
    ASSERT_EQ(10, result.size());
    ASSERT_STREQ(expected, result);
}

void RUN_CONTACT_SUITE()
{
    test_should_demonstrate_contact_creation();
    test_should_ensure_formatted_first_name_is_properly_formatted();
    test_should_ensure_formatted_last_name_is_properly_formatted();
    test_should_ensure_formatted_nick_name_is_properly_formatted();
    test_should_ensure_formatted_index_is_properly_formatted();
}
