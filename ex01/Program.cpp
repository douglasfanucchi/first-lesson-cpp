#include <Program.hpp>

Program::Program() : _isRunning(true) {}

bool Program::isRunning() const
{
    return this->_isRunning;
}