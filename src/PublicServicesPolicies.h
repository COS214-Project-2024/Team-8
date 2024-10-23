#include <exception>
using namespace std;

#ifndef PUBLICSERVICESPOLICIES_H
#define PUBLICSERVICESPOLICIES_H

// #include "Citizen.h"
// #include "EconomicPolicies.h"
#include "Policies.h"

class Citizen;
class EconomicPolicies;
class PublicServicesPolicies;

class PublicServicesPolicies : public Policies
{
	public: Citizen* citizen;
	public: EconomicPolicies* economicPolicies;
	explicit PublicServicesPolicies(Government* govt) : Policies(govt) {} // Command Pattern for policies
	public: void executePolicy() override; // Command Pattern for policies
};

#endif
