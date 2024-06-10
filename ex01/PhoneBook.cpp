#include <PhoneBook.hpp>

PhoneBook::PhoneBook(): _size(0) {}

int PhoneBook::size() const
{
    return this->_size;
}

void PhoneBook::push(Contact contact)
{
    int index = this->size();
    if (this->_size == 8) {
        index = 7;
        for(int i = 0; i < 7; i++) {
            this->contacts[i] = this->contacts[i + 1];
            this->contacts[i].setIndex(i);
        }
    }
    contact.setIndex(index);
    this->contacts[index] = contact;
    if (this->_size < 8)
        this->_size++;
}

const Contact *PhoneBook::getContacts() const
{
    return this->contacts;
}

std::string PhoneBook::retrieveINLINEContactInfo(int index)
{
    Contact contact;

    if (index < 0 || index > this->size() - 1) {
        return "* CONTACT NOT FOUND *";
    }

    contact = this->getContacts()[index];
    return contact.getFormattedIndex()
            + "|" + contact.getFormattedFirstName()
            + "|" + contact.getFormattedLastName()
            + "|" + contact.getFormattedNickName();
}

std::string PhoneBook::retrieveContactInfo(int index)
{
    Contact contact;

    if (index < 0 || index > this->size() - 1) {
        return "* CONTACT NOT FOUND *";
    }

    contact = this->getContacts()[index];
    return "Index: " + std::to_string(contact.getIndex()) + std::string("\n") +
            "First Name: " + contact.getFirstName() + std::string("\n") +
            "Last Name: " + contact.getLastName() + std::string("\n") +
            "Nickname: " + contact.getNickName() + std::string("\n") +
            "PhoneNumber: " + contact.getPhoneNumber() + std::string("\n") +
            "Darkest Secret: " + contact.getDarkestSecret();
}