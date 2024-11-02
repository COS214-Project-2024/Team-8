#include <exception>
#include <string>
using namespace std;

#ifndef __Command_h__
#define __Command_h__

class UtilityManager;
class Command;

class Command {
    public: 
        UtilityManager* utilityMan;

        // Default the constructor like we did with destructor
        Command() = default;  // Command Pattern for policies

        virtual void execute() = 0; // Command Pattern for policies

        virtual ~Command() = default; // Command Pattern for policies

        virtual string getUtilityType() {
            return ""; // Default implementation or make it pure virtual if needed
        }
};

#endif