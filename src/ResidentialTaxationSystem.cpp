using namespace std;
#include <iostream>
#include "ResidentialTaxationSystem.h"

double ResidentialTaxationSystem::collectIncomeTaxes(double incomeTaxRate, double totalResidentsIncomes) {
    double totalIncomeTaxes = incomeTaxRate * totalResidentsIncomes;
    cout << "💰 Total Income Taxes Collected: R " << totalIncomeTaxes << endl;
    return totalIncomeTaxes;
}

double ResidentialTaxationSystem::collectPropertyTaxes(double propertyTaxRate, double totalResidentsIncomes) {
    double totalPropertyTaxes = propertyTaxRate * totalResidentsIncomes;
    cout << "🏡 Total Property Taxes Collected: R " << totalPropertyTaxes << endl;
    return totalPropertyTaxes;
}
