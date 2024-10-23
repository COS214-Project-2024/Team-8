#include <exception>
using namespace std;

#ifndef __PoliceStation_h__
#define __PoliceStation_h__

#include "State.h"

class State;
class PoliceStation;

class PoliceStation
{
	private: State _state;
	private: int _employment;
	private: int _powerReq;
	private: int _waterReq;
	private: double _maintenanceCost;
	private: int _sewageCost;
	private: float _securityCoverage;

	public: void requestState();

	public: int getEmployment();

	public: double getMaintenanceCost();

	public: int getPowerReq();

	public: int getWaterReq();

	public: int getSewageCost();

	public: float getSecurityCoverage();
};

#endif
