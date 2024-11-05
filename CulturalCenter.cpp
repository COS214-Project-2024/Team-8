#include <iostream>
#include <exception>
using namespace std;

#include "CulturalCenter.h"
#include "State.h"
#include "UnderConstruction.h"
#include "Utility.h"
#include "Citizen.h"

CulturalCenter::CulturalCenter(string bName,int pReq, int wReq, double mCost, int sCost, int waste)
{
    this->buildingName = bName;
    this->buildingType = "Landmark";
    this->powerReq = pReq;
    this->waterReq = wReq;
    this->maintenanceCost = mCost;
    this->sewageCost = sCost;
    this->waste = waste;
    
    this->state =  new UnderConstruction();
    this->state->handle();
    this->state->changeState();

    this->listOfCitizens = new Citizen("New Citizen", 100, 23, 5.0);
    //this->listOfCitizens->adjustCitizenSatisfaction(5.0);
}

void CulturalCenter::requestState() {
    this->state->handle();
}

double CulturalCenter::getMaintenanceCost() {
    return this->maintenanceCost;
}

int CulturalCenter::getPowerReq() {
    return this->powerReq;
}

int CulturalCenter::getSewageCost() {
    return this->sewageCost;
}

int CulturalCenter::getWaterReq() {
    return this->waterReq;
}

int CulturalCenter::getWasteCost() {
    return this->waste;
}

void CulturalCenter::setState(State* newState)
{
    this->state = newState;
}

string CulturalCenter::getName()
{
    return this->buildingName;
}

string CulturalCenter::getBuildingType()
{
    return this->buildingType;
}


// Added missing function
int CulturalCenter::getJobsCreated() {
    return 10;  // Cultural centers provide jobs for staff, security, and maintenance
}

void CulturalCenter::addBuilding(){
	if(resources){
	 resources->addBuilding(this);
	}
}

bool CulturalCenter::getPower(){
	if(resources){
		return resources->getPower(this);
	}
return false;
}

bool CulturalCenter::cleanSewage(){
	if(resources){
		return resources->cleanSewage(this);
	}
return false;
}

bool CulturalCenter::cleanWaste(){
	if(resources){
		return resources->cleanWaste(this);
	}
return false;
}

bool CulturalCenter::getWater(){
	if(resources){
		return resources->getWater(this);
	}
return false;
}