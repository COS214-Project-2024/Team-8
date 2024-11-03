#include <iostream>
#include <exception>
using namespace std;

#include "Factories.h"
#include "State.h"
#include "UnderConstruction.h"
#include "ResourceMediator.h"
#include "Citizen.h"

Factories::Factories(string bName, int pReq, int wReq, double mCost, int sCost, int waste, int employment)
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

	this->listOfCitizens = new Citizen("newCitizen",100,23,5.0);
}

void Factories::requestState() {
	this->state->handle();
}

double Factories::getMaintenanceCost() {
	return this->maintenanceCost;
}

int Factories::getPowerReq() {
	return this->powerReq;
}

int Factories::getSewageCost() {
	return this->sewageCost;
}

int Factories::getWasteCost() {
	return this->waste;
}

void Factories::setState(State* newState)
{
	this->state = newState;
}

int Factories::getJobsCreated()
{
	return employment; 
}

string Factories::getName()
{
	return this->buildingName;
}

string Factories::getBuildingType()
{
	return this->buildingType;
}

bool Factories::payMaintenance()
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

bool Factories::receivePower()
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

bool Factories::receiveWater()
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

bool Factories::cleanSewage()
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
    
bool Factories::cleanWaste()
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


int Factories::payCitizen()
{
	cout<<"Paying citizen"<<endl;
	return 8000;
}


