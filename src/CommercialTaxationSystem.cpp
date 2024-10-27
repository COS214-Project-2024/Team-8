using namespace std;
#include <iostream>
#include "CommercialTaxationSystem.h"

double CommercialTaxationSystem::collectBusinessTaxes(double businessTaxRate, double totalBusinessProfits) {
    double totalBusinessTaxes = businessTaxRate * totalBusinessProfits;
    cout << "💰 Total Business Taxes Collected: R " << totalBusinessTaxes << endl;
    return totalBusinessTaxes;
}

double CommercialTaxationSystem::collectSalesTaxes(double salesTaxRate, double totalBusinessProfits) {
    double totalSalesTaxes = salesTaxRate * totalBusinessProfits;
    cout << "🛒 Total Sales Taxes Collected: R " << totalSalesTaxes << endl;
    return totalSalesTaxes;
}
