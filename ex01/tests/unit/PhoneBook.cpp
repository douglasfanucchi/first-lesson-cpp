#include <iostream>
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

    ASSERT_EQ(0, contacts[0].getIndex());
    ASSERT_EQ(1, contacts[1].getIndex());
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

void test_should_shift_first_contact_in_order_to_add_a_new_one_in_a_full_list_of_contacts()
{
    PhoneBook phonebook;
    Contact first, second, third, fourth, fifth, sixth, seventh, eighth, nineth, result;
    second.setFirstName("Second");
    third.setFirstName("Third");
    fourth.setFirstName("Fourth");
    fifth.setFirstName("Fifth");
    sixth.setFirstName("Sixth");
    seventh.setFirstName("Seventh");
    eighth.setFirstName("Eighth");
    nineth.setFirstName("Nineth");
    phonebook.push(first);
    phonebook.push(second);
    phonebook.push(third);
    phonebook.push(fourth);
    phonebook.push(fifth);
    phonebook.push(sixth);
    phonebook.push(seventh);
    phonebook.push(eighth);

    phonebook.push(nineth);

    ASSERT_STREQ("Second", phonebook.getContacts()[0].getFirstName());
    ASSERT_STREQ("Nineth", phonebook.getContacts()[7].getFirstName());
}

void test_should_retrieve_inline_information_about_a_certain_contact()
{
    PhoneBook phonebook;
    Contact contact;
    contact.setFirstName("Douglas");
    contact.setLastName("Fanucchi");
    contact.setNickName("sementinha do mau");
    contact.setDarkestSecret("deu em cima da ex do amigo");
    phonebook.push(contact);
    std::string expected = "         0|   Douglas|  Fanucchi|sementinh.";

    std::string result = phonebook.retrieveINLINEContactInfo(0);
    ASSERT_STREQ(expected, result);
}

void test_should_retrieve_a_not_found_message_when_trying_to_retrieve_info_about_inexistence_contact()
{
    PhoneBook phonebook;
    std::string expected = "* CONTACT NOT FOUND *";

    std::string result = phonebook.retrieveINLINEContactInfo(0);

    ASSERT_STREQ(expected, result);

    phonebook.push(Contact());
    result = phonebook.retrieveINLINEContactInfo(-1);

    ASSERT_STREQ(expected, result);
}

void test_should_retrieve_all_informations_about_a_contact()
{
    PhoneBook phonebook;
    Contact contact;
    contact.setFirstName("Douglas");
    contact.setLastName("Fanucchi");
    contact.setNickName("sementinha do mau");
    contact.setDarkestSecret("deu em cima da ex do amigo");
    contact.setPhoneNumber("11988888888");
    phonebook.push(contact);
    std::string expected = "Index: 0" + std::string("\n") +
                    "First Name: Douglas" + std::string("\n") +
                    "Last Name: Fanucchi" + std::string("\n") +
                    "Nickname: sementinha do mau" + std::string("\n") +
                    "PhoneNumber: 11988888888" + std::string("\n") +
                    "Darkest Secret: deu em cima da ex do amigo";

    std::string result = phonebook.retrieveContactInfo(0);

    ASSERT_STREQ(expected, result);
}

void test_should_retrieve_a_not_found_message_when_trying_to_retrieve_full_info_about_inexistence_contact()
{
    PhoneBook phonebook;
    std::string expected = "* CONTACT NOT FOUND *";

    std::string result = phonebook.retrieveContactInfo(0);
    ASSERT_STREQ(expected, result);

    result = phonebook.retrieveContactInfo(-1);
    ASSERT_STREQ(expected, result);
}

void RUN_PHONEBOOK_SUITE()
{
    test_should_demonstrates_phonebook_creation();
    test_should_add_new_contact_and_chages_phonebooks_size();
    test_should_push_contact_to_the_back_of_phonebook();
    test_should_shift_first_contact_in_order_to_add_a_new_one_in_a_full_list_of_contacts();
    test_should_retrieve_inline_information_about_a_certain_contact();
    test_should_retrieve_a_not_found_message_when_trying_to_retrieve_info_about_inexistence_contact();
    test_should_retrieve_all_informations_about_a_contact();
    test_should_retrieve_a_not_found_message_when_trying_to_retrieve_full_info_about_inexistence_contact();
}
