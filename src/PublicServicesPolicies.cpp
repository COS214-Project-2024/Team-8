#include <exception>
using namespace std;

#include "PublicServicesPolicies.h"
#include "Citizen.h"
#include "EconomicPolicies.h"
#include "Government.h"

PublicServicesPolicies::PublicServicesPolicies(Government* govt)
    : Policies(govt) {}

void PublicServicesPolicies::executePolicy() {
    government->requestAllocationOfHealthcareFunds();
    government->requestAllocationOfEducationFunds();
    government->requestAllocationOfUtilitiesFunds();
    government->notify();
}

