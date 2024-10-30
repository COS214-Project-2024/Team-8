#include <exception>
using namespace std;
#include "FinanceDepartment.h"
#include "Government.h"
#include "Citizen.h"
#include "Policies.h"
#include "Buildings.h"
#include <iostream>
#include <iomanip>
#include <iostream>
using namespace std;

void Government::attach(Citizen *citizen)
{
}
void Government::detach(Citizen *citizen)
{
}

void Government::notify()
{
}
Government::Government(FinanceDepartment *financeDepartment)
    : financeDepartment(financeDepartment),
      citizenList(nullptr),
      successor(nullptr) {}
void Government::requestCollectionOfTaxes()
{

    cout << "💰 Collecting taxes from residents (Income and Property Taxes) and businesses (Business and Sales Taxes)" << endl;
    financeDepartment->delegateRequestForCollectionOfTaxes();
    cout << "✅ Tax collection processed!" << endl;
}

void Government::requestAllocationOfPublicServiceBuildingsFunds()
{
    double totalPublicServiceBuildingsFunds = 0.0;
    totalPublicServiceBuildingsFunds = financeDepartment->delegateRequestForAllocationOfPublicServiceBuildingsFunds();
    std::cout << "🏛️ Public Service Buildings Funds Allocated: R"
              << totalPublicServiceBuildingsFunds << std::endl;
}

void Government::requestAllocationOfUtilitiesFunds()
{
    double totalUtilitiesFunds = 0.0;
    totalUtilitiesFunds = financeDepartment->delegateRequestForAllocationOfUtilitiesFunds();
    std::cout << "💧 Utilities Funds Allocated: R"
              << totalUtilitiesFunds << std::endl;
}

void Government::requestAllocationOfTransportInfrastructureFunds()
{
    double totalTransportInfrastructureFunds = 0.0;
    totalTransportInfrastructureFunds = financeDepartment->delegateRequestForAllocationOfTransportInfrastructureFunds();
    std::cout << "🚆 Transport Infrastructure Funds Allocated: R"
              << totalTransportInfrastructureFunds << std::endl;
}

void Government::requestAllocationOfLandmarkBuildingsFunds()
{
    double totalLandmarkBuildingsFunds = 0.0;
    totalLandmarkBuildingsFunds = financeDepartment->delegateRequestForAllocationOfLandmarkBuildingsFunds();
    std::cout << "🏰 Landmark Buildings Funds Allocated: R"
              << totalLandmarkBuildingsFunds << std::endl;
}































// Government.cpp
#include "Government.h"
#include <algorithm>

Government::Government()
    : financeDepartment(nullptr),successor(nullptr), requestee(nullptr), budget(0.0), totalRevenue(0.0) {}

Government::Government(FinanceDepartment *financeDepartment)
    : financeDepartment(financeDepartment) ,successor(nullptr), requestee(nullptr), budget(0.0), totalRevenue(0.0) {}

void Government::attach(Citizen *citizen)
{
    citizenList.push_back(citizen);
}

void Government::detach(Citizen *citizen)
{
    auto it = std::find(citizenList.begin(), citizenList.end(), citizen);
    if (it != citizenList.end())
    {
        citizenList.erase(it);
    }
}

void Government::notify()
{
    for (auto citizen : citizenList)
    {
        // citizen->setSatisfaction(citizen->getSatisfaction() + 5.0);
        citizen->update(newTaxRate);
    }
}

void Government::addCommand(std::unique_ptr<Command> command)
{
    commands.push_back(std::move(command));
}

void Government::executeCommands()
{
    for (const auto &command : commands)
    {
        command->execute();
    }
    commands.clear();
}

double Government::requestCollectionOfPropertyTax()
{
    financeDepartment->delegateRequestForCollectionOffPropertyTax();
    for (auto citizen : citizenList)
    {
        citizen->setSatisfaction(citizen->getSatisfaction() - 2.0);
    }
    
}

double Government::requestCollectionOfIncomeTax()
{
    financeDepartment->delegateRequestForCollectionOffIncomeTax();
    for (auto citizen : citizenList)
    {
        citizen->setSatisfaction(citizen->getSatisfaction() - 3.0);
    }
}

double Government::requestCollectionOfBusinessTax()
{
    financeDepartment->delegateRequestForCollectionOffIncomeTax();
    for (auto citizen : citizenList)
    {
        citizen->setSatisfaction(citizen->getSatisfaction() - 2.5);
    }
}

void Government::requestCollectionOfSalesTax()
{
    for (auto citizen : citizenList)
    {
        citizen->setSatisfaction(citizen->getSatisfaction() - 1.0);
    }
}

float Government::requestAllocationOfUtilitiesFunds()
{
   
    notify();
}

float Government::requestAllocationOfHealthcareFunds()
{
 
    notify();
}

float Government::requestAllocationOfTransportFunds()
{
   
    notify();
}

float Government::requestAllocationOfEducationFunds()
{

    notify();
}

float Government::requestAllocationOfRecreationFunds()
{

    notify();
}

void Government::setBudget(double b) { budget = b; }
double Government::getBudget() const { return budget; }
double Government::getTotalRevenue() const { return totalRevenue; }
