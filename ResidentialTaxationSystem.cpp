using namespace std;
#include <iostream>
#include "ResidentialTaxationSystem.h"

double ResidentialTaxationSystem::collectIncomeTax(double incomeTaxRate, double residentsIncome)
{
    double incomeTax = incomeTaxRate * residentsIncome;
    cout << "💰 Income Tax Collected: R " << incomeTax << endl;
    return incomeTax;
}

double ResidentialTaxationSystem::collectPropertyTax(double propertyTaxRate, double residentsIncome)
{
    double propertyTax = propertyTaxRate * residentsIncome;
    cout << "🏡 Property Tax Collected: R " << propertyTax << endl;
    return propertyTax;
}
