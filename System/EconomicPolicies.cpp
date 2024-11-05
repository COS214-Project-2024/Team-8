#include <exception>
using namespace std;

#include "EconomicPolicies.h"
#include "PublicServicesPolicies.h"
#include "Citizen.h"
#include "Policies.h"
#include "Government.h"

EconomicPolicies::EconomicPolicies(Government* govt) : Policies(govt) {}

void EconomicPolicies::executePolicy() {
    government->requestCollectionOfIncomeTax();
    government->requestCollectionOfBusinessTax();
    government->requestCollectionOfSalesTax();
    government->notify();
}

