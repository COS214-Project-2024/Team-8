// Government.cpp
#include "Government.h"
#include <algorithm>

Government::Government()
    : financeDepartment(nullptr), successor(nullptr), requestee(nullptr), budget(0.0), totalRevenue(0.0) {}

Government::Government(FinanceDepartment *financeDepartment)
    : financeDepartment(financeDepartment), successor(nullptr), requestee(nullptr), budget(0.0), totalRevenue(0.0) {}

void Government::attach(Citizen *citizen)
{
    citizenList.push_back(citizen);
    financeDepartment->addResidents(citizen);
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
    double totalCollectedPropertyTax = financeDepartment->delegateRequestForCollectionOffPropertyTax();
    for (auto citizen : citizenList)
    {
        citizen->setSatisfaction(citizen->getSatisfaction() - 2.0);
    }
    return totalCollectedPropertyTax;
}

double Government::requestCollectionOfIncomeTax()
{
    double totalCollectedIncomeTax = financeDepartment->delegateRequestForCollectionOffIncomeTax();
    for (auto citizen : citizenList)
    {
        citizen->setSatisfaction(citizen->getSatisfaction() - 3.0);
    }
    return totalCollectedIncomeTax;
}

double Government::requestCollectionOfBusinessTax()
{
    double totalCollectedBusinessTax = financeDepartment->delegateRequestForCollectionOfBusinessTax();
    for (auto citizen : citizenList)
    {
        citizen->setSatisfaction(citizen->getSatisfaction() - 2.5);
    }
    return totalCollectedBusinessTax;
}

double Government::requestCollectionOfSalesTax()
{
    double totalCollectedSalesTax = financeDepartment->delegateRequestForCollectionOfSalesTax();
    for (auto citizen : citizenList)
    {
        citizen->setSatisfaction(citizen->getSatisfaction() - 1.0);
    }
    return totalCollectedSalesTax;
}

double Government::requestAllocationOfUtilitiesFunds()
{
    double allocatedFundsForUtilities = financeDepartment->delegateRequestForAllocationOfUtilitiesFunds();
    notify();
    return allocatedFundsForUtilities;
}

double Government::requestAllocationOfPublicServiceBuildingsFunds()
{
    double allocatedFundsForPublicServiceBuildings = financeDepartment->delegateRequestForAllocationOfPublicServiceBuildingsFunds();
    notify();
    return allocatedFundsForPublicServiceBuildings;
}

double Government::requestAllocationOfTransportFunds()
{
    double allocatedFundsForTransport = financeDepartment->delegateRequestForAllocationOfTransportInfrastructureFunds();
    notify();
    return allocatedFundsForTransport;
}

double Government::requestAllocationOfRecreationFunds()
{
    double allocatedFundsForRecreation = financeDepartment->delegateRequestForAllocationOfLandmarkBuildingsFunds();
    notify();
    return allocatedFundsForRecreation;
}
void Government:: setBudget(double b){
    budget = b;
}

double Government:: getBudget() const{
    return budget;
}

void Government::setTotalRevenue(double b) { financeDepartment->setAvailableFunds(b); }
double Government::getTotalRevenue() const { return financeDepartment->getAvailableFunds(); }
