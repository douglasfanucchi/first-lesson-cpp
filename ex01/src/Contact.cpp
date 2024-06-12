#include "Contact.hpp"

void Contact::setFirstName(std::string firstName)
{
    this->firstName = firstName;
}

std::string Contact::getFirstName() const
{
    return this->firstName;
}

void Contact::setLastName(std::string lastName)
{
    this->lastName = lastName;
}

std::string Contact::getLastName() const
{
    return this->lastName;
}

void Contact::setNickName(std::string nickName)
{
    this->nickName = nickName;
}

std::string Contact::getNickName() const
{
    return this->nickName;
}

void Contact::setIndex(int i)
{
    this->index = i;
}

int Contact::getIndex() const
{
    return this->index;
}

void Contact::setDarkestSecret(std::string darkestSecret)
{
    this->darkestSecret = darkestSecret;
}

std::string Contact::getDarkestSecret() const
{
    return this->darkestSecret;
}

void Contact::setPhoneNumber(std::string phoneNumber)
{
    this->phoneNumber = phoneNumber;
}

std::string Contact::getPhoneNumber() const
{
    return this->phoneNumber;
}

std::string Contact::getFormattedFirstName() const
{
    return this->formatString(this->getFirstName());
}

std::string Contact::getFormattedLastName() const
{
    return this->formatString(this->getLastName());
}

std::string Contact::getFormattedNickName() const
{
    return this->formatString(this->getNickName());
}

std::string Contact::getFormattedIndex() const
{
    std::ostringstream stream;

    stream << this->index;
    return this->formatString(stream.str());
}

std::string Contact::formatString(std::string string) const
{
    if (string.size() < 11) {
        int spacesToInsert = 10 - string.size();
        string.insert(0, spacesToInsert, ' ');
        return string;
    }

    return string.substr(0, 9) + ".";
}
