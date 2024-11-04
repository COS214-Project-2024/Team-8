#include <iostream>
#include <memory>
#include <vector>
#include <limits>
#include "Citizen.h"
#include "CitizenType.h"
#include "EmployedCitizen.h"
#include "PropertyOwner.h"
#include "Buildings.h"
#include "CommercialFactory.h"
#include "OfficeFactory.h"
#include "Office.h"
#include "HouseFactory.h"
#include "House.h"
#include "ResidentialFactory.h"

const std::string highlight = "\033[3;38;5;45m";
const std::string reset = "\033[0m";

void clearInput() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void waitForEnter() {
    std::cout << "\nPress Enter to continue...";
    clearInput();
    std::cin.get();
}

// Component 1: Basic Citizen Management
void createAndManageCitizens() {
    std::cout << "Executing: " << std::endl;
    std::cout << highlight << "auto citizen = std::make_unique<Citizen>(\"John Doe\", 50000, 30, 75);\n" << reset;
    auto citizen = std::make_unique<Citizen>("John Doe", 50000, 30, 75);
    
    std::cout << highlight << "citizen->displayDetails();\n" << reset;
    citizen->displayDetails();
    
    std::cout << highlight << "citizen->adjustCitizenSatisfaction(10);\n" << reset;
    citizen->adjustCitizenSatisfaction(10);
}

void demonstrateCitizenStates() {
    std::cout << "Executing: " << std::endl;
    auto citizen = std::make_unique<Citizen>("Jane Smith", 60000, 35, 80);
    
    std::cout << highlight << "Initial state:\n" << reset;
    citizen->displayDetails();
    
    std::cout << highlight << "Setting employment status to true:\n" << reset;
    citizen->setEmploymentStatus(true);
    
    std::cout << highlight << "Setting property ownership to true:\n" << reset;
    citizen->setPropertyOwnership(true);
    
    std::cout << highlight << "Final state:\n" << reset;
    citizen->displayDetails();
}

// Component 2: Citizen Type Decorators
void demonstrateEmployedCitizen() {
    std::cout << "Executing: " << std::endl;
    auto baseCitizen = std::make_unique<Citizen>("Bob Wilson", 45000, 28, 70);
    std::cout << highlight << "Creating Employed Citizen decorator\n" << reset;
    auto employedCitizen = std::make_unique<EmployedCitizen>(std::move(baseCitizen));
    CommercialFactory *downtownOfficeFactory = new OfficeFactory();
    Buildings *office = downtownOfficeFactory->createBuilding();
    
    std::cout << highlight << "employedCitizen->getEmployed(office);\n" << reset;
    employedCitizen->getEmployed(office);
    
    std::cout << highlight << "employedCitizen->jobPromotion(10);\n" << reset;
    employedCitizen->jobPromotion(10);

    delete downtownOfficeFactory;
    delete office;
}

void demonstratePropertyOwner() {
    std::cout << "Executing: " << std::endl;
    auto baseCitizen = std::make_unique<Citizen>("Alice Brown", 70000, 40, 85);
    std::cout << highlight << "Creating Property Owner decorator\n" << reset;
    auto propertyOwner = std::make_unique<PropertyOwner>(std::move(baseCitizen));
    
    ResidentialFactory *houseFactory = new HouseFactory();
    Buildings *house = houseFactory->createBuilding();
    
    std::cout << highlight << "propertyOwner->moveIntoResidence(house);\n" << reset;
    propertyOwner->moveIntoResidence(house);
    
    std::cout << highlight << "propertyOwner->upgradeResidence(15);\n" << reset;
    propertyOwner->upgradeResidence(15);
    
    delete house;
}

// Demo menu functions
void demoBasicCitizen() {
    while (true) {
        std::cout << "\n\e[1mComponent 1: Basic Citizen Management\e[0m\n";
        std::cout << "1. Create and manage citizens\n";
        std::cout << "2. Demonstrate citizen states\n";
        std::cout << "3. Return to main menu\n";
        std::cout << "Enter your choice: ";

        int choice;
        std::cin >> choice;
        clearInput();

        if (choice == 3) break;

        switch (choice) {
            case 1: createAndManageCitizens(); break;
            case 2: demonstrateCitizenStates(); break;
            default: std::cout << "Invalid choice. Please try again.\n";
        }
        waitForEnter();
    }
}

void demoCitizenDecorators() {
    while (true) {
        std::cout << "\n\e[1mComponent 2: Citizen Type Decorators\e[0m\n";
        std::cout << "1. Demonstrate Employed Citizen\n";
        std::cout << "2. Demonstrate Property Owner\n";
        std::cout << "3. Return to main menu\n";
        std::cout << "Enter your choice: ";

        int choice;
        std::cin >> choice;
        clearInput();

        if (choice == 3) break;

        switch (choice) {
            case 1: demonstrateEmployedCitizen(); break;
            case 2: demonstratePropertyOwner(); break;
            default: std::cout << "Invalid choice. Please try again.\n";
        }
        waitForEnter();
    }
}

void runFullDemo() {
    std::cout << "\n=== Running Full Citizen System Demo ===\n";
    
    std::cout << "\n\e[1m--- Component 1: Basic Citizen Management ---\e[0m\n";
    createAndManageCitizens();
    waitForEnter();
    demonstrateCitizenStates();
    waitForEnter();
    
    std::cout << "\n\e[1m--- Component 2: Citizen Type Decorators ---\e[0m\n";
    demonstrateEmployedCitizen();
    waitForEnter();
    demonstratePropertyOwner();
    waitForEnter();

    std::cout << "\n=== Full Demo Completed ===\n";
}

int main() {
    while (true) {
        std::cout << "\n\e[1mCitizen System Demo\e[0m\n";
        std::cout << "1. Basic Citizen Management\n";
        std::cout << "2. Citizen Type Decorators\n";
        std::cout << "3. Full Demo\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";

        int choice;
        std::cin >> choice;
        clearInput();

        switch (choice) {
            case 1: demoBasicCitizen(); break;
            case 2: demoCitizenDecorators(); break;
            case 3: runFullDemo(); break;
            case 4:
                std::cout << "Demo complete. Goodbye!\n";
                return 0;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}