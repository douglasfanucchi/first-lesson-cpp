#include <PhoneBook.hpp>
#include <asserts.hpp>

void test_should_demonstrates_phonebook_creation()
{
    PhoneBook phonebook;

    ASSERT_EQ(0, phonebook.size());
}

void test_should_push_contact_to_the_back_of_phonebook()
{
    PhoneBook phonebook;
    Contact contact, contact2;
    const Contact *contacts = phonebook.getContacts();
    contact.setPhoneNumber("11999999999");
    contact2.setPhoneNumber("11888888888");
    std::string first_expected = "11999999999";
    std::string second_expected = "11888888888";

    phonebook.push(contact);
    phonebook.push(contact2);
    std::string first_result = contacts[0].getPhoneNumber();
    std::string second_result = contacts[1].getPhoneNumber();

    ASSERT_STREQ(first_expected, first_result);
    ASSERT_STREQ(second_expected, second_result);
}

void test_should_add_new_contact_and_chages_phonebooks_size()
{
    PhoneBook phonebook;
    Contact first, second, third;

    phonebook.push(first);
    phonebook.push(second);
    phonebook.push(third);

    ASSERT_EQ(3, phonebook.size());
}

void RUN_PHONEBOOK_SUITE()
{
    test_should_demonstrates_phonebook_creation();
    test_should_add_new_contact_and_chages_phonebooks_size();
    test_should_push_contact_to_the_back_of_phonebook();
}
