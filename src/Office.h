#ifndef OFFICE_H
#define OFFICE_H

class Office : CommercialBuilding {

protected:
	string buildingName;
	string buildingType;
	int employment;
	Citizen* listOfCitizens;
	double maintenanceCost;
	int powerReq;
	float profit;
	ResourceMediator* resources;
	float sales;
	int sewageCost;
protected:
	State* state;
	int waterReq;

public:
	virtual bool cleanSewage() = 0;

	virtual bool cleanWaste() = 0;

	virtual string getBuildingType() = 0;

	virtual int getJobsCreated() = 0;

	float getlSales();

	virtual double getMaintenanceCost() = 0;

	virtual string getName() = 0;

	virtual int getPowerReq() = 0;

	float getProfit();

	virtual int getSewageCost() = 0;

	virtual int getWaterCost() = 0;

	virtual void operation() = 0;

	void operation2();

	virtual bool payMaintenance() = 0;

	virtual bool recievePower() = 0;

	virtual bool recieveWater() = 0;

	virtual void requestState() = 0;
};

#endif
