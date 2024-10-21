#include <exception>
using namespace std;

#ifndef __PublicServicesPolicies_h__
#define __PublicServicesPolicies_h__

// #include "Citizen.h"
// #include "EconomicPolicies.h"

class Citizen;
class EconomicPolicies;
class PublicServicesPolicies;

class PublicServicesPolicies
{
	public: Citizen* _unnamed_Citizen_;
	public: EconomicPolicies* _unnamed_EconomicPolicies_;

	public: void executePolicy();
};

#endif
