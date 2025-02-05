#include <iostream>
#include <exception>
using namespace std;

#include "School.h"
#include "State.h"
#include "UnderConstruction.h"
#include "Utility.h"
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
	this->state->changeState();//in case it needs to change

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

void School::setState(State* newState)
{
	this->state = newState;
}


int School::getJobsCreated()
{
	return employment; //NOT SURE - ask Tebogo what this should return
}

string School::getName()
{
	return this->buildingName;
}

string School::getBuildingType()
{
	return this->buildingType;
}

void School::addBuilding(){
	if(resources){
		 resources->addBuilding(this);
	}

}

bool School::getPower(){
	if(resources){
		return resources->getPower(this);
	}
return false;
}

bool School::cleanSewage(){
	if(resources){
		return resources->cleanSewage(this);
	}
return false;
}

bool School::cleanWaste(){
	if(resources){
		return resources->cleanWaste(this);
	}
return false;
}

bool School::getWater(){
	if(resources){
		return resources->getWater(this);
	}
return false;
}

float School::getEducationalCoverage()
{
	return this->educationCoverage;
}



