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
        }
    }
    contact.setIndex(index);
    this->contacts[index] = contact;
    this->_size++;
}

const Contact *PhoneBook::getContacts() const
{
    return this->contacts;
}