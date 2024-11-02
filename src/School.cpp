#include <iostream>
#include <exception>
using namespace std;

#include "School.h"
#include "State.h"
#include "UnderConstruction.h"
#include "ResourceMediator.h"
#include "Citizen.h"

School::School(string bName,int pReq, int wReq, double mCost, int sCost, int waste, int employment, float eCov)
{
	this->buildingName = bName;
	this->buildingType = "Public Service";
	this->powerReq = pReq;
	this->waterReq = wReq;
	this->maintenanceCost = mCost;
	this->sewageCost = sCost;
	this->waste = waste;
	this->employment = employment;
	this->educationCoverage = eCov;

	this->state =  new UnderConstruction(); //when we instantiate a building it will be under construction
	this->state->handle(); //handle the state;
	this->setState(); //change the state to operation if the resources are available

	this->resources = new ResourceMediator();
	this->listOfCitizens = new Citizen();
}

void School::requestState() {
	this->state->handle();
}

double School::getMaintenanceCost() {
	return this->maintenanceCost;
}

int School::getPowerReq() {
	return this->powerReq;
}

int School::getSewageCost() {
	return this->sewageCost;
}

int School::getWaterReq() {
	return this->waterReq;
}

int School::getWasteCost() {
	return this->waste;
}

void School::setState()
{
	this->state->changeState();
}


int School::getJobsCreated()
{
	return employment; 
}

string School::getName()
{
	return this->buildingName;
}

string School::getBuildingType()
{
	return this->buildingType;
}

float School::getEducationCoverage()
{
	return this->educationCoverage;
}

bool School::payMaintenance()
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

bool School::receivePower()
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

bool School::receiveWater()
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

bool School::cleanSewage()
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
    
bool School::cleanWaste()
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


