#include <iostream>
#include <exception>
using namespace std;

#include "Monument.h"
#include "State.h"
#include "UnderConstruction.h"
#include "ResourceMediator.h"
#include "Citizen.h"

Monument::Monument(string bName,int pReq, int wReq, double mCost, int sCost, int waste)
{
	this->buildingName = bName;
	this->buildingType = "Landmark";
	this->powerReq = pReq;
	this->waterReq = wReq;
	this->maintenanceCost = mCost;
	this->sewageCost = sCost;
	this->waste = waste;
	

	this->state =  new UnderConstruction(); //when we instantiate a building it will be under construction
	this->state->handle(); //handle the state;
	this->setState(); //change the state to operation if the resources are available

	this->resources = new ResourceMediator();
	this->listOfCitizens = new Citizen("NewCitizen",100,21,5.0);
	this->listOfCitizens->adjustCitizenSatisfaction(5.0);
}

void Monument::requestState() {
	this->state->handle();
}

double Monument::getMaintenanceCost() {
	return this->maintenanceCost;
}

int Monument::getPowerReq() {
	return this->powerReq;
}

int Monument::getSewageCost() {
	return this->sewageCost;
}

int Monument::getWaterReq() {
	return this->waterReq;
}

int Monument::getWasteCost() {
	return this->waste;
}

void Monument::setState()
{
	this->state->changeState();
}

string Monument::getName()
{
	return this->buildingName;
}

string Monument::getBuildingType()
{
	return this->buildingType;
}

bool Monument::payMaintenance()
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

bool Monument::receivePower()
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

bool Monument::receiveWater()
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

bool Monument::cleanSewage()
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
    
bool Monument::cleanWaste()
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


