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
    if (command == "SEARCH") {
        this->search();
        return;
    }
}

void Program::add()
{
    Contact contact;

    contact.setFirstName(
        this->getTextField("First Name", "First Name cannot be empty!")
    );
    contact.setLastName(
        this->getTextField("Last Name", "Last Name cannot be empty!")
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

void Program::search()
{
    std::string index, firstName, lastName, nickName;
    int contactIndex;
    const Contact *contacts = this->phonebook.getContacts();
    Contact contact;

    index = this->formatString("INDEX");
    firstName = this->formatString("FIRST NAME");
    lastName = this->formatString("LAST NAME");
    nickName = this->formatString("NICKNAME");

    std::cout << "---------------------------------------------" << std::endl;
    std::cout << "|" << index << "|" << firstName << "|" << lastName << "|" << nickName << "|" << std::endl;
    std::cout << "---------------------------------------------" << std::endl;

    for(int i = 0; i < this->phonebook.size(); i++) {
        contact = contacts[i];
        index = contact.getFormattedIndex();
        firstName = contact.getFormattedFirstName();
        lastName = contact.getFormattedLastName();
        nickName = contact.getFormattedNickName();
        std::cout << "|" << index << "|" << firstName << "|" << lastName << "|" << nickName << "|" << std::endl;
    }
    std::cout << "---------------------------------------------" << std::endl;
    contactIndex = this->getIntField("User index to display", "* SEARCH INDEX CANNOT BE EMPTY *");
    std::cout << this->phonebook.retrieveContactInfo(contactIndex) << std::endl;
}

std::string Program::formatString(std::string string) const
{
    if (string.size() < 11) {
        int spacesToInsert = 10 - string.size();
        string.insert(0, spacesToInsert, ' ');
        return string;
    }

    return string.substr(0, 9) + ".";
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

int Program::getIntField(std::string label, std::string validationMessage)
{
    std::string input(
        this->getTextField(label, validationMessage)
    );

    while (input[0] != '0' && std::atoi(input.c_str()) == 0) {
        std::cout << "* INDEX SHOULD BE A NUMBER *" << std::endl;
        input = this->getTextField(label, validationMessage);
    }

    return std::stoi(input);
}