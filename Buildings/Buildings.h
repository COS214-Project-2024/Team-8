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

class Buildings
{
	// private: State _state;
private:
	int _powerReq;
	int _waterReq;
	double _maintenanceCost;
	int _sewageCost;
	int _waste;

public:
	Government *_unnamed_Government_;
	ConstructionCompany *_unnamed_ConstructionCompany_;
	State *_buidling;
	Resources *_unnamed_Resources_;

	virtual void requestState() = 0;
	virtual double getMaintenanceCost() = 0;
	virtual int getPowerReq() = 0;
	virtual int getSewageCost() = 0;
	virtual int getWaterCost() = 0;
	virtual int getWasteCost() = 0; // Why was this void ?
};

#endif
