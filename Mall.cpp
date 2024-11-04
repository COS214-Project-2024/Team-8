#include <iostream>
#include <string>
#include <exception>
using namespace std;

#include "Mall.h"
#include "State.h"
#include "UnderConstruction.h"
#include "ResourceMediator.h"
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
	this->listOfCitizens->adjustCitizenSatisfaction(5.0);
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


bool Mall::payMaintenance()
{
	if(this->maintenanceCost > 200)
	{
		this->resources->useRevenue(100, this);
		this->maintenanceCost = this->maintenanceCost - 100;
		cout<<"successfully paid maintenance."<<endl;
		return true;
	}
	else
	{
		cout<<"insufficient funds to pay maintenance"<<endl;
		this->state->changeState();
		return false;
	}
}

bool Mall::receivePower()
{
		if(this->maintenanceCost > 200)
	{
		this->resources->useRevenue(100, this);
		this->maintenanceCost = this->maintenanceCost - 100;
		cout<<"successfully paid maintenance."<<endl;
		return true;
	}
	else
	{
		cout<<"insufficient funds to pay maintenance"<<endl;
		this->state->changeState();
		return false;
	}
}

bool Mall::receiveWater()
{
		if(this->waterReq > 200)
	{
		this->resources->useWater(100, this);
		this->maintenanceCost = this->maintenanceCost - 100;
		cout<<"successfully recieved water."<<endl;
		return true;
	}
	else
	{
		cout<<"insufficient funds to recieve water."<<endl;
		this->state->changeState();
		return false;
	}
}

bool Mall::cleanSewage()
{
		if(this->maintenanceCost > 200)
	{
		this->resources->cleanSewage(100, this);
		this->maintenanceCost = this->maintenanceCost - 100;
		cout<<"successfully cleaned sewage."<<endl;
		return true;
	}
	else
	{
		cout<<"insufficient funds to clean sewage."<<endl;
		this->state->changeState();
		return false;
	}
}
    
bool Mall::cleanWaste()
{
		if(this->maintenanceCost > 200)
	{
		this->resources->cleanWaste(100, this);
		this->maintenanceCost = this->maintenanceCost - 100;
		cout<<"successfully cleaned waste."<<endl;
		return true;
	}
	else
	{
		cout<<"insufficient funds to clean waste"<<endl;
		this->state->changeState();
		return false;
	}
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

// Added missing function
void Mall::operation() {
    cout << "Mall " << buildingName << " is operating." << endl;
}