#include <iostream>
#include "BudgetAllocationSystem.h"
#include "CommercialTaxationSystem.h"
#include "ResidentialTaxationSystem.h"
#include "CommercialFactory.h"
#include "BuildingFactory.h"
#include "Buildings.h"
#include "FinanceDepartment.h"
#include <vector>
#include "Citizen.h"
#include "CitizenInterface.h"

//g++ -std=c++11 -o palesa_test PalesaMainTesting.cpp Citizen.cpp  Government.cpp FinanceDepartment.cpp CommercialTaxationSystem.cpp ResidentialTaxationSystem.cpp BudgetAllocationSystem.cpp  Shop.cpp Mall.cpp Office.cpp ShopFactory.cpp MallFactory.cpp OfficeFactory.cpp Stops.h TravelManager.h PopulationControl.h && ./palesa_test

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
    //testBudgetAllocationSystem();
    //testCommercialTaxationSystem();
    //testResidentialTaxationSystem();
    //testFinanceDepartment();
    testGovernment();
    return 0;
}
