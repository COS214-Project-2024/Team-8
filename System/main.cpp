/**
 * @file main.cpp
 * @brief Interactive City Builder Simulation
 * @author Design Wits (modified)
 * @date 2024-04-29
 */

#include <iostream>
#include <memory>
#include <vector>
#include <limits>
#include <thread>
#include <chrono>
#include <ctime>
#include <string>

// Government includes
#include "Government.h"
#include "FinanceSector.h"
#include "UtilitiesSector.h"
#include "GeneralSector.h"
#include "FinanceDepartment.h"
#include "Command.h"
#include "Policies.h"
#include "EconomicPolicies.h"
#include "PublicServicesPolicies.h"

// Citizens and Buildings includes
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
#include "Apartment.h"
#include "ApartmentFactory.h"
#include "ShopFactory.h"
#include "Shop.h"
#include "BuildingController.h"
#include "PublicServiceBuilding.h"
#include "MedicalCenter.h"
#include "LandmarkBuilding.h"
#include "Mall.h"

// Transportation includes
#include "TravelManager.h"
#include "Road.h"
#include "Plane.h"
#include "Train.h"
#include "Airport.h"
#include "BestRouteNode.h"
#include "AccesibleRoute.h"
#include "TrainStation.h"
#include "MapIterator.h"

// Console colors
const std::string GREEN = "\033[32m";
const std::string BLUE = "\033[34m";
const std::string YELLOW = "\033[33m";
const std::string RED = "\033[31m";
const std::string RESET = "\033[0m";
const std::string highlight = "\033[3;38;5;45m";

// Global vector for city buildings
std::vector<std::unique_ptr<Buildings>> cityBuildings;

void clearInput() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void waitForEnter() {
    std::cout << "\nPress Enter to continue...";
    clearInput();
    std::cin.get();
}

void displayCitySkyline() {
    std::cout << "\033[35m" << R"(
                                       /\
                                      /  \              __
                     __              /    \            /  \
                    /  \            /      \     __   /    \
           __      /    \     __   /        \   /  \ /      \
     __   /  \    /      \   /  \ /          \ /    \        \
    /  \ /    \  /        \ /    \            \      \        \
   /    \      \/          \      \            \      \        \
  /      \      \           \      \            \      \________\
 /        \      \___________\      \____________\               \
/          \                   \                   \              \
‾‾‾‾|‾‾‾‾‾‾‾‾|‾‾‾‾‾|‾‾‾‾‾‾‾‾‾|‾‾‾‾‾‾|‾‾‾‾‾‾‾‾‾‾|‾‾‾‾‾‾|‾‾‾‾‾‾
    |  []  []  |     | []  []  |     |  []  []   |     |  []  [] 
    |  []  []  |     | []  []  |     |  []  []   |     |  []  []
    |  []  []  |     | []  []  |     |  []  []   |     |  []  []
    |  []  []  |     | []  []  |     |  []  []   |     |  []  []
    |  []  []  |     | []  []  |     |  []  []   |     |  []  []
    |__[]__[]__|     |_[]__[]__|     |__[]__[]___|     |__[]__[]_
       CITY BUILDER SIMULATION - A COS 214 PROJECT - DESIGN WITS (2024)
)" << "\033[0m" << std::endl;
}

void displayStoryIntro() {
    std::cout << GREEN << "\nWelcome to New Horizons City!" << RESET << std::endl;
    std::cout << "The year is 2024, and you've been appointed as the city planner of this growing metropolis.\n";
    std::cout << "Your mission is to transform this modest settlement into a thriving urban center.\n";
    std::cout << "Balance residential needs, commercial growth, and essential public services\n";
    std::cout << "while creating iconic landmarks that will define your city's skyline.\n\n";
    waitForEnter();
}

void handlePublicServiceConstruction() {
    std::cout << BLUE << "\n=== Public Service Construction ===" << RESET << "\n";
    std::cout << "1. Medical Center\n";
    std::cout << "2. Police Station (Coming Soon)\n";
    std::cout << "3. Fire Station (Coming Soon)\n";
    std::cout << "4. School (Coming Soon)\n";
    std::cout << "5. Back\n";

    int choice;
    std::cin >> choice;
    clearInput();

    switch(choice) {
        case 1: {
            std::cout << "Enter Medical Center name: ";
            std::string name;
            std::getline(std::cin, name);
            
            auto* medicalCenter = new MedicalCenter(
                name,           // building name
                1000,          // power requirement
                500,           // water requirement
                10000.0,       // maintenance cost
                200,           // sewage cost
                150,           // waste
                50,            // employment
                0.85           // health coverage
            );
            
            std::cout << GREEN << "\nMedical Center '" << name << "' constructed successfully!" << RESET << "\n";
            std::cout << "Health Coverage: " << (medicalCenter->getHealthCoverage() * 100) << "%\n";
            std::cout << "Jobs Created: " << medicalCenter->getJobsCreated() << "\n";
            
            cityBuildings.push_back(std::unique_ptr<Buildings>(medicalCenter));
            break;
        }
        default:
            std::cout << "Option not available yet.\n";
    }
}

void handleLandmarkConstruction() {
    std::cout << YELLOW << "\n=== Landmark Construction ===" << RESET << "\n";
    std::cout << "1. City Hall (Coming Soon)\n";
    std::cout << "2. Museum (Coming Soon)\n";
    std::cout << "3. Stadium (Coming Soon)\n";
    std::cout << "4. Monument (Coming Soon)\n";
    std::cout << "5. Back\n";

    int choice;
    std::cin >> choice;
    clearInput();

    if (choice != 5) {
        std::cout << "This landmark type will be available in the next update!\n";
    }
}

std::vector<std::unique_ptr<CitizenInterface>> citizens;

void handleCitizenManagement() {
    std::cout << "\n=== Citizen Management ===\n";
    std::cout << "1. Create New Citizen\n";
    std::cout << "2. View Citizens\n";
    std::cout << "3. Assign Jobs\n";
    std::cout << "4. Back to Main Menu\n";

    int choice;
    std::cin >> choice;
    clearInput();

    switch (choice) {
        case 1: {
            std::cout << "Enter citizen name: ";
            std::string name;
            std::getline(std::cin, name);
            
            auto citizen = std::make_unique<Citizen>(name, 50000, 30, 75);
            citizen->displayDetails();
            citizens.push_back(std::move(citizen));
            break;
        }
        case 2: {
            if (citizens.empty()) {
                std::cout << "No citizens registered yet!\n";
            } else {
                std::cout << "\n=== Registered Citizens ===\n";
                for (size_t i = 0; i < citizens.size(); ++i) {
                    std::cout << "\nCitizen #" << (i + 1) << ":\n";
                    citizens[i]->displayDetails();
                }
            }
            break;
        }
        case 3: {
            if (citizens.empty()) {
                std::cout << "No citizens available to assign jobs!\n";
                break;
            }
            if (cityBuildings.empty()) {
                std::cout << "No buildings available for employment!\n";
                break;
            }

            std::cout << "\nSelect a citizen to employ:\n";
            for (size_t i = 0; i < citizens.size(); ++i) {
                std::cout << (i + 1) << ". " << citizens[i]->getName() 
                         << " (Currently " << (citizens[i]->getEmployementStatus() ? "Employed" : "Unemployed") 
                         << ")\n";
            }

            int citizenChoice;
            std::cin >> citizenChoice;
            clearInput();

            if (citizenChoice < 1 || citizenChoice > static_cast<int>(citizens.size())) {
                std::cout << "Invalid citizen selection!\n";
                break;
            }

            std::cout << "\nSelect a building for employment:\n";
            int buildingCount = 0;
            std::vector<size_t> validBuildingIndices;

            for (size_t i = 0; i < cityBuildings.size(); ++i) {
                if (auto commercialBuilding = dynamic_cast<CommercialBuilding*>(cityBuildings[i].get())) {
                    buildingCount++;
                    validBuildingIndices.push_back(i);
                    std::cout << buildingCount << ". " << cityBuildings[i]->getName() << "\n";
                }
                else if (auto publicBuilding = dynamic_cast<PublicServiceBuilding*>(cityBuildings[i].get())) {
                    buildingCount++;
                    validBuildingIndices.push_back(i);
                    std::cout << buildingCount << ". " << cityBuildings[i]->getName() << "\n";
                }
            }

            if (buildingCount == 0) {
                std::cout << "No suitable buildings for employment!\n";
                break;
            }

            int buildingChoice;
            std::cin >> buildingChoice;
            clearInput();

            if (buildingChoice < 1 || buildingChoice > buildingCount) {
                std::cout << "Invalid building selection!\n";
                break;
            }

            // Create employed citizen decorator
            size_t citizenIndex = citizenChoice - 1;
            size_t buildingIndex = validBuildingIndices[buildingChoice - 1];

            auto employedCitizen = std::make_unique<EmployedCitizen>(std::move(citizens[citizenIndex]));
            employedCitizen->getEmployed(cityBuildings[buildingIndex].get());
            
            // Put the decorated citizen back in the vector
            citizens[citizenIndex] = std::move(employedCitizen);
            break;
        }
    }
    waitForEnter();
}

void handleTransportation() {
    std::cout << "\n=== Transportation Management ===\n";
    std::cout << "1. Build Transport Station\n";
    std::cout << "2. Create Route\n";
    std::cout << "3. View Transport Network\n";
    std::cout << "4. Back to Main Menu\n";

    int choice;
    std::cin >> choice;
    clearInput();

    TravelManager* manager = new TravelManager();

    switch (choice) {
        case 1: {
            std::cout << "Select station type:\n";
            std::cout << "1. Train Station\n";
            std::cout << "2. Airport\n";
            std::cout << "3. Bus Stop\n";
            
            int stationType;
            std::cin >> stationType;
            clearInput();
            
            switch(stationType) {
                case 1: {
                    Stops* trainStation = new TrainStation("Central Station", 10.0f);
                    manager->addStops(trainStation);
                    std::cout << "Train station built successfully!\n";
                    break;
                }
                case 2: {
                    Stops* airport = new Airport("City International", 10.0f);
                    manager->addStops(airport);
                    std::cout << "Airport built successfully!\n";
                    break;
                }
                case 3: {
                    Stops* road = new Road("Bus Terminal", 10.0f);
                    manager->addStops(road);
                    std::cout << "Bus stop built successfully!\n";
                    break;
                }
            }
            break;
        }
        case 2: {
            std::cout << "Route creation functionality coming soon!\n";
            break;
        }
        case 3: {
            std::cout << "Transport network view coming soon!\n";
            break;
        }
    }
    delete manager;
    waitForEnter();
}

void handleGovernment() {
    auto financeDept = std::make_unique<FinanceDepartment>();
    std::cout << "=== Government Management ===\n";
    
    financeDept->setResidentialIncomeTaxRate(0.10);
    financeDept->setResidentialPropertyTaxRate(0.012);
    financeDept->setCommercialBusinessTaxRate(0.25);
    financeDept->setCommercialSalesTaxRate(0.08);
    financeDept->setAvailableFunds(40000000.00);

    auto government = std::make_unique<Government>(financeDept.get());

    std::cout << "\nCurrent Tax Rates:\n";
    std::cout << "Income Tax: 10%\n";
    std::cout << "Property Tax: 1.2%\n";
    std::cout << "Business Tax: 25%\n";
    std::cout << "Sales Tax: 8%\n";

    std::cout << "\nCollecting taxes and managing budget...\n";
    
    double propertyTax = government->requestCollectionOfPropertyTax();
    double incomeTax = government->requestCollectionOfIncomeTax();
    double businessTax = government->requestCollectionOfBusinessTax();
    double salesTax = government->requestCollectionOfSalesTax();

    std::cout << "Property Tax Collected: $" << propertyTax << std::endl;
    std::cout << "Income Tax Collected: $" << incomeTax << std::endl;
    std::cout << "Business Tax Collected: $" << businessTax << std::endl;
    std::cout << "Sales Tax Collected: $" << salesTax << std::endl;

    waitForEnter();
}

void displayMenu() {
    std::cout << "\n=== City Builder Menu ===\n";
    std::cout << "1. Build/Manage Buildings\n";
    std::cout << "2. Manage Citizens\n";
    std::cout << "3. Manage Transportation\n";
    std::cout << "4. Government Actions\n";
    std::cout << "5. View City Statistics\n";
    std::cout << "6. Exit Game\n";
}

void displayBuildingMenu() {
    std::cout << "\n=== Building Management ===\n";
    std::cout << "1. Build Residential (House/Apartment)\n";
    std::cout << "2. Build Commercial (Shop/Office/Mall)\n";
    std::cout << BLUE << "3. Build Public Service" << RESET << "\n";
    std::cout << YELLOW << "4. Build Landmark" << RESET << "\n";
    std::cout << "5. View Building Statistics\n";
    std::cout << "6. Back to Main Menu\n";
}

int main() {
    srand(time(0));
    
    displayCitySkyline();
    displayStoryIntro();

    bool running = true;
    while (running) {
        displayMenu();
        std::cout << "\nEnter your choice: ";
        int choice;
        std::cin >> choice;
        clearInput();

        switch (choice) {
            case 1: {  // Building Management
                bool buildingMenu = true;
                while (buildingMenu) {
                    displayBuildingMenu();
                    int buildChoice;
                    std::cin >> buildChoice;
                    clearInput();

                    switch (buildChoice) {
                        case 1: {  // Residential
                            std::cout << "Choose type (1: House, 2: Apartment): ";
                            int type;
                            std::cin >> type;
                            clearInput();
                            
                            if (type == 1) {
                                std::unique_ptr<ResidentialFactory> factory(new HouseFactory());
                                cityBuildings.push_back(std::unique_ptr<Buildings>(factory->createBuilding()));
                                std::cout << "House built successfully!\n";
                            } else {
                                std::unique_ptr<ResidentialFactory> factory(new ApartmentFactory());
                                cityBuildings.push_back(std::unique_ptr<Buildings>(factory->createBuilding()));
                                std::cout << "Apartment built successfully!\n";
                            }
                            break;
                        }
                        case 2: {  // Commercial
                            std::cout << "Choose type (1: Shop, 2: Office, 3: Mall): ";
                            int type;
                            std::cin >> type;
                            clearInput();

                            switch(type) {
                                case 1: {
                                    std::unique_ptr<CommercialFactory> factory(new ShopFactory());
                                    cityBuildings.push_back(std::unique_ptr<Buildings>(factory->createBuilding()));
                                    std::cout << "Shop built successfully!\n";
                                    break;
                                }
                                case 2: {
                                    std::unique_ptr<CommercialFactory> factory(new OfficeFactory());
                                    cityBuildings.push_back(std::unique_ptr<Buildings>(factory->createBuilding()));std::cout << "Office built successfully!\n";
                                    break;
                                }
                              case 3: {
            std::cout << "Enter Mall name: ";
            std::string name;
            std::getline(std::cin, name);
            
            auto* mall = new Mall(
                name,           // building name
                2000,          // power requirement
                1500,          // water requirement
                15000.0,       // maintenance cost
                300,           // sewage cost
                250,           // waste
                100000.0f,     // sales
                25000.0f,      // profit
                100            // employment
            );
            
            std::cout << "\nMall '" << name << "' constructed successfully!\n";
            std::cout << "Jobs Created: " << mall->getJobsCreated() << "\n";
            
            cityBuildings.push_back(std::unique_ptr<Buildings>(mall));
            break;
        }
        default:
            std::cout << "Invalid choice!\n";
    }
                            break;
                        }
                        case 3: {
                            handlePublicServiceConstruction();
                            break;
                        }
                        case 4: {
                            handleLandmarkConstruction();
                            break;
                        }
                        case 5: {
                            std::cout << "\n=== Building Statistics ===\n";
                            std::cout << "Total Buildings: " << cityBuildings.size() << "\n";
                            
                            // Count building types
                            int residential = 0, commercial = 0, publicService = 0, landmarks = 0;
                            for (const auto& building : cityBuildings) {
                                if (dynamic_cast<PublicServiceBuilding*>(building.get()))
                                    publicService++;
                                else if (dynamic_cast<LandmarkBuilding*>(building.get()))
                                    landmarks++;
                                // Add other type counts here when those classes are implemented
                            }
                            
                            std::cout << "Residential Buildings: " << residential << "\n";
                            std::cout << "Commercial Buildings: " << commercial << "\n";
                            std::cout << BLUE << "Public Service Buildings: " << publicService << RESET << "\n";
                            std::cout << YELLOW << "Landmarks: " << landmarks << RESET << "\n";
                            
                            waitForEnter();
                            break;
                        }
                        case 6:
                            buildingMenu = false;
                            break;
                    }
                }
                break;
            }
            case 2:
                handleCitizenManagement();
                break;
            
            case 3:
                handleTransportation();
                break;
            
            case 4:
                handleGovernment();
                break;

            case 5: {
                std::cout << "\n=== City Overview ===\n";
                std::cout << "Total Buildings: " << cityBuildings.size() << "\n";
                waitForEnter();
                break;
            }
            case 6:
                std::cout << "Thank you for playing City Builder!\n";
                running = false;
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}