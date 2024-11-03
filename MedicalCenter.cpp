#include <iostream>
#include <exception>
using namespace std;

#include "MedicalCenter.h"
#include "State.h"
#include "UnderConstruction.h"
#include "ResourceMediator.h"
#include "Citizen.h"

MedicalCenter::MedicalCenter(string bName, int pReq, int wReq, double mCost, int sCost, int waste, int employment, float hCov)
{
	this->buildingName = bName;
	this->buildingType = "Public Service";
	this->powerReq = pReq;
	this->waterReq = wReq;
	this->maintenanceCost = mCost;
	this->sewageCost = sCost;
	this->waste = waste;
	this->employment = employment;
	this->healthCoverage = hCov;
	this->birthRate = 50;

	this->state =  new UnderConstruction(); //when we instantiate a building it will be under construction
	this->state->handle(); //handle the state;
	this->setState(); //change the state to operation if the resources are available

	this->resources = new ResourceMediator();
	this->listOfCitizens = new Citizen("NewCitizen",100,21,5.0);
}

void MedicalCenter::requestState() {
	this->state->handle();
}

double MedicalCenter::getMaintenanceCost() {
	return this->maintenanceCost;
}

int MedicalCenter::getPowerReq() {
	return this->powerReq;
}

int MedicalCenter::getSewageCost() {
	return this->sewageCost;
}

int MedicalCenter::getWaterReq() {
	return this->waterReq;
}

int MedicalCenter::getWasteCost() {
	return this->waste;
}

void MedicalCenter::setState()
{
	this->state->changeState();
}


int MedicalCenter::getJobsCreated()
{
	return employment; //NOT SURE - ask Tebogo what this should return
}

string MedicalCenter::getName()
{
	return this->buildingName;
}

string MedicalCenter::getBuildingType()
{
	return this->buildingType;
}

float MedicalCenter::getHealthCoverage()
{
	return this->healthCoverage;
}

bool MedicalCenter::payMaintenance()
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

bool MedicalCenter::receivePower()
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

bool MedicalCenter::receiveWater()
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

bool MedicalCenter::cleanSewage()
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
    
bool MedicalCenter::cleanWaste()
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

int MedicalCenter::getBirthRate()
{
	return this->birthRate;
}


