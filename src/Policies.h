#include <exception>
using namespace std;

#ifndef __Policies_h__
#define __Policies_h__

// #include "Government.h"
#include "Command.h"

class Government;
class Policies;

class Policies : public Command
{
	protected:
		Government* government;

	public: 
		explicit Policies(Government* govt) : government(govt) {} // Command Pattern for policies
		virtual void executePolicy() = 0; // Command Pattern for policies
		void execute() override { executePolicy(); }// Command Pattern for policies
   	    virtual ~Policies() = default;
};

#endif
