#ifndef PHONEBOOK_H
# define PHONEBOOK_H
#include <Contact.hpp>

class PhoneBook
{
    Contact contacts[8];
    int _size;

    public:
        PhoneBook();
        int size() const;
        void push(Contact);
        const Contact *getContacts() const;
        std::string retrieveINLINEContactInfo(int);
        std::string retrieveContactInfo(int);
};
#endif
