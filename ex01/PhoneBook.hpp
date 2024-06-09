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
};
#endif
