#include <Program.hpp>

int main()
{
    Program program;
    std::string command;

    while (program.isRunning()) {
        std::getline(std::cin, command);
        program.run(command);
    }
    return 0;
}
