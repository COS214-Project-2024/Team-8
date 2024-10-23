#include <exception>
using namespace std;

#ifndef __MedicalCenter_h__
#define __MedicalCenter_h__

#include "State.h"

class State;
class MedicalCenter;

class MedicalCenter
{
	private: State _state;
	private: int _powerReq;
	private: int _waterReq;
	private: double _maintenanceCost;
	private: int _sewageCost;
	private: int _waste;
	private: int _healthcareCoverage;

	public: void requestState();

	public: double getMaintenanceCost();

	public: double getSewageCost();

	public: float getHealthCare();

	public: int getPowerReq();

	public: int getWaterReq();
};

#endif
