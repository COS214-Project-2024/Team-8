#include <iostream>
#include <exception>
using namespace std;

#include "CulturalCenter.h"
#include "State.h"
#include "UnderConstruction.h"
#include "ResourceMediator.h"
#include "Citizen.h"

CulturalCenter::CulturalCenter(string bName,int pReq, int wReq, double mCost, int sCost, int waste)
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
	this->state->changeState();//in case it needs to change

	this->listOfCitizens = new Citizen("New Citizen" , 100 , 23 , 5.0) ;
	this->listOfCitizens->adjustCitizenSatisfaction(5.0);
}

void CulturalCenter::requestState() {
	this->state->handle();
}

double CulturalCenter::getMaintenanceCost() {
	return this->maintenanceCost;
}

int CulturalCenter::getPowerReq() {
	return this->powerReq;
}

int CulturalCenter::getSewageCost() {
	return this->sewageCost;
}

int CulturalCenter::getWaterReq() {
	return this->waterReq;
}

int CulturalCenter::getWasteCost() {
	return this->waste;
}

void CulturalCenter::setState(State* newState)
{
	this->state = newState;
}

string CulturalCenter::getName()
{
	return this->buildingName;
}

string CulturalCenter::getBuildingType()
{
	return this->buildingType;
}

bool CulturalCenter::payMaintenance()
{
	if(this->maintenanceCost > 200)
	{
		this->resources->useRevenue(100,this);
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

bool CulturalCenter::receivePower()
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

bool CulturalCenter::receiveWater()
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

bool CulturalCenter::cleanSewage()
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
    
bool CulturalCenter::cleanWaste()
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


