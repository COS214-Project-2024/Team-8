#include <iostream>
#include "BudgetAllocationSystem.h"
#include "CommercialTaxationSystem.h"
#include "ResidentialTaxationSystem.h"
#include "CommercialFactory.h"
#include "ShopFactory.h"
#include "MallFactory.h"
#include "OfficeFactory.h"
#include "FinanceDepartment.h"

void testBudgetAllocationSystem()
{
    std::cout << "\033[34m------------------------------NOW ALLOCATING FUNDS-----------------------:\033[0m\n";
    double availableFunds = 1000.0;
    BudgetAllocationSystem *budgetSystem = new BudgetAllocationSystem();
    std::cout << "\033[34mThe available funds are: " << availableFunds << "\033[0m" << std::endl;
    std::cout << "\033[34mThe funds allocated to each department of the system are as follows:\033[0m\n";
    std::cout << budgetSystem->allocateMedicalCenterFunds(availableFunds) << std::endl;
    std::cout << budgetSystem->allocateSchoolFunds(availableFunds) << std::endl;
    std::cout << budgetSystem->allocatePoliceStationFunds(availableFunds) << std::endl;
    std::cout << budgetSystem->allocatePowerPlantFunds(availableFunds) << std::endl;
    std::cout << budgetSystem->allocateWaterTowerFunds(availableFunds) << std::endl;
    std::cout << budgetSystem->allocateWastePlantFunds(availableFunds) << std::endl;
    std::cout << budgetSystem->allocateSewagePipeFunds(availableFunds) << std::endl;
    std::cout << budgetSystem->allocateRoadsFunds(availableFunds) << std::endl;
    std::cout << budgetSystem->allocateAirportsFunds(availableFunds) << std::endl;
    std::cout << budgetSystem->allocateTrainStationsFunds(availableFunds) << std::endl;
    std::cout << budgetSystem->allocateParkFunds(availableFunds) << std::endl;
    std::cout << budgetSystem->allocateMonumentFunds(availableFunds) << std::endl;
    std::cout << budgetSystem->allocateCulturalCenterFunds(availableFunds) << std::endl;
}

void testCommercialTaxationSystem()
{
    std::cout << "\033[34m------------------------------NOW COLLECTING COMMERCIAL TAXES-----------------------:\033[0m\n";
    CommercialTaxationSystem *taxSystem = new CommercialTaxationSystem();
    double businessTaxRate = 0.15;  // Example business tax rate (15%)
    double salesTaxRate = 0.10;     // Example sales tax rate (10%)
    double businessProfit = 500000; // Example profit (R 500,000)
    // Collect and display business taxes
    double businessTaxes = taxSystem->collectBusinessTax(businessTaxRate, businessProfit);
    // Collect and display sales taxes
    double salesTaxes = taxSystem->collectSalesTax(salesTaxRate, businessProfit);
}

void testResidentialTaxationSystem()
{
    std::cout << "\033[34m------------------------------NOW COLLECTING RESIDENTIAL TAXES-----------------------:\033[0m\n";
    ResidentialTaxationSystem *taxSystem = new ResidentialTaxationSystem();
    double incomeTaxRate = 0.18;     // Example income tax rate (18%)
    double propertyTaxRate = 0.05;   // Example property tax rate (5%)
    double residentsIncome = 350000; // Example income (R 350,000)
    // Collect and display income tax
    double incomeTax = taxSystem->collectIncomeTax(incomeTaxRate, residentsIncome);
    // Collect and display property tax
    double propertyTax = taxSystem->collectPropertyTax(propertyTaxRate, residentsIncome);
}
void testFinanceDepartment()
{
    CommercialFactory *shopFactory = new ShopFactory();
    CommercialFactory *mallFactory = new MallFactory();
    CommercialFactory *officeFactory = new OfficeFactory();
    Buildings *shop = shopFactory->createBuilding();
    Buildings *mall = mallFactory->createBuilding();
    Buildings *office = officeFactory->createBuilding();
    FinanceDepartment *financeDepartment = new FinanceDepartment();
    financeDepartment->addCommercialBuilding(shop);
    financeDepartment->addCommercialBuilding(mall);
    financeDepartment->addCommercialBuilding(office);
}
int main()
{
    testBudgetAllocationSystem();
    testCommercialTaxationSystem();
    testResidentialTaxationSystem();
    return 0;
}
