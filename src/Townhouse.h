#ifndef TOWNHOUSE_H
#define TOWNHOUSE_H

class Townhouse : ResidentialBuilding {

protected:
	string buildingName;
	string buildingType;
	int capacity;
	Citizen* listOfCitizens;
	double maintenanceCost;
	int powerReq;
	ResourceMediator* resources;
	int sewageCost;
protected:
	State* state;
	int waterReq;

public:
	virtual bool cleanSewage() = 0;

	virtual bool cleanWaste() = 0;

	virtual string getBuildingType() = 0;

	virtual int getJobsCreated() = 0;

	virtual double getMaintenanceCost() = 0;

	virtual string getName() = 0;

	virtual int getPowerReq() = 0;

	virtual int getSewageCost() = 0;

	virtual int getWaterCost() = 0;

	virtual void operation() = 0;

	virtual bool payMaintenance() = 0;

	virtual bool recievePower() = 0;

	virtual bool recieveWater() = 0;

	virtual void requestState() = 0;
};

#endif
