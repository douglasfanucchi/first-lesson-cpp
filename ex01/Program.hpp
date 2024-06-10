#ifndef PROGRAM_H
# define PROGRAM_H

#include <iostream>
#include <PhoneBook.hpp>

class Program
{
    bool _isRunning;
    PhoneBook phonebook;

    protected:
        void add();
        std::string formatString(std::string) const;
        std::string getTextField(std::string, std::string);

    public:
        Program();
        bool isRunning() const;
        void run(std::string);
};

#endif