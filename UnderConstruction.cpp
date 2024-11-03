#include <string>
#include <iostream>
#include <exception>
using namespace std;

#include "UnderConstruction.h"
#include "State.h"
#include "Buildings.h"
#include "Operational.h"
#include "ResourceMediator.h"

UnderConstruction::UnderConstruction()
{
	this->stateName = "Under Construction";
}

void UnderConstruction::handle() {
	cout<<"This building is under construction!";
}

void UnderConstruction::changeState() {
	if(this->building->resources!= nullptr)
	{
		if(building->receivePower() && building->receivePower())
        {
            State* newState = new Operational();
            building->setState();
            cout<<"The building is now Operational, resources have been replenished!";
            //if the resources are available, the building will be repaired
            //the state will become operations
        }
	}
	else
	{
		//if the resources are unavailable, the building will become remain opertional.
		cout<<"No resources available. please replenish resources to make this building operational"<<endl;
	}
}

string UnderConstruction::getStateName()
{
	return this->stateName;
}
