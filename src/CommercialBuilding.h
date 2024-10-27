#include <exception>
using namespace std;

#ifndef __CommercialBuilding_h__
#define __CommercialBuilding_h__

#include "State.h"
#include "Buildings.h"

class CommercialBuilding : public Buildings
{
public:
	// Implementing the virtual functions from the Buildings base class
	void requestState() override;

	double getMaintenanceCost() override;

	int getPowerReq() override;

	int getSewageCost() override;

	int getWaterCost() override;

	int getWasteCost() override;

	double getSales() const;

	double getProfit() const;

protected:
	double sales;
	double profit;
};

#endif
