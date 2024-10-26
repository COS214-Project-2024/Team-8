using namespace std;
#include <iostream>
#include "CommercialTaxationSystem.h"

float CommercialTaxationSystem::collectBusinessTaxes(float businessTaxRate, float totalBusinessProfits) {
    float totalBusinessTaxes = businessTaxRate * totalBusinessProfits;
    cout << "💰 Total Business Taxes Collected: R " << totalBusinessTaxes << endl;
    return totalBusinessTaxes;
}

float CommercialTaxationSystem::collectSalesTaxes(float salesTaxRate, float totalBusinessProfits) {
    float totalSalesTaxes = salesTaxRate * totalBusinessProfits;
    cout << "🛒 Total Sales Taxes Collected: R " << totalSalesTaxes << endl;
    return totalSalesTaxes;
}
