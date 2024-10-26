#include "EmployedCitizen.h"

EmployedCitizen::EmployedCitizen(std::unique_ptr<CitizenInterface> baseCitizen)
    : CitizenType(std::move(baseCitizen)) {
}

void EmployedCitizen::upscaleSalary(float percentage) {
    
}

std::unique_ptr<CitizenInterface> EmployedCitizen::clone() const {
    
}

void EmployedCitizen::update(float newTaxRate) {
   
}
