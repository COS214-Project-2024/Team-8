#include <exception>
using namespace std;

#ifndef __EconomicPolicies_h__
#define __EconomicPolicies_h__

// #include "PublicServicesPolicies.h"
// #include "Citizen.h"
#include "Policies.h"

class PublicServicesPolicies;
class Citizen;
// class Policies;
class EconomicPolicies;

class EconomicPolicies: public Policies
{
	public: PublicServicesPolicies* _unnamed_PublicServicesPolicies_;
	public: Citizen* _unnamed_Citizen_;

	public: void executePolicy();
};

#endif
