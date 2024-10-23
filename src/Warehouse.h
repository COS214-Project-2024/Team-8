#include <exception>
using namespace std;

#ifndef __Warehouse_h__
#define __Warehouse_h__

#include "State.h"

class State;
class Warehouse;

class Warehouse
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

	public: in getSewageCost();

	public: int getWasteCost();

	public: int getMaintenanceCost();
};

#endif
