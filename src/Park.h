#include <exception>
using namespace std;

#ifndef __Park_h__
#define __Park_h__

#include "State.h"

class State;
class Park;

class Park
{
	private: State _state;
	private: int _powerReq;
	private: int _waterReq;
	private: double _maintenance;
	private: int _sewageCost;
	private: int _waste;

	public: void requestState();

	public: double getMaintenanceCost();

	public: int getPowerReq();

	public: int getSewageCost();

	public: int getWaterCost();

	public: int getWasteCost();
};

#endif
