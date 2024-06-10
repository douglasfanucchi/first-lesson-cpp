#include <Program.hpp>

Program::Program() : _isRunning(true) {}

bool Program::isRunning() const
{
    return this->_isRunning;
}

void Program::run(std::string command)
{
    if (command == "EXIT") {
        this->_isRunning = false;
        return;
    }
    if (command == "ADD") {
        this->add();
        return;
    }
}

void Program::add()
{
    Contact contact;

    contact.setFirstName(
        this->getTextField("First Name", "First name cannot be empty!")
    );
    contact.setLastName(
        this->getTextField("Last Name", "Last name cannot be empty!")
    );
    contact.setNickName(
        this->getTextField("Nickname", "Nickname cannot be empty!")
    );
    contact.setPhoneNumber(
        this->getTextField("Phonenumber", "Phonenumber cannot be empty!")
    );
    contact.setDarkestSecret(
        this->getTextField("Darkest Secret", "Darkest Secret cannot be empty!")
    );

    this->phonebook.push(contact);
}

std::string Program::getTextField(std::string label, std::string validationMessage)
{
    std::string input("");
    
    while (input.size() == 0) {
        std::cout << label << ": ";
        std::getline(std::cin, input);

        if(input.size() == 0) {
            std::cout << validationMessage << std::endl;
        }
    }

    return input;
}