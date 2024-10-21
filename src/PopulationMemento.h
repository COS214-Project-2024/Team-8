#include <exception>
using namespace std;

#ifndef __PopulationMemento_h__
#define __PopulationMemento_h__

#include "State.h"
// #include "PopulationHistory.h"

class State;
class PopulationHistory;
class PopulationMemento;

class PopulationMemento
{
	private: State _state;
	public: PopulationHistory* _unnamed_PopulationHistory_;

	public: State getState();

	public: void setState(State aState);
};

#endif
