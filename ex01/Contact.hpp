#ifndef CONTACT_H
# define CONTACT_H

#include <string>

class Contact
{
    int index;
    std::string const firstName;
    std::string const lastName;
    std::string nickName;
    std::string darkestSecret;
    std::string phoneNumber;

    public:
        Contact(
            std::string firstName,
            std::string lastName
        ) : firstName(firstName), lastName(lastName) {}

        int getIndex() const;
        std::string getFirstName() const;
        std::string getLastName() const;
        std::string getNickName() const;
        std::string getDarkestSecret() const;
        std::string getPhoneNumber() const;
        std::string getFormattedFirstName() const;
        std::string getFormattedLastName() const;
        std::string getFormattedNickName() const;
        std::string getFormattedIndex() const;
        std::string formatString(std::string) const;
        void setIndex(int index);
        void setNickName(std::string);
        void setDarkestSecret(std::string);
        void setPhoneNumber(std::string);
};

#endif
