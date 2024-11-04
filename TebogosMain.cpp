/**
 * @file cityBuilderMain.cpp
 * @brief Main demonstration file for City Builder Simulation system
 * @author Combined Design
 * @date 2024-04-29
 */

#include <iostream>
#include <memory>
#include <vector>
#include <limits>
#include <thread>
#include <chrono>
#include <ctime>

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

// Transportation includes
#include "TravelManager.h"
#include "Road.h"
#include "Plane.h"
#include "Train.h"
#include "Airpot.h"
#include "BestRouteNode.h"
#include "AccesibleRoute.h"
#include "TrainStation.h"
#include "MapIterator.h"

const std::string highlight = "\033[3;38;5;45m";
const std::string reset = "\033[0m";

void clearInput()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void waitForEnter()
{
    std::cout << "\nPress Enter to continue...";
    clearInput();
    std::cin.get();
}

void simulationPause(const std::string &message = "")
{
    if (!message.empty())
    {
        std::cout << "\n"
                  << highlight << message << reset << std::endl;
    }
    std::this_thread::sleep_for(std::chrono::seconds(2));
}

void demonstrateGovernment()
{
    std::cout << highlight << "Setting up Government Component...\n"
              << reset;

    // Create components in correct order
    auto financeDepartment = new FinanceDepartment();

    // Create and link sectors
    auto generalSector = new GeneralSector(financeDepartment);
    auto utilitiesSector = new UtilitiesSector(financeDepartment);
    auto financeSector = new FinanceSector(financeDepartment);

    // Set up chain of responsibility
    generalSector->setSuccessor(financeSector);
    financeSector->setSuccessor(utilitiesSector);

    // Create policies using the base handler (generalSector)
    auto econPolicies = new EconomicPolicies(generalSector);
    auto psPolicies = new PublicServicesPolicies(generalSector);

    try
    {
        std::cout << highlight << "Processing Government Requests...\n"
                  << reset;
        generalSector->handleRequest("FINANCE: Budget review needed");
        generalSector->handleRequest("UTILITIES: Power maintenance required");
        generalSector->handleRequest("General inquiry about services");

        std::cout << highlight << "Implementing Government Policies...\n"
                  << reset;
        econPolicies->execute();
        psPolicies->execute();
    }
    catch (const std::exception &e)
    {
        std::cout << "Error during government operations: " << e.what() << std::endl;
    }

    // Clean up in reverse order of creation
    delete psPolicies;
    delete econPolicies;
    delete utilitiesSector;
    delete financeSector;
    delete generalSector;
    delete financeDepartment;

    waitForEnter();
}

void demonstrateCitizens()
{
    std::cout << highlight << "Creating and Managing Citizens...\n"
              << reset;
    auto citizen = std::make_unique<Citizen>("John Doe", 50000, 30, 75);
    citizen->displayDetails();
    citizen->adjustCitizenSatisfaction(10);

    auto employedCitizen = std::make_unique<Citizen>("Jane Smith", 60000, 35, 80);
    employedCitizen->setEmploymentStatus(true);
    employedCitizen->setPropertyOwnership(true);
    employedCitizen->displayDetails();

    CommercialFactory *officeFactory = new OfficeFactory();
    Buildings *office = officeFactory->createBuilding();

    auto worker = std::make_unique<EmployedCitizen>(std::make_unique<Citizen>("Bob Wilson", 45000, 28, 70));
    worker->getEmployed(office);
    worker->jobPromotion(10);

    delete office;
    delete officeFactory;
    waitForEnter();
}

void demonstrateBuildings()
{
    BuildingController controller;
    std::cout << highlight << "Creating City Buildings...\n"
              << reset;

    ResidentialFactory *houseFactory = new HouseFactory();
    Buildings *house = houseFactory->createBuilding();
    controller.addBuilding(house);

    ResidentialFactory *apartmentFactory = new ApartmentFactory();
    Buildings *apartment = apartmentFactory->createBuilding();
    controller.addBuilding(apartment);

    CommercialFactory *officeFactory = new OfficeFactory();
    Buildings *office = officeFactory->createBuilding();
    controller.addBuilding(office);

    CommercialFactory *shopFactory = new ShopFactory();
    Buildings *shop = shopFactory->createBuilding();
    controller.addBuilding(shop);

    std::cout << "\n=== Building Statistics ===\n";
    std::cout << "Total Buildings: " << controller.getAmountOfBuildings() << "\n";
    std::cout << "Power Required: " << controller.getTotalPowerReq() << " kWh per month\n";
    std::cout << "Water Required: " << controller.getTotalWaterReq() << " Liters per day\n";
    std::cout << "Sewage Produced: " << controller.getTotalSewageReq() << " Liters per day\n";
    std::cout << "Waste Generated: " << controller.getTotalWasteReq() << " kg per week\n";
    std::cout << "Total Maintenance Cost: $" << controller.getMaintenanceCost() << " per month\n";
    std::cout << "Total Commercial Income: $" << controller.getCommercialIncome() << " per month\n";

    delete shopFactory;
    delete officeFactory;
    delete apartmentFactory;
    delete houseFactory;
    waitForEnter();
}

void demonstrateTransportation()
{
    std::cout << highlight << "Setting up Transportation Network...\n"
              << reset;
    TravelManager *manager = new TravelManager();

    Stops *highway = new Road("Highway-101", 10.0f);
    Stops *airport = new Airpot("City International", 10.0f);
    Stops *trainStation = new TrainStation("Central Station", 10.0f);
    Stops *suburb = new Road("Suburban Route", 10.0f);

    manager->addStops(highway);
    manager->addStops(airport);
    manager->addStops(trainStation);
    manager->addStops(suburb);

    std::cout << highlight << "Testing Transportation Routes...\n"
              << reset;
    manager->Travel(140, trainStation);
    manager->BestRoute(140, trainStation);

    RouteNode *head = new BestRouteNode();
    head->add(highway);
    head->add(airport);
    head->add(trainStation);

    MapIterator *iter = new MapIterator(head);
    while (iter->currentNode() != nullptr)
    {
        std::cout << "Transport Node: " << iter->operator*()->getName() << std::endl;
        iter->operator++();
    }

    delete iter;
    delete head;
    delete suburb;
    delete trainStation;
    delete airport;
    delete highway;
    delete manager;
    waitForEnter();
}

void runFullSimulation()
{
    std::cout << "\n=== Running Full City Simulation ===\n";
    simulationPause("Starting Government Component...");
    demonstrateGovernment();

    simulationPause("Starting Citizens Component...");
    demonstrateCitizens();

    simulationPause("Starting Buildings Component...");
    demonstrateBuildings();

    simulationPause("Starting Transportation Component...");
    demonstrateTransportation();

    std::cout << "\n=== Full City Simulation Complete ===\n";
    waitForEnter();
}
void testGovernment()
{
    FinanceDepartment *financeDept = new FinanceDepartment();
    std::cout << "It is the 25th day of the month 😊 Finance Department is about to do its monthly duties..." << std::endl;
    std::cout << "Finance Department setting Income ,Property , Business and Sales tax rates  "<< std::endl;
    financeDept->setResidentialIncomeTaxRate(0.10);
    financeDept->setResidentialPropertyTaxRate(0.012);
    financeDept->setCommercialBusinessTaxRate(0.25);
    financeDept->setCommercialSalesTaxRate(0.08);
    financeDept->setAvailableFunds(40000000.00);
    Government *government = new Government(financeDept);
    for (int i = 0; i < 10; ++i)
    {
        CitizenInterface *citizen = new Citizen();
        government->attach(citizen);
    }
    // Set the government budget
    government->setBudget(40000000.00);

    // Simulate tax collection and fund allocation
    double propertyTaxCollected = government->requestCollectionOfPropertyTax();
    double incomeTaxCollected = government->requestCollectionOfIncomeTax();
    double businessTaxCollected = government->requestCollectionOfBusinessTax();
    double salesTaxCollected = government->requestCollectionOfSalesTax();

    std::cout << "😊 Government is now requesting Finance Department to collect Income ,Property , Business and Sales taxes  "<< std::endl;
    std::cout << "🏡 Property Tax Collected: R" << propertyTaxCollected << std::endl;
    std::cout << "💰 Income Tax Collected: R" << incomeTaxCollected << std::endl;
    std::cout << "🏢 Business Tax Collected: R" << businessTaxCollected << std::endl;
    std::cout << "🛍️ Sales Tax Collected: R" << salesTaxCollected << std::endl;


    // Allocate funds and test all allocations
    /*double utilitiesFunds = government->requestAllocationOfUtilitiesFunds();
    std::cout << "Allocated Utilities Funds: R" << utilitiesFunds << std::endl;

    double publicServiceBuildingsFunds = government->requestAllocationOfPublicServiceBuildingsFunds();
    std::cout << "Allocated Public Service Buildings Funds: R" << publicServiceBuildingsFunds << std::endl;

    double transportInfrastructureFunds = government->requestAllocationOfTransportFunds();
    std::cout << "Allocated Transport Infrastructure Funds: R" << transportInfrastructureFunds << std::endl;

    double educationFunds = government->requestAllocationOfEducationFunds();
    std::cout << "Allocated Education Funds: R" << educationFunds << std::endl;

    double recreationFunds = government->requestAllocationOfRecreationFunds();
    std::cout << "Allocated Recreation Funds: R" << recreationFunds << std::endl;*/
    std::cout << "😊 Government is now requesting Finance Department to allocate funds for Utilities, Public Service Buildings , Transport Infrastructure , Education Buildings and Recreation Buildings "<< std::endl;
    std::cout << government->requestAllocationOfUtilitiesFunds()<< std::endl;
    std::cout << government->requestAllocationOfPublicServiceBuildingsFunds() << std::endl;
    std::cout << government->requestAllocationOfTransportFunds() << std::endl;
    std::cout << government->requestAllocationOfEducationFunds() << std::endl;
    std::cout << government->requestAllocationOfRecreationFunds()  << std::endl;

}
int main()
{
    srand(time(0));

    std::cout << "\033[35m" << " _____ _ _         ____        _ _     _\n"
                               "|     |_| |_ _ ___|    \\ ___ _|_| |___| |___ ___\n"
                               "|   --| |  _| | | |  |  | . | | | | -_| |  _| -_|\n"
                               "|_____|_|_| |_____|____/|___|_|_|_|___|_|_| |___|\n"
                               "\033[0m"
              << std::endl;

    while (true)
    {
        std::cout << "\n\e[1mCity Builder Simulation\e[0m\n";
        std::cout << "1. Government Management\n";
        std::cout << "2. Citizens Management\n";
        std::cout << "3. Building Management\n";
        std::cout << "4. Transportation Management\n";
        std::cout << "5. Taxation and Budget Allocation Management\n";
        std::cout << "6. Run Full City Simulation\n";
        std::cout << "7. Exit\n";
        std::cout << "Enter your choice: ";

        int choice;
        std::cin >> choice;
        clearInput();

        switch (choice)
        {
        case 1:
            demonstrateGovernment();
            break;
        case 2:
            demonstrateCitizens();
            break;
        case 3:
            demonstrateBuildings();
            break;
        case 4:
            demonstrateTransportation();
            break;
        case 5:
            testGovernment();
            break;
        case 6:
            runFullSimulation();
            break;
        case 7:
            std::cout << "Exiting City Builder Simulation. Goodbye!\n";
            return 0;
        default:
            std::cout << "Invalid choice. Please try again.\n";
        }
    }
    testGovernment();
    return 0;
}
