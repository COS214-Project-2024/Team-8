#include <iostream>
#include <memory>
#include <exception>

using namespace std;

#include "Apartment.h"
#include "State.h"
#include "UnderConstruction.h"
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


string Apartment::getName()
{
	return this->buildingName;
}

// Added missing functions
string Apartment::getBuildingType() {
    return this->buildingType;
}

int Apartment::getJobsCreated() {
    return 5;  // Each apartment creates maintenance, management, and security jobs
}
// Added missing functions
string Apartment::getBuildingType() {
    return this->buildingType;
}

int Apartment::getJobsCreated() {
    return 5;  // Each apartment creates maintenance, management, and security jobs
}





