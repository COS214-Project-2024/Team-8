#include <iostream>
#include <exception>
using namespace std;

#include "State.h"
#include "Shop.h"
#include "UnderConstruction.h"
#include "Utility.h"
#include "Citizen.h"

Shop::Shop(string bName, int pReq, int wReq, double mCost, int sCost, int waste, float sales, float profit, int emp)
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

	this->listOfCitizens->adjustCitizenSatisfaction(5.0);
}

void Shop::requestState() {
	this->state->handle();
}

double Shop::getMaintenanceCost() {
	return this->maintenanceCost;
}

int Shop::getPowerReq() {
	return this->powerReq;
}

int Shop::getSewageCost() {
	return this->sewageCost;
}

int Shop::getWaterReq() {
	return this->waterReq;
}

int Shop::getWasteCost() {
	return this->waste;
}

void Shop::setState(State* newState)
{
	this->state = newState;
}

int Shop::getJobsCreated()
{
	return this->employment;
}

string Shop::getName()
{
	return this->buildingName;
}

string Shop::getBuildingType()
{
	return this->buildingType;
}

float Shop::getProfit()
{
	return this->profit;
}

float Shop::getSales()
{
	return this->sales;
}

int Shop::payCitizen()
{
	cout<<"Paying citizen"<<endl;
	return 5000;
}

int Shop::getCommercialIncome()
{
	return this->profit;
}

void Shop::setBalance(double d)
{
	this->balance  = d ;
}

double Shop::getBalance()
{
	return this->balance;
}

void Shop::addBuilding(){
	if(resources){
		resources->addBuilding(this);
	}
}

bool Shop::getPower(){
	if(resources){
		resources->getPower(this);
	}
}

bool Shop::cleanSewage(){
	if(resources){
		resources->cleanSewage(this);
	}
}

bool Shop::cleanWaste(){
	if(resources){
		resources->cleanWaste(this);
	}
}

bool Shop::getWater(){
	if(resources){
		resources->getWater(this);
	}
}

