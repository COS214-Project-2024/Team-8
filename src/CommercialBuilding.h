#include <exception>
using namespace std;

#ifndef __CommercialBuilding_h__
#define __CommercialBuilding_h__

#include "State.h"
#include "Buildings.h"

class CommercialBuilding : public Buildings
{
public:
	void requestState() override;

	double getMaintenanceCost() override;

	int getPowerReq() override;

	int getSewageCost() override;

	int getWaterCost() override;

	int getWasteCost() override;

	double getSales(); //----------------------HEY I'M NEW HERE=---------------------

	double getProfit(); //----------------------HEY I'M NEW HERE=---------------------

	double getBalance(); //----------------------HEY I'M NEW HERE=---------------------

	void setSales(double sale); //----------------------HEY I'M NEW HERE=---------------------

	void setProfit(double profit); //----------------------HEY I'M NEW HERE=---------------------

	void setBalance(double balance); //----------------------HEY I'M NEW HERE=---------------------


protected:
	double sales;  //----------------------HEY I'M NEW HERE=---------------------
	double profit; //----------------------HEY I'M NEW HERE=---------------------
	double balance ;//----------------------HEY I'M NEW HERE=---------------------
};

#endif
