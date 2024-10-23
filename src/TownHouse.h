#include <exception>
using namespace std;

#ifndef __TownHouse_h__
#define __TownHouse_h__

#include "State.h"
#include "Estate.h"

class State;
// class Estate;
class TownHouse;

class TownHouse: public Estate
{
	private: State _state;
	private: int _capacity;
	private: Citizen* _listOfResidents;
	private: int _powerReq;
	private: int _waterReq;
	private: double _maintenanceCost;
	private: int _sewageCost;
	private: int _waste;

	public: void requestState();

	public: int getCapacity();

	public: Citizen* getListOfResidents();

	public: int getPowerReq();

	public: int getWaterReq();

	public: int getSewageCost();

	public: int getWasteCost();

	public: double getMaintanenceCost();
};

#endif
