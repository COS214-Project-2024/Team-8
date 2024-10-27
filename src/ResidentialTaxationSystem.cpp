using namespace std;
#include <iostream>
#include "ResidentialTaxationSystem.h"

float ResidentialTaxationSystem::collectIncomeTaxes(float incomeTaxRate, float totalResidentsIncomes) {
    float totalIncomeTaxes = incomeTaxRate * totalResidentsIncomes;
    cout << "💰 Total Income Taxes Collected: R " << totalIncomeTaxes << endl;
    return totalIncomeTaxes;
}

float ResidentialTaxationSystem::collectPropertyTaxes(float propertyTaxRate, float totalResidentsIncomes) {
    float totalPropertyTaxes = propertyTaxRate * totalResidentsIncomes;
    cout << "🏡 Total Property Taxes Collected: R " << totalPropertyTaxes << endl;
    return totalPropertyTaxes;
}
