#include <exception>
using namespace std;

#ifndef __State_h__
#define __State_h__

// #include "Buildings.h"

class Buildings;
class State;

class State
{
	// protected: Buidlings _building;
	public: Buildings* _state;
	public: Buildings* _buidling;

	public: virtual void handle() = 0;
	virtual ~State() = default;
	public: virtual void changeState() = 0;
};

#endif
