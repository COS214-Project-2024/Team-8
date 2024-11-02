#include <iostream>
#include <exception>
using namespace std;

#include "Office.h"
#include "State.h"
#include "UnderConstruction.h"
#include "ResourceMediator.h"
#include "Citizen.h"

Office::Office(string bName,int pReq, int wReq, double mCost, int sCost, int waste, float sales, float profit, int emp, int income)
{
	this->buildingName = bName;
	this->buildingType = "Landmark";
	this->powerReq = pReq;
	this->waterReq = wReq;
	this->maintenanceCost = mCost;
	this->sewageCost = sCost;
	this->waste = waste;
	this->sales = sales;
	this->profit = profit;
	this->employment = emp;
	this->income = income;

	this->state =  new UnderConstruction(); //when we instantiate a building it will be under construction
	this->state->handle(); //handle the state;
	this->setState(); //change the state to operation if the resources are available

	this->resources = new ResourceMediator();
	this->listOfCitizens = new Citizen();
	this->listOfCitizens->adjustCitizenSatisfaction(5.0);
}

void Office::requestState() {
	this->state->handle();
}

double Office::getMaintenanceCost() {
	return this->maintenanceCost;
}

int Office::getPowerReq() {
	return this->powerReq;
}

int Office::getSewageCost() {
	return this->sewageCost;
}

int Office::getWaterCost() {
	return this->waterReq;
}

int Office::getWasteCost() {
	return this->waste;
}

void Office::setState()
{
	this->state->changeState();
}

string Office::getName()
{
	return this->buildingName;
}

string Office::getBuildingType()
{
	return this->buildingType;
}

float Office::getSales()
{
	return this->sales;
}

float Office::getProfit()
{
	return this->profit;
}

int Office::getJobsCreated()
{
	return this->employment;
}

int Office::getIncome()
{
	return this->income;
}

bool Office::payMaintenance()
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

bool Office::receivePower()
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

bool Office::receiveWater()
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

bool Office::cleanSewage()
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
    
bool Office::cleanWaste()
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

int Office::payCitizen()
{
	cout<<"Paying citizen"<<endl;
	return 5000;
}


