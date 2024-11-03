#include <exception>
using namespace std;

#include "PublicServicesPolicies.h"
#include "Citizen.h"
#include "EconomicPolicies.h"
#include "Government.h"

// Constructor is already defined in header file
// PublicServicesPolicies::PublicServicesPolicies(Government* govt) : Policies(govt) {}

void PublicServicesPolicies::executePolicy() {
    government->requestCollectionOfSalesTax();
    government->requestAllocationOfEducationFunds();
    government->requestAllocationOfUtilitiesFunds();
    government->notify();
}

