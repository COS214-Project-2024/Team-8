#include <exception>
using namespace std;

#ifndef __PopulationControl_h__
#define __PopulationControl_h__

#include "State.h"
// #include "Citizen.h"
// #include "City.h"
#include "PopulationMemento.h"

class State;
class Citizen;
class City;
class PopulationMemento;
class PopulationControl;

class PopulationControl
{
	private: State _state;
	public: Citizen* _unnamed_Citizen_;
	public: City* _unnamed_City_;

	public: PopulationMemento createMemento();

	public: void setMemento(PopulationMemento aMemento);
};

#endif
