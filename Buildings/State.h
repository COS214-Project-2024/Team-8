#include <exception>
using namespace std;

#ifndef __State_h__
#define __State_h__

#include "Buildings.h"

class Buildings;
class State;

class State
{
	protected: Buildings building;
	public: Buildings* state;
	public: Buildings* buidling;

	public: virtual void handle() = 0;

	public: virtual void changeState() = 0;
};

#endif
