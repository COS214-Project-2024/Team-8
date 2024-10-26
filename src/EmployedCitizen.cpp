#include "EmployedCitizen.h"
#include "Buildings.h"
#include <memory>

EmployedCitizen::EmployedCitizen(std::unique_ptr<CitizenInterface> baseCitizen)
    : CitizenType(std::move(baseCitizen)), hasJob(false), ownsProperty(false), currTaxRate(0.0f) {}

void EmployedCitizen::getEmployed(Buildings* building) {
    if (!hasJob && building != nullptr) {
        hasJob = true;
        salary = building->payCitizen();
        adjustCitizenSatisfaction(10.0f);
    }
}

float EmployedCitizen::calculateTax() {
	if(hasJob){
		return salary * currTaxRate;
	}
}

void EmployedCitizen::applyTax() {
	float taxAmount = calculateTax();
    salary -= taxAmount;
}

void EmployedCitizen::jobPromotion(float percentage) {
	float salaryIncrease = salary * (percentage/ 100.0f);
    salary += salaryIncrease;
}
void EmployedCitizen::jobPromotion(float percentage) {
    salary += salary * (percentage / 100);
    adjustCitizenSatisfaction(15.0f);
}
