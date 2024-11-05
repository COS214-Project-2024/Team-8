#include <iostream>
#include <exception>
using namespace std;

#include "Factories.h"
#include "State.h"
#include "UnderConstruction.h"
#include "Utility.h"
#include "Citizen.h"

Factories::Factories(string bName, int pReq, int wReq, double mCost, int sCost, int waste, int employment)
{
	this->buildingName = bName;
	this->buildingType = "Industrial";
	this->powerReq = 500000;
	this->waterReq = 250000;
	this->maintenanceCost = 75000;
	this->sewageCost = 5000;
	this->waste = 7000;
	this->employment = employment;

	this->state =  new UnderConstruction(); //when we instantiate a building it will be under construction
	this->state->handle(); //handle the state;
	this->state->changeState();//in case it needs to change

	this->listOfCitizens = new Citizen("newCitizen",100,23,5.0);
}

void Factories::requestState() {
	this->state->handle();
}

double Factories::getMaintenanceCost() {
	return this->maintenanceCost;
}

int Factories::getPowerReq() {
	return this->powerReq;
}

int Factories::getSewageCost() {
	return this->sewageCost;
}

int Factories::getWaterReq() {
	return this->waterReq;
}

int Factories::getWasteCost() {
	return this->waste;
}

void Factories::setState(State* newState)
{
	this->state = newState;
}

int Factories::getJobsCreated()
{
	return employment; //NOT SURE - ask Tebogo what this should return
}

string Factories::getName()
{
	return this->buildingName;
}

string Factories::getBuildingType()
{
	return this->buildingType;
}

int Factories::payCitizen()
{
	cout<<"Paying citizen"<<endl;
	return 8000;
}

void Factories::addBuilding(){
	if(resources){
		resources->addBuilding(this);
	}
}

bool Factories::getPower(){
	if(resources){
		return resources->getPower(this);
	}
return false;
}

bool Factories::cleanSewage(){
	if(resources){
		return resources->cleanSewage(this);
	}
return false;
}

bool Factories::cleanWaste(){
	if(resources){
		return resources->cleanWaste(this);
	}
return false;
}

bool Factories::getWater(){
	if(resources){
		return resources->getWater(this);
	}
return false;
}