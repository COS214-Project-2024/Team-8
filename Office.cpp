#include <iostream>
#include <exception>
using namespace std;

#include "Office.h"
#include "State.h"
#include "UnderConstruction.h"
#include "Utility.h"
#include "Citizen.h"

Office::Office(string bName,int pReq, int wReq, double mCost, int sCost, int waste, float sales, float profit, int emp, int income)
{
	this->buildingName = bName;
	this->buildingType = "Landmark";
	this->powerReq = pReq;
	this->waterReq = wReq;
	this->maintenanceCost = mCost;
	this->sewageCost = sCost;
	this->waste = waste;
	this->sales = sales;
	this->profit = profit;
	this->employment = emp;
	this->income = income;

	this->state =  new UnderConstruction(); //when we instantiate a building it will be under construction
	this->state->handle(); //handle the state;
	this->state->changeState();//in case it needs to change

	this->listOfCitizens = new Citizen("NewCitizen",100,21,5.0);
	//this->listOfCitizens->adjustCitizenSatisfaction(5.0);
}

void Office::requestState() {
	this->state->handle();
}

double Office::getMaintenanceCost() {
	return this->maintenanceCost;
}

int Office::getPowerReq() {
	return this->powerReq;
}

int Office::getSewageCost() {
	return this->sewageCost;
}

int Office::getWaterReq() {
	return this->waterReq;
}

int Office::getWasteCost() {
	return this->waste;
}

void Office::setState(State* newState)
{
	this->state = newState;
}

int Office::getJobsCreated()
{
	return this->employment;
}

string Office::getName()
{
	return this->buildingName;
}

string Office::getBuildingType()
{
	return this->buildingType;
}

float Office::getProfit()
{
	return this->profit;
}

float Office::getSales()
{
	return this->sales;
}

int Office::payCitizen()
{
	cout<<"Paying citizen"<<endl;
	return 5000;
}

int Office::getCommercialIncome()
{
	return this->profit;
}

void Office::setBalance(double d)
{
	this->balance  = d ;
}

double Office::getBalance()
{
	return this->balance;
}

void Office::addBuilding(){
	if(resources){
		 resources->addBuilding(this);
	}

}

bool Office::getPower(){
	if(resources){
		return resources->getPower(this);
	}
return false;
}

bool Office::cleanSewage(){
	if(resources){
		return resources->cleanSewage(this);
	}
return false;
}

bool Office::cleanWaste(){
	if(resources){
		return resources->cleanWaste(this);
	}
return false;
}

bool Office::getWater(){
	if(resources){
		return resources->getWater(this);
	}
return false;
}