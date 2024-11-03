#include <iostream>
#include <memory>
#include <exception>
using namespace std;

#include "Apartment.h"
#include "State.h"
#include "UnderConstruction.h"
#include "ResourceMediator.h"
#include "Citizen.h"

Apartment::Apartment(string bName,int pReq, int wReq, double mCost, int sCost, int waste, int capacity)
{
	this->buildingName = bName;
	this->buildingType = "Residential";
	this->powerReq = 500000;
	this->waterReq = 250000;
	this->maintenanceCost = 75000;
	this->sewageCost = 5000;
	this->waste = 7000;
	this->capacity = 1000;

	this->state =  new UnderConstruction(); //when we instantiate a building it will be under construction
	this->state->handle(); //handle the state;
	this->state->changeState();//in case it needs to change

	this->listOfCitizens = new Citizen();
}

void Apartment::requestState() {
	this->state->handle();
}

int Apartment::getCapacity() {
	return this->capacity;
}

Citizen* Apartment::getListOfResidents() {
	return this->listOfCitizens;
}

double Apartment::getMaintenanceCost() {
	return this->maintenanceCost;
}

int Apartment::getPowerReq() {
	return this->powerReq;
}

int Apartment::getWaterReq() {
	return this->waterReq;
}

int Apartment::getSewageCost() {
	return this->sewageCost;
}

int Apartment::getWasteCost() {
	return this->waste;
}

void Apartment::setState(State* newState)
{
	this->state = newState;
}

int Apartment::getCapacity()
{
	return this->capacity;
}

string Apartment::getName()
{
	return this->buildingName;
}

bool Apartment::payMaintenance()
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

bool Apartment::receivePower()
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

bool Apartment::receiveWater()
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

bool Apartment::cleanSewage()
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
    
bool Apartment::cleanWaste()
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





