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
	this->state->changeState();//in case it needs to change

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

void Monument::setState(State* newState)
{
	this->state = newState;
}

string Monument::getName()
{
	return this->buildingName;
}

string Monument::getBuildingType()
{
	return this->buildingType;
}



