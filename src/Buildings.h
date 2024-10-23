#include <exception>
using namespace std;

#ifndef __Buildings_h__
#define __Buildings_h__

#include "State.h"
// #include "Government.h"
// #include "ConstructionCompany.h"
// #include "Resources.h"

class State;
class Government;
class ConstructionCompany;
class Resources;
class Buildings;

__abstract class Buildings
{
	private: State _state;
	private: int _powerReq;
	private: int _waterReq;
	private: double _maintenanceCost;
	private: int _sewageCost;
	private: int _waste;
	public: Government* _unnamed_Government_;
	public: ConstructionCompany* _unnamed_ConstructionCompany_;
	public: State* _buidling;
	public: Resources* _unnamed_Resources_;

	public: virtual void requestState() = 0;

	public: virtual double getMaintenanceCost() = 0;

	public: virtual int getPowerReq() = 0;

	public: virtual int getSewageCost() = 0;

	public: virtual int getWaterCost() = 0;

	public: virtual void getWasteCost() = 0;
};

#endif
