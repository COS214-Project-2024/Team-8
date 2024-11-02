#include <string>
#include <exception>
using namespace std;

#ifndef __UnderConstruction_h__
#define __UnderConstruction_h__

#include "State.h"

// class State;
class UnderConstruction;

class UnderConstruction: public State
{
	public: 
		UnderConstruction();
		void handle();
		void changeState();
		string getStateName();

};

#endif
