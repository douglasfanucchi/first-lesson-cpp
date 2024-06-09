#include <PhoneBook.hpp>
#include <asserts.hpp>

void test_should_demonstrates_phonebook_creation()
{
    PhoneBook phonebook;

    ASSERT_EQ(0, phonebook.size());
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
}
