#include <iostream>

void RUN_CONTACT_SUITE();
void RUN_PHONEBOOK_SUITE();
void RUN_PROGRAM_SUITE();
void RUN_UTILS_SUITE();

int main()
{
    RUN_CONTACT_SUITE();
    RUN_PHONEBOOK_SUITE();
    RUN_PROGRAM_SUITE();
    RUN_UTILS_SUITE();
    std::cout << std::endl;
}
