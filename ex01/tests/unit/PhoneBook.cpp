#include <PhoneBook.hpp>
#include <asserts.hpp>

void test_should_demonstrates_phonebook_creation()
{
    PhoneBook phonebook;

    ASSERT_EQ(0, phonebook.size());
}

void RUN_PHONEBOOK_SUITE()
{
    test_should_demonstrates_phonebook_creation();
}
