#include <iostream>
#include <exception>
using namespace std;

#include "Park.h"
#include "State.h"
#include "UnderConstruction.h"
#include "Utility.h"
#include "Citizen.h"

Park::Park(string bName,int pReq, int wReq, double mCost, int sCost, int waste)
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
	//this->listOfCitizens->adjustCitizenSatisfaction(5.0);
}

void Park::requestState() {
	this->state->handle();
}

double Park::getMaintenanceCost() {
	return this->maintenanceCost;
}

int Park::getPowerReq() {
	return this->powerReq;
}

int Park::getSewageCost() {
	return this->sewageCost;
}

int Park::getWaterReq() {
	return this->waterReq;
}

int Park::getWasteCost() {
	return this->waste;
}

void Park::setState(State* newState)
{
	this->state = newState;
}

string Park::getName()
{
	return this->buildingName;
}

string Park::getBuildingType()
{
	return this->buildingType;
}

void Park::addBuilding(){
	if(resources){
		 resources->addBuilding(this);
	}

}

bool Park::getPower(){
	if(resources){
		return resources->getPower(this);
	}
return false;
}

bool Park::cleanSewage(){
	if(resources){
		return resources->cleanSewage(this);
	}
return false;
}

bool Park::cleanWaste(){
	if(resources){
		return resources->cleanWaste(this);
	}
return false;
}

bool Park::getWater(){
	if(resources){
		return resources->getWater(this);
	}
return false;
}

