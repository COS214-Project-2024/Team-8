#include <exception>
using namespace std;

#ifndef __Shop_h__
#define __Shop_h__

#include "State.h"
#include "Mall.h"

class State;
// class Mall;
class Shop;

class Shop: public Mall
{
	private: State _state;
	private: double _income;
	private: int _employment;
	private: int _powerReq;
	private: int _waterReq;
	private: double _maintenanceCost;
	private: int _sewageCost;
	private: int _waste;

	public: void requestState();

	public: double getMaintenaceCost();

	public: int getSewageCost();

	public: int getWasteCost();

	public: void getWaterReq();

	public: int getEmployment();

	public: int getIncome();

	public: void getPowerReq();
};

#endif
