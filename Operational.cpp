#include <string>
#include <iostream>
#include <exception>
using namespace std;

#include "Operational.h"
#include "State.h"
#include "Buildings.h"
#include "Damaged.h"
#include "ResourceMediator.h"

Operational::Operational()
{
	this->stateName = "Operational";
}

void Operational::handle() {
	cout<<"This building Operational!"<<endl;
}

void Operational::changeState() {
	if(this->building->resources!= nullptr)
	{
		//if the resources are available, the building will remain operational
	}
	else
	{
		State* newState = new Damaged();
		building->setState();
		cout<<"The building is now Damaged, please replace resources to restore it to operational!";
		//if the resources are unavailable, the building will become damaged.
	}
}

string Operational::getStateName()
{
	return this->stateName;
}
