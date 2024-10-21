#include <exception>
using namespace std;

#ifndef __Damaged_h__
#define __Damaged_h__

#include "State.h"

// class State;
class Damaged;

class Damaged: public State
{

	public: void handle();

	public: void changeState();
};

#endif
