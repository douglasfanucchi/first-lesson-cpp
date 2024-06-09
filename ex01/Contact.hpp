#ifndef CONTACT_H
# define CONTACT_H

#include <string>

class Contact
{
    int index;
    std::string firstName;
    std::string lastName;
    std::string nickName;
    std::string darkestSecret;
    std::string phoneNumber;

    protected:
        std::string formatString(std::string) const;

    public:
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
        void setFirstName(std::string);
        void setLastName(std::string);
        void setIndex(int index);
        void setNickName(std::string);
        void setDarkestSecret(std::string);
        void setPhoneNumber(std::string);
};

#endif
