#ifndef PROGRAM_H
# define PROGRAM_H

#include <iostream>

class Program
{
    bool _isRunning;

    public:
        Program();
        bool isRunning() const;
        void run(std::string);
};

#endif