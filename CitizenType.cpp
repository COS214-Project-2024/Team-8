#include "CitizenType.h"
using namespace std;

CitizenType::CitizenType(std::unique_ptr<CitizenInterface> citizen)
    : baseCitizen(std::move(citizen)) {}

std::unique_ptr<CitizenInterface> CitizenType::clone()
{
    return std::make_unique<CitizenType>(*this);
}

void CitizenType::update(float newTaxRate)
{
    if (baseCitizen)
    {
        baseCitizen->update(newTaxRate);
    }
}
void Government::notify()
{
    for (Citizen * citizen : CitizenList)
    {
        double incomeTax;
        double propertyTax;
        if (citizen->getEmployementStatus() == true)
        {
            citizen->update(incomeTax);
        }
        else if (citizen->getPropertyOwnershipStatus() == true)
        {
            citizen->update(propertyTax);
        }
        else if (citizen->getPropertyOwnershipStatus() && citizen->getEmployementStatus())
        {
            double combinedTax = incomeTax + propertyTax;
            citizen->update(combinedTax);
        }
        else
        {
            // assuming the citizen is unemployed
            citizen->update(0.0f);
        }
    }
}

void CitizenType::makeRequest(Government *government, std::string requestDetails)
{
    if (baseCitizen && government)
    {
        baseCitizen->makeRequest(government, requestDetails);
    }
}

void CitizenType::useTransport(Transport *transport)
{
    if (baseCitizen && transport)
    {
        baseCitizen->useTransport(transport);
    }
}

void CitizenType::adjustCitizenSatisfaction(float newSatisfaction)
{
    if (baseCitizen)
    {
        baseCitizen->adjustCitizenSatisfaction(newSatisfaction);
    }
}

void CitizenType::requestPublicService(std::string serviceType, float impact)
{
    if (baseCitizen)
    {
        baseCitizen->requestPublicService(serviceType, impact);
    }
}

void CitizenType::attendEvent(std::string eventName, float impact)
{
    if (baseCitizen)
    {
        baseCitizen->requestPublicService(eventName, impact);
    }
}

float CitizenType::evaluateHappiness()
{
    if (baseCitizen)
    {
        return baseCitizen->evaluateHappiness();
    }
}

float CitizenType::getSalary()
{
    if (baseCitizen)
    {
        return baseCitizen->getSalary();
    }
}

void CitizenType::setSalary(float newSalary)
{
    if (baseCitizen)
    {
        baseCitizen->setSalary(newSalary);
    }
}

float CitizenType::getSatisfaction()
{
    if (baseCitizen)
    {
        return baseCitizen->getSatisfaction();
    }
}

bool CitizenType::getEmployementStatus()
{
    if (baseCitizen)
    {
        return baseCitizen->getEmployementStatus();
    }
}

void CitizenType::setEmploymentStatus(bool employmentStatus)
{
    if (baseCitizen)
    {
        baseCitizen->setEmploymentStatus(employmentStatus);
    }
}

bool CitizenType::getPropertyOwnershipStatus()
{
    if (baseCitizen)
    {
        return baseCitizen->getPropertyOwnershipStatus();
    }
}

void CitizenType::setPropertyOwnership(bool ownsProperty)
{
    if (baseCitizen)
    {
        baseCitizen->setPropertyOwnership(ownsProperty);
    }
}

int CitizenType::getAge()
{
    if (baseCitizen)
    {
        return baseCitizen->getAge();
    }
}

std::string CitizenType::getName()
{
    if (baseCitizen)
    {
        return baseCitizen->getName();
    }
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
