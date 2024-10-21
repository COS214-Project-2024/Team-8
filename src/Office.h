#include <exception>
using namespace std;

#ifndef __Office_h__
#define __Office_h__

#include "State.h"

class State;
class Office;

class Office
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

	public: int getIncome();

	public: int getEmployment();

	public: double getMaintenanceCost();

	public: int getPowerReq();

	public: int getWatereReq();

	public: int getSewageCost();

	public: int getWasteCost();
};

#endif
