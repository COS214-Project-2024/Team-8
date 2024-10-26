#include "Citizen.h"
#include "Government.h"

Citizen::Citizen(const std::string& name, float salary, Government* government, bool hasJob, bool ownsProperty)
    : government(government), hasJob(hasJob), ownsProperty(ownsProperty) {
    this->name = name;
    this->salary = salary;
    this->satisfaction = 100.0f; 
}

Citizen::~Citizen() {
   
}

float Citizen::calculateTax() {
    
}

void Citizen::applyTax() {
    
}

void Citizen::jobPromotion(float percentage) {
    
}

std::unique_ptr<CitizenInterface> Citizen::clone() {
    
}

void Citizen::update(float newTaxRate) {
}

void Citizen::makeRequest(Government* government, std::string& requestDetails)
{
    
}

void Citizen::useTransport(Transport *transport)
{
}
