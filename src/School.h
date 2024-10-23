#include <exception>
using namespace std;

#ifndef __School_h__
#define __School_h__

#include "State.h"

class State;
class School;

class School
{
	private: State _state;
	private: int _powerReq;
	private: int _waterReq;
	private: double _maintenanceCost;
	private: int _sewageCost;
	private: int _waste;
	private: float _educationCoverage;

	public: void requestState();

	public: double getMaintenanceCost();

	public: double getSewageCost();

	public: int getPowerReq();

	public: int getWaterReq();

	public: int getEducation();
};

#endif
