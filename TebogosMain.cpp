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

#include "TravelManager.h"
#include "Road.h"
#include "Plane.h"
#include "Train.h"
#include "Airpot.h"
#include "BestRouteNode.h"
#include "AccesibleRoute.h"
#include "TrainStation.h"
#include "MapIterator.h"
#include "UtilityFactory.h"
#include "EnergyFactory.h"
#include "CoalFactory.h"
#include "WindFactory.h"
#include "HydroFactory.h"
#include "NuclearFactory.h"
#include "UtilityPowerPlant.h"
#include "Utility.h"
#include "EnergySource.h"
#include "UtilityFactory.h"
#include "WaterFactory.h"
#include "SewageSystems.h"
#include "WaterSupply.h"
#include "WaterFactory.h"
#include "PowerPlantFactory.h"
#include "WasteFactory.h"
#include "SewageFactory.h"
#include "UtilityManager.h"
#include "Command.h"
#include "StartCommand.h"
#include "StopCommand.h"
#include "UndoCommand.h"

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

void CitizenTransport(){
   std::cout << highlight<<"Citizen Travelling "<<reset << std::endl;

    auto citizen = std::make_unique<Citizen>("John Doe", 50000, 30, 75);
    std::vector<std::unique_ptr<Stops>> stops;

    stops.push_back(std::make_unique<Road>("HighWay", 10.0f));
    stops.push_back(std::make_unique<Airpot>("LAX", 10.0f));
    stops.push_back(std::make_unique<TrainStation>("Union Station", 10.0f));
    stops.push_back(std::make_unique<Road>("N2", 10.0f));
    stops.push_back(std::make_unique<Airpot>("OR Tambo", 10.0f));
    stops.push_back(std::make_unique<TrainStation>("Gauteng Station", 10.0f));
    stops.push_back(std::make_unique<Road>("N1", 10.0f));
    stops.push_back(std::make_unique<Road>("Route 66", 15.0f));
    stops.push_back(std::make_unique<Airpot>("JFK", 20.0f));
    stops.push_back(std::make_unique<TrainStation>("Grand Central", 12.0f));
    stops.push_back(std::make_unique<Road>("M25", 25.0f));
    stops.push_back(std::make_unique<Airpot>("Heathrow", 30.0f));
    stops.push_back(std::make_unique<TrainStation>("King's Cross", 22.0f));
    stops.push_back(std::make_unique<Road>("I-95", 18.0f));
    stops.push_back(std::make_unique<Airpot>("Singapore Changi", 35.0f));
    stops.push_back(std::make_unique<TrainStation>("Shinjuku Station", 28.0f));
    stops.push_back(std::make_unique<Road>("A40", 40.0f));

    for (const auto& stop : stops) {
        citizen->addKnownLocations(stop.get());
    }

    int size = stops.size();
    int random = rand() % size + 1;
    int bestRoute = rand() % 2 + 1;
    if(bestRoute == 1){
        citizen->useTransport(stops[random].get(), 100, true);
    }else{
        citizen->useTransport(stops[random].get(), 100);
    }
}

// Demo menu functions
void demoBasicCitizen() {
    while (true) {
        std::cout << "\n\e[1mComponent 1: Basic Citizen Management\e[0m\n";
        std::cout << "1. Create and manage citizens\n";
        std::cout << "2. Demonstrate citizen states\n";
        std::cout << "3. Run Citizen Transport\n";
        std::cout << "4. Return to main menu\n";
        std::cout << "Enter your choice: ";

        int choice;
        std::cin >> choice;
        clearInput();

        if (choice == 4) break;

        switch (choice) {
            case 1: createAndManageCitizens(); break;
            case 2: demonstrateCitizenStates(); break;
            case 3: CitizenTransport(); break;
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

void undoCommand(UtilityManager* manager) {
    std::cout << "Undoing last command" << std::endl;
    manager->undoCommand();
}

void PauseOperations(UtilityManager* manager) {
    std::cout << "Pausing Utility operations" << std::endl;
    while(true){
        std::cout<< "1. Pause Water\n";
        std::cout<< "2. Pause Electricity\n";
        std::cout<< "3. Pause All\n";
        std::cout<< "4. Return to utility menu\n";
        std::cout<<" Enter your choice: ";

        int choice;
        std::cin >> choice;
        clearInput();
        switch (choice)
        {   
            case 1: manager->UnfilledDam(); break;
            case 2: manager->LoadShedding(); break;
            case 3: manager->UnfilledDam(); manager->LoadShedding(); break;
            case 4: return;
            default: std::cout << "Invalid choice. Please try again.\n";
        }
        waitForEnter();
    }
}

void ExecuteOperations(UtilityManager* manager) {
    while(true){
        std::cout<< "1. Execute Sewage\n";
        std::cout<< "2. Execute Water\n";
        std::cout<< "3. Execute Electricity\n";
        std::cout<< "4. Execute All\n";
        std::cout<< "5. Return to utility menu\n";
        std::cout<<" Enter your choice: ";

        int choice;
        std::cin >> choice;
        clearInput();
        switch (choice)
        {   
            case 1: manager->executeSewage(); break;
            case 2: manager->executeWater(); break;
            case 3: manager->executeElectricity(); break;
            case 4: manager->executeSewage(); manager->executeWater(); manager->executeElectricity(); break;
            case 5: return;
            default: std::cout << "Invalid choice. Please try again.\n";
        }
        waitForEnter();
    }

}

void repairUtilities(std::vector<Utility*> utilities) {
    for (auto utility : utilities) {
        utility->repairUtility();
        std::cout << utility->getStatus() << std::endl;
    }
}

void useUtilities() {
    UtilityFactory *plantfactory = new PowerPlantFactory();
    UtilityFactory *waterfactory = new WaterFactory();
    UtilityFactory *wastefactory = new WasteFactory();
    UtilityFactory *sewagefactory = new SewageFactory();

    Utility* plant = plantfactory->createUtility(1200);
    Utility* water = waterfactory->createUtility(1300);
    Utility* waste = wastefactory->createUtility(300);
    Utility* sewage = sewagefactory->createUtility(500);

    std::vector<Utility*> utilities = {plant, water, waste, sewage};

    UtilityManager *manager = new UtilityManager();
    int size = utilities.size();
    std::vector<Command*> commands;
    for(int i = 0; i < size; i++){
        Command* start = new StartCommand(utilities[i]);
        commands.push_back(start);
        manager->addCommand(start);
    }

    for(int i = 0; i < size; i++){
        Command* stop = new StopCommand(utilities[i]);
        commands.push_back(stop);
        manager->addCommand(stop);
    }

    for(int i = 0; i < size; i++){
        Command* undo = new UndoCommand(utilities[i]);
        commands.push_back(undo);
        manager->addCommand(undo);
    }

    bool ran = false;
    while(true){
        std::cout << "\n\e[1mUse Utilities\e[0m\n";
        std::cout << "1. Execute Utility operations\n";
        std::cout << "2. Repair Utilities\n";
        if(ran){
            std::cout << "3. Undo last operation\n";
        }
        std::cout << "4. Pause Utility operations\n";
        std::cout << "5. Return to main menu\n";
        std::cout << "Enter your choice: ";

        int choice;
        std::cin >> choice;
        clearInput();

        if(choice == 3 && !ran){
            std::cout << "No operations have been executed yet. Please try again.\n";
            continue;
        }
        
        if (choice == 5) break;

        switch(choice){
            case 1: ExecuteOperations(manager); break;
            case 2: repairUtilities(utilities); break;
            case 3: undoCommand(manager); break;
            case 4: PauseOperations(manager); break;
            case 5: return;
            default: std::cout << "Invalid choice. Please try again.\n";
        }
        ran = true;
        waitForEnter();
    }

    delete plant;
    delete water;
    delete waste;
    delete sewage;

    delete plantfactory;
    delete waterfactory;
    delete wastefactory;
    delete sewagefactory;

    int commandSize = commands.size();
    for(int i = 0; i < commandSize; i++){
        delete commands[i];
    }

    delete manager;
}

void runFullDemo() {
    std::cout << "\n=== Running Full Citizen System Demo ===\n";
    
    std::cout << "\n\e[1m--- Component 1: Basic Citizen Management ---\e[0m\n";
    createAndManageCitizens();
    waitForEnter();
    demonstrateCitizenStates();
    waitForEnter();
    CitizenTransport();
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
        std::cout << "3. Use Utilities\n";
        std::cout << "4. Full Demo\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice: ";

        int choice;
        std::cin >> choice;
        clearInput();

        switch (choice) {
            case 1: demoBasicCitizen(); break;
            case 2: demoCitizenDecorators(); break;
            case 3: useUtilities(); break;
            case 4: runFullDemo(); break; 
            case 5:
                std::cout << "Demo complete. Goodbye!\n";
                return 0;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}