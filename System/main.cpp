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
#include <map>

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
#include "School.h"
#include "PoliceStation.h"
#include "LandmarkBuilding.h"
#include "Mall.h"
#include "Monument.h"
#include "Park.h"
#include "CulturalCenter.h"

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

// States
#include "State.h"
#include "UnderConstruction.h"
#include "Operational.h"
#include "Damaged.h"

// Console colors
const std::string GREEN = "\033[32m";
const std::string BLUE = "\033[34m";
const std::string YELLOW = "\033[33m";
const std::string RED = "\033[31m";
const std::string RESET = "\033[0m";
const std::string highlight = "\033[3;38;5;45m";

// Resource tracking struct
struct ResourceConsumption {
    int powerUsage = 0;
    int waterUsage = 0;
    int wasteProduction = 0;
    int sewageProduction = 0;
    double maintenanceCost = 0.0;
};

// Global vectors and maps
std::vector<std::unique_ptr<Buildings>> cityBuildings;
std::vector<std::unique_ptr<CitizenInterface>> citizens;
std::map<Buildings*, std::vector<CitizenInterface*>> buildingOccupants;
std::map<Buildings*, int> buildingCapacity;
std::map<Buildings*, ResourceConsumption> buildingResources;

// Building states
enum class BuildingState {
    UnderConstruction,
    Operational,
    Damaged
};void clearInput() {
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
    std::cout << GREEN << "\nWelcome to Design Wits Dystopia!" << RESET << std::endl;
    std::cout << "Long ago, the city prospered when all four sectors lived in harmony:\n";
    std::cout << "Residential, Commercial, Public Services, and Infrastructure.\n";
    std::cout << "But everything changed when resources grew scarce.\n";
    std::cout << "Only the City Planner, master of all four elements, could restore balance,\n";
    std::cout << "and now, that responsibility falls to you.\n\n";
    waitForEnter();
}

void updateBuildingResources(Buildings* building) {
    ResourceConsumption consumption;
    consumption.powerUsage = building->getPowerReq();
    consumption.waterUsage = building->getWaterReq();
    consumption.wasteProduction = building->getWasteCost();
    consumption.sewageProduction = building->getSewageCost();
    consumption.maintenanceCost = building->getMaintenanceCost();
    
    buildingResources[building] = consumption;
}

void handleBuildingState(Buildings* building, BuildingState newState) {
    State* state = nullptr;
    switch(newState) {
        case BuildingState::UnderConstruction:
            state = new UnderConstruction();
            break;
        case BuildingState::Operational:
            state = new Operational();
            break;
        case BuildingState::Damaged:
            state = new Damaged();
            break;
    }
    
    if (state) {
        building->setState(state);
        building->requestState();
        
        if (buildingOccupants.find(building) != buildingOccupants.end()) {
            float satisfactionChange = 0.0f;
            switch(newState) {
                case BuildingState::UnderConstruction:
                    satisfactionChange = -5.0f;
                    break;
                case BuildingState::Operational:
                    satisfactionChange = 5.0f;
                    break;
                case BuildingState::Damaged:
                    satisfactionChange = -10.0f;
                    break;
            }
            
            for (auto citizen : buildingOccupants[building]) {
                citizen->adjustCitizenSatisfaction(satisfactionChange);
            }
        }
    }
}void manageBuildingCapacity(Buildings* building) {
    int maxCapacity = 0;
    if (auto residential = dynamic_cast<ResidentialBuilding*>(building)) {
        maxCapacity = 100; // Default capacity for residential buildings
    } else if (auto commercial = dynamic_cast<CommercialBuilding*>(building)) {
        maxCapacity = commercial->getJobsCreated();
    } else if (auto publicService = dynamic_cast<PublicServiceBuilding*>(building)) {
        maxCapacity = publicService->getJobsCreated();
    }
    buildingCapacity[building] = maxCapacity;
}

bool canAddOccupant(Buildings* building) {
    if (buildingOccupants.find(building) == buildingOccupants.end()) {
        buildingOccupants[building] = std::vector<CitizenInterface*>();
        return true;
    }
    return buildingOccupants[building].size() < static_cast<size_t>(buildingCapacity[building]);
}

void addOccupant(Buildings* building, CitizenInterface* citizen) {
    if (canAddOccupant(building)) {
        buildingOccupants[building].push_back(citizen);
    }
}

void handleBuildingConstruction(Buildings* building) {
    handleBuildingState(building, BuildingState::UnderConstruction);
    updateBuildingResources(building);
    manageBuildingCapacity(building);
    std::this_thread::sleep_for(std::chrono::seconds(2));
    handleBuildingState(building, BuildingState::Operational);
}void handlePublicServiceConstruction() {
    std::cout << "\n=== Public Service Construction ===" << "\n";
    std::cout << "1. Medical Center\n";
    std::cout << "2. School\n";
    std::cout << "3. Police Station\n";
    std::cout << "4. Back\n";

    int choice;
    std::cin >> choice;
    clearInput();

    switch(choice) {
        case 1: {
            std::cout << "Enter Medical Center name: ";
            std::string name;
            std::getline(std::cin, name);
            
            auto* medicalCenter = new MedicalCenter(
                name, 1000, 500, 10000.0, 200, 150, 50, 0.85
            );
            
            handleBuildingConstruction(medicalCenter);
            std::cout << "\nMedical Center '" << name << "' constructed successfully!\n";
            std::cout << "Health Coverage: " << (medicalCenter->getHealthCoverage() * 100) << "%\n";
            std::cout << "Jobs Created: " << medicalCenter->getJobsCreated() << "\n";
            
            cityBuildings.push_back(std::unique_ptr<Buildings>(medicalCenter));
            break;
        }
        case 2: {
            std::cout << "Enter School name: ";
            std::string name;
            std::getline(std::cin, name);
            
            auto* school = new School(
                name, 800, 400, 8000.0, 150, 100, 40, 0.90
            );
            
            handleBuildingConstruction(school);
            std::cout << "\nSchool '" << name << "' constructed successfully!\n";
            std::cout << "Education Coverage: " << (school->getEducationalCoverage() * 100) << "%\n";
            std::cout << "Jobs Created: " << school->getJobsCreated() << "\n";
            
            cityBuildings.push_back(std::unique_ptr<Buildings>(school));
            break;
        }
        case 3: {
            std::cout << "Enter Police Station name: ";
            std::string name;
            std::getline(std::cin, name);
            
            auto* policeStation = new PoliceStation(
                name, 900, 300, 9000.0, 200, 120, 30, 0.85
            );
            
            handleBuildingConstruction(policeStation);
            std::cout << "\nPolice Station '" << name << "' constructed successfully!\n";
            std::cout << "Security Coverage: " << (policeStation->getSecurityCoverage() * 100) << "%\n";
            std::cout << "Jobs Created: " << policeStation->getJobsCreated() << "\n";
            
            cityBuildings.push_back(std::unique_ptr<Buildings>(policeStation));
            break;
        }
    }
}void handleLandmarkConstruction() {
    std::cout << "\n=== Landmark Construction ===" << "\n";
    std::cout << "1. Monument\n";
    std::cout << "2. Park\n";
    std::cout << "3. Cultural Center\n";
    std::cout << "4. Back\n";

    int choice;
    std::cin >> choice;
    clearInput();

    switch(choice) {
        case 1: {
            std::cout << "Enter Monument name: ";
            std::string name;
            std::getline(std::cin, name);
            
            auto* monument = new Monument(name, 500, 200, 5000.0, 100, 50);
            handleBuildingConstruction(monument);
            std::cout << "\nMonument '" << name << "' constructed successfully!\n";
            
            cityBuildings.push_back(std::unique_ptr<Buildings>(monument));
            break;
        }
        case 2: {
            std::cout << "Enter Park name: ";
            std::string name;
            std::getline(std::cin, name);
            
            auto* park = new Park(name, 300, 1000, 3000.0, 150, 80);
            handleBuildingConstruction(park);
            std::cout << "\nPark '" << name << "' constructed successfully!\n";
            
            cityBuildings.push_back(std::unique_ptr<Buildings>(park));
            break;
        }
        case 3: {
            std::cout << "Enter Cultural Center name: ";
            std::string name;
            std::getline(std::cin, name);
            
            auto* culturalCenter = new CulturalCenter(name, 800, 600, 7000.0, 250, 150);
            handleBuildingConstruction(culturalCenter);
            std::cout << "\nCultural Center '" << name << "' constructed successfully!\n";
            
            cityBuildings.push_back(std::unique_ptr<Buildings>(culturalCenter));
            break;
        }
    }
}void handleCitizenManagement() {
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
            citizens.push_back(std::move(citizen));
            citizens.back()->displayDetails();
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
                if (auto* building = cityBuildings[i].get()) {
                    if (canAddOccupant(building)) {
                        buildingCount++;
                        validBuildingIndices.push_back(i);
                        std::cout << buildingCount << ". " << building->getName() << "\n";
                    }
                }
            }

            if (buildingCount == 0) {
                std::cout << "No buildings available for employment!\n";
                break;
            }

            int buildingChoice;
            std::cin >> buildingChoice;
            clearInput();

            if (buildingChoice < 1 || buildingChoice > buildingCount) {
                std::cout << "Invalid building selection!\n";
                break;
            }

            size_t citizenIndex = citizenChoice - 1;
            size_t buildingIndex = validBuildingIndices[buildingChoice - 1];

            auto employedCitizen = std::make_unique<EmployedCitizen>(std::move(citizens[citizenIndex]));
            employedCitizen->getEmployed(cityBuildings[buildingIndex].get());
            
            addOccupant(cityBuildings[buildingIndex].get(), employedCitizen.get());
            citizens[citizenIndex] = std::move(employedCitizen);
            break;
        }
    }
    waitForEnter();
}

void handleGovernment() {
    auto financeDept = std::make_unique<FinanceDepartment>();
    std::cout << "=== Government Management ===\n";
    std::cout << "1. Manage Tax Rates\n";
    std::cout << "2. Collect Taxes\n";
    std::cout << "3. Manage Policies\n";
    std::cout << "4. Allocate Funds\n";
    std::cout << "5. Back\n";

    int choice;
    std::cin >> choice;
    clearInput();

    auto government = std::make_unique<Government>(financeDept.get());

    switch(choice) {
        case 1: {
            financeDept->setResidentialIncomeTaxRate(0.10);
            financeDept->setResidentialPropertyTaxRate(0.012);
            financeDept->setCommercialBusinessTaxRate(0.25);
            financeDept->setCommercialSalesTaxRate(0.08);
            std::cout << "\nTax rates updated successfully!\n";
            break;
        }
        case 2: {
            for (const auto& citizen : citizens) {
                government->attach(citizen.get());
            }
            
            std::cout << "\nCollecting taxes...\n";
            double propertyTax = government->requestCollectionOfPropertyTax();
            double incomeTax = government->requestCollectionOfIncomeTax();
            double businessTax = government->requestCollectionOfBusinessTax();
            double salesTax = government->requestCollectionOfSalesTax();

            std::cout << "Property Tax Collected: $" << propertyTax << "\n";
            std::cout << "Income Tax Collected: $" << incomeTax << "\n";
            std::cout << "Business Tax Collected: $" << businessTax << "\n";
            std::cout << "Sales Tax Collected: $" << salesTax << "\n";
            break;
        }
        case 3: {
            std::cout << "\nSelect Policy to Implement:\n";
            std::cout << "1. Economic Policy\n";
            std::cout << "2. Public Services Policy\n";
            
            int policyChoice;
            std::cin >> policyChoice;
            clearInput();

            if (policyChoice == 1) {
                auto policy = std::make_unique<EconomicPolicies>(government.get());
                government->addCommand(std::move(policy));
            } else if (policyChoice == 2) {
                auto policy = std::make_unique<PublicServicesPolicies>(government.get());
                government->addCommand(std::move(policy));
            }
            
            government->executeCommands();
            break;
        }
        case 4: {
            double utilitiesFunds = government->requestAllocationOfUtilitiesFunds();
            double transportFunds = government->requestAllocationOfTransportFunds();
            double educationFunds = government->requestAllocationOfEducationFunds();
            double recreationFunds = government->requestAllocationOfRecreationFunds();

            std::cout << "\nFunds Allocated:\n";
            std::cout << "Utilities: $" << utilitiesFunds << "\n";
            std::cout << "Transport: $" << transportFunds << "\n";
            std::cout << "Education: $" << educationFunds << "\n";
            std::cout << "Recreation: $" << recreationFunds << "\n";
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
                    for (const auto& citizen : citizens) {
                        citizen->addKnownLocations(trainStation);
                    }
                    break;
                }case 2: {
                    Stops* airport = new Airport("City International", 10.0f);
                    manager->addStops(airport);
                    std::cout << "Airport built successfully!\n";
                    for (const auto& citizen : citizens) {
                        citizen->addKnownLocations(airport);
                    }
                    break;
                }
                case 3: {
                    Stops* road = new Road("Bus Terminal", 10.0f);
                    manager->addStops(road);
                    std::cout << "Bus stop built successfully!\n";
                    for (const auto& citizen : citizens) {
                        citizen->addKnownLocations(road);
                    }
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
    std::cout << "3. Build Public Service\n";
    std::cout << "4. Build Landmark\n";
    std::cout << "5. View Building Statistics\n";
    std::cout << "6. Back to Main Menu\n";
}int main() {
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
                                auto* building = factory->createBuilding();
                                handleBuildingConstruction(building);
                                cityBuildings.push_back(std::unique_ptr<Buildings>(building));
                                std::cout << "House built successfully!\n";
                            } else {
                                std::unique_ptr<ResidentialFactory> factory(new ApartmentFactory());
                                auto* building = factory->createBuilding();
                                handleBuildingConstruction(building);
                                cityBuildings.push_back(std::unique_ptr<Buildings>(building));
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
                                    auto* building = factory->createBuilding();
                                    handleBuildingConstruction(building);
                                    cityBuildings.push_back(std::unique_ptr<Buildings>(building));
                                    std::cout << "Shop built successfully!\n";
                                    break;
                                }
                                case 2: {
                                    std::unique_ptr<CommercialFactory> factory(new OfficeFactory());
                                    auto* building = factory->createBuilding();
                                    handleBuildingConstruction(building);
                                    cityBuildings.push_back(std::unique_ptr<Buildings>(building));
                                    std::cout << "Office built successfully!\n";
                                    break;
                                }
                                case 3: {
                                    std::cout << "Enter Mall name: ";
                                    std::string name;
                                    std::getline(std::cin, name);
                                    
                                    auto* mall = new Mall(
                                        name, 2000, 1500, 15000.0, 300, 250, 
                                        100000.0f, 25000.0f, 100
                                    );
                                    handleBuildingConstruction(mall);
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
                        }case 5: {
                            std::cout << "\n=== Building Statistics ===\n";
                            std::cout << "Total Buildings: " << cityBuildings.size() << "\n";
                            
                            int residential = 0, commercial = 0, publicService = 0, landmarks = 0;
                            for (const auto& building : cityBuildings) {
                                if (dynamic_cast<ResidentialBuilding*>(building.get()))
                                    residential++;
                                else if (dynamic_cast<CommercialBuilding*>(building.get()))
                                    commercial++;
                                else if (dynamic_cast<PublicServiceBuilding*>(building.get()))
                                    publicService++;
                                else if (dynamic_cast<LandmarkBuilding*>(building.get()))
                                    landmarks++;
                            }
                            
                            std::cout << "Residential Buildings: " << residential << "\n";
                            std::cout << "Commercial Buildings: " << commercial << "\n";
                            std::cout << "Public Service Buildings: " << publicService << "\n";
                            std::cout << "Landmarks: " << landmarks << "\n\n";
                            
                            std::cout << "=== Resource Consumption ===\n";
                            int totalPower = 0, totalWater = 0, totalWaste = 0, totalSewage = 0;
                            double totalMaintenance = 0.0;
                            
                            for (const auto& resource_pair : buildingResources) {
                                const auto& resources = resource_pair.second;
                                totalPower += resources.powerUsage;
                                totalWater += resources.waterUsage;
                                totalWaste += resources.wasteProduction;
                                totalSewage += resources.sewageProduction;
                                totalMaintenance += resources.maintenanceCost;
                            }
                            
                            std::cout << "Total Power Usage: " << totalPower << " kWh\n";
                            std::cout << "Total Water Usage: " << totalWater << " liters\n";
                            std::cout << "Total Waste Production: " << totalWaste << " units\n";
                            std::cout << "Total Sewage Production: " << totalSewage << " units\n";
                            std::cout << "Total Maintenance Cost: $" << totalMaintenance << "\n";
                            
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
                std::cout << "Total Citizens: " << citizens.size() << "\n";
                
                int employedCount = 0;
                float totalSatisfaction = 0.0f;
                for (const auto& citizen : citizens) {
                    if (citizen->getEmployementStatus()) employedCount++;
                    totalSatisfaction += citizen->getSatisfaction();
                }
                
                std::cout << "Employed Citizens: " << employedCount << "\n";
                std::cout << "Average Satisfaction: " << (citizens.empty() ? 0 : totalSatisfaction / citizens.size()) << "%\n";
                
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