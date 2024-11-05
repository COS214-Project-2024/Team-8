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

void Apartment::addBuilding(){
	if(resources){
	 resources->addBuilding(this);
	}
}

bool Apartment::getPower(){
	if(resources){
		return resources->getPower(this);
	}
return false;
}

bool Apartment::cleanSewage(){
	if(resources){
		return resources->cleanSewage(this);
	}
return false;
}

bool Apartment::cleanWaste(){
	if(resources){
		return resources->cleanWaste(this);
	}
return false;
}

bool Apartment::getWater(){
	if(resources){
		return resources->getWater(this);
	}
return false;
}




