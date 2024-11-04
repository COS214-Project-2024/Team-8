#include <string>
#include <iostream>
#include <exception>
using namespace std;

#include "PoliceStation.h"
#include "State.h"
#include "UnderConstruction.h"
#include "Utility.h"
#include "Citizen.h"

PoliceStation::PoliceStation(string bName,int pReq, int wReq, double mCost, int sCost, int waste, int employment, float sCov)
{
	this->buildingName = bName;
	this->buildingType = "Public Service";
	this->powerReq = pReq;
	this->waterReq = wReq;
	this->maintenanceCost = mCost;
	this->sewageCost = sCost;
	this->waste = waste;
	this->employment = employment;
	this->securityCoverage = sCov;

	this->state =  new UnderConstruction(); //when we instantiate a building it will be under construction
	this->state->handle(); //handle the state;
	this->state->changeState();//in case it needs to change

	this->listOfCitizens = new Citizen("NewCitizen",100,21,5.0);
}

void PoliceStation::requestState() {
	this->state->handle();
}

double PoliceStation::getMaintenanceCost() {
	return this->maintenanceCost;
}

int PoliceStation::getPowerReq() {
	return this->powerReq;
}

int PoliceStation::getSewageCost() {
	return this->sewageCost;
}

int PoliceStation::getWaterReq() {
	return this->waterReq;
}

int PoliceStation::getWasteCost() {
	return this->waste;
}

void PoliceStation::setState(State* newState)
{
	this->state = newState;
}


int PoliceStation::getJobsCreated()
{
	return employment; //NOT SURE - ask Tebogo what this should return
}

string PoliceStation::getName()
{
	return this->buildingName;
}

string PoliceStation::getBuildingType()
{
	return this->buildingType;
}

float PoliceStation::getSecurityCoverage()
{
	return this->securityCoverage;
}


