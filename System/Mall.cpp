#include <iostream>
#include <string>
#include <exception>
using namespace std;

#include "Mall.h"
#include "State.h"
#include "UnderConstruction.h"
#include "Utility.h"
#include "Citizen.h"

Mall::Mall(string bName,int pReq, int wReq, double mCost, int sCost, int waste, float sales, float profit, int emp)
{
	this->buildingName = bName;
	this->buildingType = "Commercial";
	this->powerReq = pReq;
	this->waterReq = wReq;
	this->maintenanceCost = mCost;
	this->sewageCost = sCost;
	this->waste = waste;
	this->sales = sales;
	this->profit = profit;
	this->employment = emp;

	this->state =  new UnderConstruction(); //when we instantiate a building it will be under construction
	this->state->handle(); //handle the state;
	this->state->changeState();//in case it needs to change

	this->listOfCitizens = new Citizen("NewCitizen",100,23,5.0);
	//this->listOfCitizens->adjustCitizenSatisfaction(5.0);
}

void Mall::requestState() {
	this->state->handle();
}

double Mall::getMaintenanceCost() {
	return this->maintenanceCost;
}

int Mall::getPowerReq() {
	return this->powerReq;
}

int Mall::getSewageCost() {
	return this->sewageCost;
}

int Mall::getWaterReq() {
	return this->waterReq;
}

int Mall::getWasteCost() {
	return this->waste;
}

void Mall::setState(State* newState)
{
	this->state = newState;
}

float Mall::getSales()
{
	return this->sales;
}


int Mall::getJobsCreated()
{
	return this->employment;
}

string Mall::getName()
{
	return this->buildingName;
}

string Mall::getBuildingType()
{
	return this->buildingType;
}

float Mall::getProfit()
{
	return this->profit;
}


int Mall::payCitizen()
{
	cout<<"Paying citizen"<<endl;
	return 5000;
}

int Mall::getCommercialIncome()
{
	return this->profit;
}

void Mall::setBalance(double d)
{
	this->balance  = d;
}

double Mall::getBalance()
{
	return this->balance;
}

void Mall::addBuilding(){
	if(resources){
		 resources->addBuilding(this);
	}
}

bool Mall::getPower(){
	if(resources){
		return resources->getPower(this);
	}
return false;
}

bool Mall::cleanSewage(){
	if(resources){
		return resources->cleanSewage(this);
	}
return false;
}

bool Mall::cleanWaste(){
	if(resources){
		return resources->cleanWaste(this);
	}
return false;
}

bool Mall::getWater(){
	if(resources){
		return resources->getWater(this);
	}
return false;
}