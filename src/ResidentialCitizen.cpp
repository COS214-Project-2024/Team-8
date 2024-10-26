#include "ResidentialCitizen.h"
#include "Buildings.h"
#include <memory>

ResidentialCitizen::ResidentialCitizen(std::unique_ptr<CitizenInterface> baseCitizen)
    : CitizenType(std::move(baseCitizen)), hasResidence(false), ownsProperty(false), currTaxRate(0.0f) {}

void ResidentialCitizen::moveIntoResidence(Buildings* building) {
    if (!hasResidence && building != nullptr) {
        hasResidence = true;
        adjustCitizenSatisfaction(15.0f);
    }
}

float ResidentialCitizen::calculateTax() {
    float tax = salary * (currTaxRate / 100);
    if (ownsProperty) {
        tax += 150.0f; // Additional property tax if the citizen owns property
    }
    return tax;
}

void ResidentialCitizen::applyTax() {
    salary -= calculateTax();
}

void ResidentialCitizen::upgradeResidence(float satisfactionBoost) {
    adjustCitizenSatisfaction(satisfactionBoost);
}
