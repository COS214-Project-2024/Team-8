#include <iostream>
#include <exception>
using namespace std;

#include "PowerPlant.h"
#include "State.h"
#include "UnderConstruction.h"
#include "ResourceMediator.h"
#include "Citizen.h"

PowerPlant::PowerPlant(string bName, int pReq, int wReq, double mCost, int sCost, int waste, int employment)
{
	this->buildingName = bName;
	this->buildingType = "Industrial";
	this->powerReq = 500000;
	this->waterReq = 250000;
	this->maintenanceCost = 75000;
	this->sewageCost = 5000;
	this->waste = 7000;
	this->employment = employment;

	this->state =  new UnderConstruction(); //when we instantiate a building it will be under construction
	this->state->handle(); //handle the state;
	this->setState(); //change the state to operation if the resources are available

	this->resources = new ResourceMediator();
	this->listOfCitizens = new Citizen("NewCitizen",100,21,5.0);
}

void PowerPlant::requestState() {
	this->state->handle();
}

double PowerPlant::getMaintenanceCost() {
	return this->maintenanceCost;
}

int PowerPlant::getPowerReq() {
	return this->powerReq;
}

int PowerPlant::getSewageCost() {
	return this->sewageCost;
}

int PowerPlant::getWaterReq() {
	return this->waterReq;
}

int PowerPlant::getWasteCost() {
	return this->waste;
}

void PowerPlant::setState()
{
	this->state->changeState();
}


int PowerPlant::getJobsCreated()
{
	return employment; //NOT SURE - ask Tebogo what this should return
}

string PowerPlant::getName()
{
	return this->buildingName;
}

string PowerPlant::getBuildingType()
{
	return this->buildingType;
}

bool PowerPlant::payMaintenance()
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

bool PowerPlant::receivePower()
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

bool PowerPlant::receiveWater()
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

bool PowerPlant::cleanSewage()
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
    
bool PowerPlant::cleanWaste()
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

int PowerPlant::payCitizen()
{
	cout<<"Paying citizen"<<endl;
	return 8000;
}


