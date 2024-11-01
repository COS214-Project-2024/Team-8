#include <exception>
using namespace std;

#ifndef __Operational_h__
#define __Operational_h__

#include "State.h"

// class State;
class Operational;

class Operational: public State
{

	public: void handle();

	public: void changeState();
};

#endif
