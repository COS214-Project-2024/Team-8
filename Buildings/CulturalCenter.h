#include <exception>
using namespace std;

#ifndef __CulturalCenter_h__
#define __CulturalCenter_h__

#include "State.h"

class State;
class CulturalCenter;

class CulturalCenter
{
	private: State _state;
	private: int _powerReq;
	private: int _waterReq;
	private: double _maintenanceCost;
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
