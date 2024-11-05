#include <iostream>
#include <exception>
using namespace std;

#include "MedicalCenter.h"
#include "State.h"
#include "UnderConstruction.h"
#include "Utility.h"
#include "Citizen.h"

MedicalCenter::MedicalCenter(string bName, int pReq, int wReq, double mCost, int sCost, int waste, int employment, float hCov)
{
	this->buildingName = bName;
	this->buildingType = "Public Service";
	this->powerReq = pReq;
	this->waterReq = wReq;
	this->maintenanceCost = mCost;
	this->sewageCost = sCost;
	this->waste = waste;
	this->employment = employment;
	this->healthCoverage = hCov;
	this->birthRate = 50;

	this->state =  new UnderConstruction(); //when we instantiate a building it will be under construction
	this->state->handle(); //handle the state;
	this->state->changeState();//in case it needs to change

	this->listOfCitizens = new Citizen("NewCitizen",100,21,5.0);
}

void MedicalCenter::requestState() {
	this->state->handle();
}

double MedicalCenter::getMaintenanceCost() {
	return this->maintenanceCost;
}

int MedicalCenter::getPowerReq() {
	return this->powerReq;
}

int MedicalCenter::getSewageCost() {
	return this->sewageCost;
}

int MedicalCenter::getWaterReq() {
	return this->waterReq;
}

int MedicalCenter::getWasteCost() {
	return this->waste;
}

void MedicalCenter::setState(State* newState)
{
	this->state = newState;
}

int MedicalCenter::getJobsCreated()
{
	return employment; //NOT SURE - ask Tebogo what this should return
}

string MedicalCenter::getName()
{
	return this->buildingName;
}

string MedicalCenter::getBuildingType()
{
	return this->buildingType;
}

float MedicalCenter::getHealthCoverage()
{
	return this->healthCoverage;
}


int MedicalCenter::getBirthRate()
{
	return this->birthRate;
}

void MedicalCenter::addBuilding(){
	if(resources){
		 resources->addBuilding(this);
	}
}

bool MedicalCenter::getPower(){
	if(resources){
	 return resources->getPower(this);
	}
return false;

}

bool MedicalCenter::cleanSewage(){
	if(resources){
		return resources->cleanSewage(this);
	}
return false;
}

bool MedicalCenter::cleanWaste(){
	if(resources){
		return resources->cleanWaste(this);
	}
return false;
}

bool MedicalCenter::getWater(){
	if(resources){
		return resources->getWater(this);
	}
return false;
}



