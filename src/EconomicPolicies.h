#include <exception>
using namespace std;

#ifndef ECONOMICPOLICIES_H
#define ECONOMICPOLICIES_H

// #include "PublicServicesPolicies.h"
// #include "Citizen.h"
#include "Policies.h"

class PublicServicesPolicies;
class Citizen;
// class Policies;
class EconomicPolicies;

class EconomicPolicies: public Policies
{
	public: 
		explicit EconomicPolicies(Government* govt); // Command Pattern for policies
		PublicServicesPolicies* psPolicies;
	    Citizen* citizen;
	    void executePolicy() override;
};

#endif
