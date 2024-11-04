#include "CommercialTaxationSystem.h"
#include <iostream>

CommercialTaxationSystem::CommercialTaxationSystem() {}

double CommercialTaxationSystem::collectBusinessTax(double businessTaxRate, double businessProfit)
{
    double totalBusinessTaxes = businessTaxRate * businessProfit;
    std::cout << "💰 Total Business Taxes Collected: R " << totalBusinessTaxes << std::endl;
    return totalBusinessTaxes;
}

double CommercialTaxationSystem::collectSalesTax(double salesTaxRate, double businessProfit)
{
    double totalSalesTaxes = salesTaxRate * businessProfit;
    std::cout << "🛒 Total Sales Taxes Collected: R " << totalSalesTaxes << std::endl;
    return totalSalesTaxes;
}