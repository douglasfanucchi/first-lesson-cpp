#include <iostream>
#include <cctype>

class Megaphone
{
    public:
        std::string strToUpper(std::string str);
        void say(char** words);
};

void Megaphone::say(char** words)
{
    if (*words == NULL) {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return;
    }
    while (*words)
    {
        std::cout << this->strToUpper(*words);
        words++;
    }
    std::cout << std::endl;
}

std::string Megaphone::strToUpper(std::string str)
{
    for(int i = 0; i < str.length(); i++) {
        if(std::isupper(str[i])) {
            continue;
        }
        str.replace(i, 1, 1, std::toupper(str[i]));
    }
    return str;
}

int main(int argc, char **argv)
{
    Megaphone megaphone;

    megaphone.say(argv + 1);
}
