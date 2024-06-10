#ifndef PROGRAM_H
# define PROGRAM_H

#include <iostream>
#include <PhoneBook.hpp>

class Program
{
    bool _isRunning;
    PhoneBook phonebook;

    public:
        Program();
        bool isRunning() const;
        void run(std::string);
};

#endif