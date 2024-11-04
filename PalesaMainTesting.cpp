#include <iostream>
#include "BudgetAllocationSystem.h"
#include "CommercialTaxationSystem.h"
#include "ResidentialTaxationSystem.h"
#include "CommercialFactory.h"
#include "BuildingFactory.h"
#include "Buildings.h"
#include "ShopFactory.h"
#include "MallFactory.h"
#include "OfficeFactory.h"
#include "CommercialFactory.h"
#include "FinanceDepartment.h"
#include <vector>
#include "Shop.h"
#include "Mall.h"
#include "Office.h"

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
    //    Shop(string bName, int pReq, int wReq, double mCost, int sCost, int waste, float sales, float profit, int emp);

    CommercialBuilding *shop = new Shop("ShopName", 100, 50, 2000.0, 100, 30, 1000.0f, 500.0f, 10);
    CommercialBuilding *mall = new Mall("MallName", 200, 100, 5000.0, 150, 50, 3000.0f, 1500.0f, 50);
    CommercialBuilding *office = new Office("OfficeName", 150, 80, 3000.0, 120, 40, 2000.0f, 1000.0f, 20, 50000);

    FinanceDepartment *financeDepartment = new FinanceDepartment();
    financeDepartment->addCommercialBuilding(shop);
    financeDepartment->addCommercialBuilding(mall);
    financeDepartment->addCommercialBuilding(office);

    for (int i = 0; i < 10; ++i)
    {
        CitizenInterface *citizen = new Citizen();
        financeDepartment->addResidents(citizen);
    }
    financeDepartment->setResidentialIncomeTaxRate(0.10);
    financeDepartment->setResidentialPropertyTaxRate(0.012);
    financeDepartment->setCommercialBusinessTaxRate(0.25);
    financeDepartment->setCommercialSalesTaxRate(0.08);
    financeDepartment->setAvailableFunds(4000000);

    double incomeTaxCollection = financeDepartment->delegateRequestForCollectionOffIncomeTax();
    double propertyTaxCollection = financeDepartment->delegateRequestForCollectionOffPropertyTax();
    double businessTaxCollection = financeDepartment->delegateRequestForCollectionOfBusinessTax();
    double salesTaxCollection = financeDepartment->delegateRequestForCollectionOfSalesTax();

    double publicServiceBuildingsFunds = financeDepartment->delegateRequestForAllocationOfPublicServiceBuildingsFunds();
    double landmarkBuildingsFunds = financeDepartment->delegateRequestForAllocationOfLandmarkBuildingsFunds();
    double transportInfrastructureFunds = financeDepartment->delegateRequestForAllocationOfTransportInfrastructureFunds();
    double utilitiesFunds = financeDepartment->delegateRequestForAllocationOfUtilitiesFunds();

    std::cout << "💰 Income Tax Collection: R" << incomeTaxCollection << std::endl;
    std::cout << "🏡 Property Tax Collection: R" << propertyTaxCollection << std::endl;
    std::cout << "🏢 Business Tax Collection: R" << businessTaxCollection << std::endl;
    std::cout << "🛍️ Sales Tax Collection: R" << salesTaxCollection << std::endl;
    std::cout << "🏗️ Public Service Buildings Funds: R" << publicServiceBuildingsFunds << std::endl;
    std::cout << "🏛️ Landmark Buildings Funds: R" << landmarkBuildingsFunds << std::endl;
    std::cout << "🚧 Transport Infrastructure Funds: R" << transportInfrastructureFunds << std::endl;
    std::cout << "💧 Utilities Funds: R" << utilitiesFunds << std::endl;
}
void testGovernment()
{
    FinanceDepartment *financeDept = new FinanceDepartment();
    Government *government = new Government(financeDept);

    for (int i = 0; i < 10; ++i)
    {
        CitizenInterface *citizen = new Citizen();
        government->attach(citizen);
    }
    // Set the government budget
    government->setBudget(1000000.0);
    std::cout << "Government budget set to: R" << government->getBudget() << std::endl;

    // Simulate tax collection and fund allocation
    double propertyTaxCollected = government->requestCollectionOfPropertyTax();
    double incomeTaxCollected = government->requestCollectionOfIncomeTax();
    double businessTaxCollected = government->requestCollectionOfBusinessTax();
    double salesTaxCollected = government->requestCollectionOfSalesTax();

    std::cout << "Tax Collections:" << std::endl;
    std::cout << "Property Tax Collected: R" << propertyTaxCollected << std::endl;
    std::cout << "Income Tax Collected: R" << incomeTaxCollected << std::endl;
    std::cout << "Business Tax Collected: R" << businessTaxCollected << std::endl;
    std::cout << "Sales Tax Collected: R" << salesTaxCollected << std::endl;

    // Allocate funds and test all allocations
    double utilitiesFunds = government->requestAllocationOfUtilitiesFunds();
    std::cout << "Allocated Utilities Funds: R" << utilitiesFunds << std::endl;

    double publicServiceBuildingsFunds = government->requestAllocationOfPublicServiceBuildingsFunds();
    std::cout << "Allocated Public Service Buildings Funds: R" << publicServiceBuildingsFunds << std::endl;

    double transportInfrastructureFunds = government->requestAllocationOfTransportFunds();
    std::cout << "Allocated Transport Infrastructure Funds: R" << transportInfrastructureFunds << std::endl;

    double educationFunds = government->requestAllocationOfEducationFunds();
    std::cout << "Allocated Education Funds: R" << educationFunds << std::endl;

    double recreationFunds = government->requestAllocationOfRecreationFunds();
    std::cout << "Allocated Recreation Funds: R" << recreationFunds << std::endl;
}
int main()
{
    testBudgetAllocationSystem();
    testCommercialTaxationSystem();
    testResidentialTaxationSystem();
    testFinanceDepartment();
    testGovernment();
    return 0;
}
