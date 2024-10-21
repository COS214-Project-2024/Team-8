#include <exception>
using namespace std;

#ifndef __Factories_h__
#define __Factories_h__

#include "State.h"

class State;
class Factories;

class Factories
{
	private: State _state;
	private: int _capacity;
	private: int _powerReq;
	private: int _waterReq;
	private: double _maintenanceCost;
	private: int _sewageCost;
	private: int _waste;

	public: void requestState();

	public: int getCapacity();

	public: int getPowerReq();

	public: int getWaterReq();

	public: int getSewageCost();

	public: int getWasteCost();

	public: double getMaintanenceCost();
};

#endif
