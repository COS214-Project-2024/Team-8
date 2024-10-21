#include <exception>
using namespace std;

#ifndef __ResidentialBuilding_h__
#define __ResidentialBuilding_h__

#include "State.h"
#include "Buildings.h"

class State;
// class Buildings;
class ResidentialBuilding;

class ResidentialBuilding: public Buildings
{
	private: State _state;
	private: int _powerReq;
	private: int _waterReq;
	private: double _maintenanceCost;
	private: int _sewageCost;
	private: int _waste;

	public: void requestState();

	public: double getMaintenanceCost();

	public: int getSewageCost();

	public: int getWaterCost();

	public: int getPowerReq();

	public: void getWaterReq();

	public: int getWasteCost();
};

#endif
