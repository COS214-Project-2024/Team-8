#include <iostream>
#include <memory>
#include <exception>
using namespace std;

#include "TownHouse.h"
#include "State.h"
#include "UnderConstruction.h"
#include "Utility.h"
#include "Citizen.h"

TownHouse::TownHouse(string bName,int pReq, int wReq, double mCost, int sCost, int waste, int capacity)
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

void TownHouse::requestState() {
	this->state->handle();
}

Citizen* TownHouse::getListOfResidents() {
	return this->listOfCitizens;
}

double TownHouse::getMaintenanceCost() {
	return this->maintenanceCost;
}

int TownHouse::getPowerReq() {
	return this->powerReq;
}

int TownHouse::getWaterReq() {
	return this->waterReq;
}

int TownHouse::getSewageCost() {
	return this->sewageCost;
}

int TownHouse::getWasteCost() {
	return this->waste;
}

void TownHouse::setState(State* newState)
{
	this->state = newState;
}

int TownHouse::getCapacity()
{
	return this->capacity;
}

string TownHouse::getName()
{
	return this->buildingName;
}

void TownHouse::addBuilding(){
	if(resources){
		 resources->addBuilding(this);
	}

}

bool TownHouse::getPower(){
	if(resources){
		return resources->getPower(this);
	}
return false;
}

bool TownHouse::cleanSewage(){
	if(resources){
		return resources->cleanSewage(this);
	}
return false;
}

bool TownHouse::cleanWaste(){
	if(resources){
		return resources->cleanWaste(this);
	}
return false;
}

bool TownHouse::getWater(){
	if(resources){
		return resources->getWater(this);
	}
return false;
}