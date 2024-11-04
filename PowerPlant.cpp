#include <iostream>
#include <exception>
using namespace std;

#include "PowerPlant.h"
#include "State.h"
#include "UnderConstruction.h"
#include "Utility.h"
#include "Citizen.h"

PowerPlant::PowerPlant(string bName, int pReq, int wReq, double mCost, int sCost, int waste, int employment)
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

	this->listOfCitizens = new Citizen("NewCitizen",100,21,5.0);
}

void PowerPlant::requestState() {
	this->state->handle();
}

double PowerPlant::getMaintenanceCost() {
	return this->maintenanceCost;
}

int PowerPlant::getPowerReq() {
	return this->powerReq;
}

int PowerPlant::getSewageCost() {
	return this->sewageCost;
}

int PowerPlant::getWaterReq() {
	return this->waterReq;
}

int PowerPlant::getWasteCost() {
	return this->waste;
}

void PowerPlant::setState(State* newState)
{
	this->state = newState;
}


int PowerPlant::getJobsCreated()
{
	return employment;
}

string PowerPlant::getName()
{
	return this->buildingName;
}

string PowerPlant::getBuildingType()
{
	return this->buildingType;
}

int PowerPlant::payCitizen()
{
	cout<<"Paying citizen"<<endl;
	return 8000;
}

float PowerPlant::getSales() {
    return this->sales;
}

float PowerPlant::getProfit() {
    return this->profit;
}

void PowerPlant::addBuilding(){
	if(resources){
		resources->addBuilding(this);
	}
}

bool PowerPlant::getPower(){
	if(resources){
		resources->getPower(this);
	}
}

bool PowerPlant::cleanSewage(){
	if(resources){
		resources->cleanSewage(this);
	}
}

bool PowerPlant::cleanWaste(){
	if(resources){
		resources->cleanWaste(this);
	}
}

bool PowerPlant::getWater(){
	if(resources){
		resources->getWater(this);
	}
}