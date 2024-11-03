#ifndef COMMAND_H
#define COMMAND_H

#include "Utility.h"

class UtilityManager; // Forward declaration

class Command {
public: 
    UtilityManager* utilityMan; // Member variable

    Command() = default; // Default constructor

    virtual void execute() = 0; // Pure virtual function

    virtual ~Command() = default; // Default destructor

    virtual std::string getUtilityType() {
        return ""; // Default implementation
    }
};

#endif
