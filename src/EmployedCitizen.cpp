#include "EmployedCitizen.h"
#include "Buildings.h"
#include <memory>

EmployedCitizen::EmployedCitizen(std::unique_ptr<CitizenInterface> baseCitizen)
    : CitizenType(std::move(baseCitizen)) {}

#include "EmployedCitizen.h"
#include "Buildings.h"
#include <iostream>

void EmployedCitizen::getEmployed(Buildings* building) {
    if (building) {
        // Set employment status and get salary
        baseCitizen->setEmploymentStatus(true); 
        float salary = building->payCitizen(); // Get salary from the building
        baseCitizen->setSalary(salary); // Set the salary in the base citizen
        baseCitizen->adjustCitizenSatisfaction(10.0f); // Adjust satisfaction

        // Output statement indicating successful employment
        std::cout << "Success! " << baseCitizen->getName() << " has secured a job at " 
                  << building->getName() << ". Their new salary is $" << salary<<std::endl;
    } else {
        // Output statement if the building is null
        std::cout << "Employment failed: The specified building does not exist." << std::endl;
    }
}

void EmployedCitizen::jobPromotion(float percentage) {
    // Calculate the salary increase based on percentage
    float salaryIncrease = salary * (percentage / 100.0f);
    salary += salaryIncrease; // Update the salary
    baseCitizen->setSalary(salary); // Set the new salary in the base citizen
    baseCitizen->adjustCitizenSatisfaction(15.0f); // Adjust satisfaction after promotion

    // Output statement indicating the promotion
    std::cout << "Congratulations! " << baseCitizen->getName() << " has received a promotion! "
              << "Their salary has increased by " << percentage << "% to $" << salary << std::endl;
}

std::string EmployedCitizen::citizenType() {
    // Output statement to indicate the citizen type
    std::cout << baseCitizen->getName() << " is classified as an Employed citizen." << std::endl;
    return "Employed";
}
