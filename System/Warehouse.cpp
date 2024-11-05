#include <iostream>
#include <exception>
using namespace std;

#include "Warehouse.h"
#include "State.h"
#include "UnderConstruction.h"
#include "Utility.h"
#include "Citizen.h"

Warehouse::Warehouse(string bName, int pReq, int wReq, double mCost, int sCost, int waste, int employment)
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

	this->listOfCitizens = new Citizen();
}

void Warehouse::requestState() {
	this->state->handle();
}

double Warehouse::getMaintenanceCost() {
	return this->maintenanceCost;
}

int Warehouse::getPowerReq() {
	return this->powerReq;
}

int Warehouse::getSewageCost() {
	return this->sewageCost;
}

int Warehouse::getWaterReq() {
	return this->waterReq;
}

int Warehouse::getWasteCost() {
	return this->waste;
}

void Warehouse::setState(State* newState)
{
	this->state = newState;
}

int Warehouse::getJobsCreated()
{
	return employment; //NOT SURE - ask Tebogo what this should return
}

string Warehouse::getName()
{
	return this->buildingName;
}

string Warehouse::getBuildingType()
{
	return this->buildingType;
}

int Warehouse::payCitizen()
{
	cout<<"Paying citizen"<<endl;
	return 8000;
}

void Warehouse::addBuilding(){
	if(resources){
		 resources->addBuilding(this);
	}

}

bool Warehouse::getPower(){
	if(resources){
		return resources->getPower(this);
	}
return false;
}

bool Warehouse::cleanSewage(){
	if(resources){
		return resources->cleanSewage(this);
	}
return false;
}

bool Warehouse::cleanWaste(){
	if(resources){
		return resources->cleanWaste(this);
	}
return false;
}

bool Warehouse::getWater(){
	if(resources){
		return resources->getWater(this);
	}
return false;
}

