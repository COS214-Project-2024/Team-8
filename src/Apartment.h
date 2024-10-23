#include <exception>
using namespace std;

#ifndef __Apartment_h__
#define __Apartment_h__

#include "State.h"

class State;
class Apartment;

class Apartment
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

	public: double getMaiantenanceCost();

	public: int getPowerReq();

	public: int getWaterReq();

	public: int getSewageCost();

	public: int getWasteCost();
};

#endif
