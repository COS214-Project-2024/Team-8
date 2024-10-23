#include <exception>
#include <string>
using namespace std;

#include "Citizen.h"
#include "City.h"
#include "Government.h"
#include "PublicServicesPolicies.h"
#include "EconomicPolicies.h"
#include "PopulationControl.h"
#include "Transport.h"

void Citizen::citizen(int aAge, string aName, double aSalary) {
	throw "Not yet implemented";
}

int Citizen::getAge() {
	return this->_age;
}

string Citizen::getName() {
	return this->_name;
}

double Citizen::getSalary() {
	return this->_salary;
}

double Citizen::getSatisfaction() {
	return this->_satisfaction;
}

Citizen* Citizen::clone() {
	throw "Not yet implemented";
}

void Citizen::update() {
	throw "Not yet implemented";
}

