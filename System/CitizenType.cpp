#include "CitizenType.h"
using namespace std;


void CitizenType::update(float newTaxRate)
{
   
        baseCitizen->update(newTaxRate);
    
}

void CitizenType::makeRequest(Government *government, std::string requestDetails)
{
    if (baseCitizen && government)
    {
        baseCitizen->makeRequest(government, requestDetails);
    }
}

void CitizenType::useTransport(Stops *stop, int capacity, bool bestRoute)
{
        baseCitizen->useTransport(stop, capacity, bestRoute);
}


void CitizenType::adjustCitizenSatisfaction(float newSatisfaction)
{
   
        baseCitizen->adjustCitizenSatisfaction(newSatisfaction);
    
}

void CitizenType::requestPublicService(std::string serviceType, float impact)
{
   
        baseCitizen->requestPublicService(serviceType, impact);
    
}

void CitizenType::attendEvent(std::string eventName, float impact)
{
   
        baseCitizen->requestPublicService(eventName, impact);
    
}

float CitizenType::evaluateHappiness()
{
   
        return baseCitizen->evaluateHappiness();
    
}

float CitizenType::getSalary()
{
   
        return baseCitizen->getSalary();
    
}

void CitizenType::setSalary(float newSalary)
{
   
        baseCitizen->setSalary(newSalary);
    
}

float CitizenType::getSatisfaction()
{
   
        return baseCitizen->getSatisfaction();
    
}

bool CitizenType::getEmployementStatus()
{
   
        return baseCitizen->getEmployementStatus();
    
}

void CitizenType::setEmploymentStatus(bool employmentStatus)
{
   
        baseCitizen->setEmploymentStatus(employmentStatus);
    
}

bool CitizenType::getPropertyOwnershipStatus()
{
   
        return baseCitizen->getPropertyOwnershipStatus();
    
}

void CitizenType::setPropertyOwnership(bool ownsProperty)
{
   
        baseCitizen->setPropertyOwnership(ownsProperty);
    
}

int CitizenType::getAge()
{
   
        return baseCitizen->getAge();
    
}

std::string CitizenType::getName()
{
   
        return baseCitizen->getName();
}

void CitizenType::displayDetails()
{
    // Call the base class's displayDetails
    baseCitizen->displayDetails();

    // Additional behavior or information
    std::cout << "Citizen Type: " << citizenType() << std::endl;
}

std::string CitizenType::citizenType()
{
    return "Decorated Citizen Type";
}

float CitizenType::getTaxRate()
{
    return currTaxRate;
}

double CitizenType::getBalance()
{
    return balance;
}

void CitizenType::setBalance(double newBalance)
{
    balance = newBalance;
}

void CitizenType::setSatisfaction(int newSatisfaction)
{
    satisfaction = newSatisfaction;
}

void CitizenType::addKnownLocations(Stops* stop) {
    if (baseCitizen && stop) {
        baseCitizen->addKnownLocations(stop);
    }
}