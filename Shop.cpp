#include <iostream>
#include <exception>
using namespace std;

#include "State.h"
#include "Shop.h"
#include "UnderConstruction.h"
#include "ResourceMediator.h"
#include "Citizen.h"

Shop::Shop(string bName, int pReq, int wReq, double mCost, int sCost, int waste, float sales, float profit, int emp)
{
	this->buildingName = bName;
	this->buildingType = "Commercial";
	this->powerReq = pReq;
	this->waterReq = wReq;
	this->maintenanceCost = mCost;
	this->sewageCost = sCost;
	this->waste = waste;
	this->sales = sales;
	this->profit = profit;
	this->employment = emp;

	this->state =  new UnderConstruction(); //when we instantiate a building it will be under construction
	this->state->handle(); //handle the state;
	this->setState(); //change the state to operation if the resources are available

	this->listOfCitizens->adjustCitizenSatisfaction(5.0);
}

void Shop::requestState() {
	this->state->handle();
}

double Shop::getMaintenanceCost() {
	return this->maintenanceCost;
}

int Shop::getPowerReq() {
	return this->powerReq;
}

int Shop::getSewageCost() {
	return this->sewageCost;
}

int Shop::getWaterReq() {
	return this->waterReq;
}

int Shop::getWasteCost() {
	return this->waste;
}

void Shop::setState()
{
	this->state->changeState();
}

string Shop::getName()
{
	return this->buildingName;
}

string Shop::getBuildingType()
{
	return this->buildingType;
}

float Shop::getSales()
{
	return this->sales;
}

float Shop::getProfit()
{
	return this->profit;
}

int Shop::getJobsCreated()
{
	return this->employment;
}

string Shop::getName()
{
	return this->buildingName;
}

string Shop::getBuildingType()
{
	return this->buildingType;
}

float Shop::getProfit()
{
	return this->profit;
}

float Shop::getSales()
{
	return this->sales;
}
bool Shop::payMaintenance()
{
	if(this->maintenanceCost > 200)
	{
		this->resources->useRevenue(100, this);
		this->maintenanceCost = this->maintenanceCost - 100;
		cout<<"successfully paid maintenance."<<endl;
		return true;
	}
	else
	{
		cout<<"insufficient funds to pay maintenance"<<endl;
		this->state->changeState();
		return false;
	}
}

bool Shop::receivePower()
{
		if(this->maintenanceCost > 200)
	{
		this->resources->useRevenue(100, this);
		this->maintenanceCost = this->maintenanceCost - 100;
		cout<<"successfully paid maintenance."<<endl;
		return true;
	}
	else
	{
		cout<<"insufficient funds to pay maintenance"<<endl;
		this->state->changeState();
		return false;
	}
}

bool Shop::receiveWater()
{
		if(this->waterReq > 200)
	{
		this->resources->useWater(100, this);
		this->maintenanceCost = this->maintenanceCost - 100;
		cout<<"successfully recieved water."<<endl;
		return true;
	}
	else
	{
		cout<<"insufficient funds to recieve water."<<endl;
		this->state->changeState();
		return false;
	}
}

bool Shop::cleanSewage()
{
		if(this->maintenanceCost > 200)
	{
		this->resources->cleanSewage(100, this);
		this->maintenanceCost = this->maintenanceCost - 100;
		cout<<"successfully cleaned sewage."<<endl;
		return true;
	}
	else
	{
		cout<<"insufficient funds to clean sewage."<<endl;
		this->state->changeState();
		return false;
	}
}
    
bool Shop::cleanWaste()
{
		if(this->maintenanceCost > 200)
	{
		this->resources->cleanWaste(100, this);
		this->maintenanceCost = this->maintenanceCost - 100;
		cout<<"successfully cleaned waste."<<endl;
		return true;
	}
	else
	{
		cout<<"insufficient funds to clean waste"<<endl;
		this->state->changeState();
		return false;
	}
}

int Shop::payCitizen()
{
	cout<<"Paying citizen"<<endl;
	return 5000;
}


