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
}