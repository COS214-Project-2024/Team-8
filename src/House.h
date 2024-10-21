#include <exception>
using namespace std;

#ifndef __House_h__
#define __House_h__

#include "State.h"
#include "Estate.h"

class State;
// class Estate;
class House;

class House: public Estate
{
	private: State _state;
	private: int _capacity;
	private: Citizen* _listOfResidents;
	private: int _powerReq;
	private: int _waterReq;
	private: double _maintanenceCost;
	private: int _sewageCost;
	private: int _waste;

	public: void requestState();

	public: int getCapacity();

	public: Citizen* getListOfResident();

	public: double getMaintenanceCost();

	public: int getPowerReq();

	public: int getWaterReq();

	public: int getSewageCost();

	public: int getWasteCost();
};

#endif
