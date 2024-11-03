using namespace std;
#include <iostream>
#include "CommercialTaxationSystem.h"

CommercialTaxationSystem::CommercialTaxationSystem()
{
}

double CommercialTaxationSystem::collectBusinessTax(double businessTaxRate, double businessProfit)
{
    double totalBusinessTaxes = businessTaxRate * businessProfit;
    cout << "💰 Total Business Taxes Collected: R " << totalBusinessTaxes << endl;
    return totalBusinessTaxes;
}

double CommercialTaxationSystem::collectSalesTax(double salesTaxRate, double businessProfit) {
    double totalSalesTaxes = salesTaxRate * businessProfit;
    cout << "🛒 Total Sales Taxes Collected: R " << totalSalesTaxes << endl;
    return totalSalesTaxes;
}
