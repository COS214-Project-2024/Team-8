// Government.cpp
#include "Government.h"
#include "FinanceDepartment.h"
#include "Citizen.h"
#include <algorithm>

Government::Government()
    : citizenList(),
      successor(nullptr),
      requestee(nullptr),
      commands(),
      budget(0.0),
      totalRevenue(0.0),
      currentTaxRate(0.0),
      financeDepartment(nullptr)
{
}

Government::Government(FinanceDepartment *financeDepartment)
    : citizenList(),
      successor(nullptr),
      requestee(nullptr),
      commands(),
      budget(0.0),
      totalRevenue(0.0),
      currentTaxRate(0.0),
      financeDepartment(financeDepartment)
{
}

void Government::attach(CitizenInterface *citizen)
{
    citizenList.push_back(citizen);
    // Cast to Citizen* if we're sure the CitizenInterface* is actually a Citizen*
    Citizen *concreteCitizen = dynamic_cast<Citizen *>(citizen);
    if (concreteCitizen)
    {
        financeDepartment->addResidents(concreteCitizen);
    }
}

void Government::detach(CitizenInterface *citizen)
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
        float incomeTaxRate = (float)financeDepartment->getResidentialIncomeTaxRate();
        float propertyTaxRate = (float)financeDepartment->getResidentialPropertyTaxRate();
        if (citizen->getEmployementStatus() == true)
        {
            citizen->update(incomeTaxRate);
        }
        else if (citizen->getPropertyOwnershipStatus() == true)
        {
            citizen->update(propertyTaxRate);
        }
        else if (citizen->getEmployementStatus() && citizen->getPropertyOwnershipStatus())
        {
            float combinedTaxRate = incomeTaxRate + propertyTaxRate;
            citizen->update(combinedTaxRate);
        }
        else
        {
            citizen->update(0.0f);
        }
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
void Government::setBudget(double b)
{
    budget = b;
}

double Government::getBudget() const
{
    return budget;
}

void Government::setTotalRevenue(double b) { financeDepartment->setAvailableFunds(b); }
double Government::getTotalRevenue() const { return financeDepartment->getAvailableFunds(); }

void Government::setSuccessor(Government *nextHandler)
{
    successor = nextHandler;
}

Government *Government::getSuccessor() const
{
    return successor;
}

Government::~Government() {}

double Government::requestAllocationOfEducationFunds()  // Changed from float to double
{
    double allocatedFundsForEducation = financeDepartment->delegateRequestForAllocationOfEducationFunds();
    notify();
    return allocatedFundsForEducation;
}
void Government:: handleRequest(std::string requestDetails) {}
