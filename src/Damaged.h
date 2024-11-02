#include <string>
#include <exception>
using namespace std;

#ifndef __Damaged_h__
#define __Damaged_h__

#include "State.h"

// class State;
class Damaged;

class Damaged: public State
{
	public: 
		Damaged();
		void handle();
		void changeState();
		string getStateName();

};

#endif
