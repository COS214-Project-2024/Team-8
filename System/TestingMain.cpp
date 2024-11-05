#include <iostream>

#include "TravelManager.h"
#include "Road.h"
#include "Plane.h"
#include "Train.h"
#include "Airport.h"
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

/**
 * @brief This function checks the stop iterator
 */
void checkStopIterator(){
    Stops* stop1 = new Road("HighWay", 10.0f);
    Stops* stop2 = new Airport("LAX", 10.0f);
    Stops* stop3 = new TrainStation("Union Station", 10.0f);
    RouteNode* head = new BestRouteNode();
    head->add(stop1);
    head->add(stop2);
    head->add(stop3);

    std::cout << "MapIterator" << std::endl;
    MapIterator* iter = new MapIterator(head);
    while(iter->currentNode() != nullptr){
        std::cout << "Current Node: " << iter->operator*()->getName() << std::endl;
        iter->operator++();
    }
    delete iter;
    delete head;
    delete stop3;
    delete stop2;
    delete stop1;
}

/**
 * @brief This function tests the TravelManager
 */
void TravelManagerTest(){
    TravelManager* manager = new TravelManager();
    Stops* stop1 = new Road("HighWay", 10.0f);
    Stops* stop2 = new Airport("LAX", 10.0f);
    Stops* stop3 = new TrainStation("Union Station", 10.0f);
    Stops* stop4 = new Road("N2", 10.0f);
    Stops* stop5 = new Airport("OR Tambo", 10.0f);
    Stops* stop6 = new TrainStation("Gauteng Station", 10.0f);

    manager->addStops(stop1);
    manager->addStops(stop2);
    manager->addStops(stop3);
    manager->addStops(stop4);
    manager->addStops(stop5);
    manager->addStops(stop6);
    manager->Travel(140, stop6);

    delete stop6;
    delete stop5;
    delete stop4;
    delete stop3;
    delete stop2;
    delete stop1;
    delete manager;	
}

/**
 * @brief This function checks the best route
 */
void checkBestRoute(){
    TravelManager* manager = new TravelManager();
    Stops* stop1 = new Road("HighWay", 10.0f);
    Stops* stop2 = new Airport("LAX", 10.0f);
    Stops* stop3 = new TrainStation("Union Station", 10.0f);
    Stops* stop4 = new Road("N2", 10.0f);
    Stops* stop5 = new Airport("OR Tambo", 10.0f);
    Stops* stop6 = new TrainStation("Gauteng Station", 10.0f);

    manager->addStops(stop1);
    manager->addStops(stop2);
    manager->addStops(stop3);
    manager->addStops(stop4);
    manager->addStops(stop5);
    manager->addStops(stop6);
    manager->BestRoute(140, stop6);
    delete stop6;
    delete stop5;
    delete stop4;
    delete stop3;
    delete stop2;
    delete stop1;
    delete manager;
}

void TestFactories(){
    UtilityFactory *plantfactory = new PowerPlantFactory();
    UtilityFactory *waterfactory = new WaterFactory();
    UtilityFactory *wastefactory = new WasteFactory();
    UtilityFactory *sewagefactory = new SewageFactory();

    Utility* plant = plantfactory->createUtility(1000);
    Utility* water = waterfactory->createUtility(1000);
    Utility* waste = wastefactory->createUtility(1000);
    Utility* sewage = sewagefactory->createUtility(1000);

    std::cout << "Plant: " << plant->getOutput() << std::endl;
    std::cout << "Water: " << water->getOutput() << std::endl;
    std::cout << "Waste: " << waste->getOutput() << std::endl;
    std::cout << "Sewage: " << sewage->getOutput() << std::endl;

    delete sewage;
    delete waste;
    delete water;
    delete plant;

    delete sewagefactory;
    delete wastefactory;
    delete waterfactory;
    delete plantfactory;
}

void TestUtilities(){
    UtilityFactory *plantfactory = new PowerPlantFactory();
    UtilityFactory *waterfactory = new WaterFactory();
    UtilityFactory *wastefactory = new WasteFactory();
    UtilityFactory *sewagefactory = new SewageFactory();

    Utility* plant = plantfactory->createUtility(1000);
    Utility* water = waterfactory->createUtility(1000);
    Utility* waste = wastefactory->createUtility(1000);
    Utility* sewage = sewagefactory->createUtility(1000);

    std::cout <<"=======================POWER PLANT TEST========================"<<std::endl;
    std::cout << "Plant: " << plant->getOutput() << std::endl;
    std::cout << "Status: " << plant->getStatus() << std::endl;
    plant->repairUtility();
    std::cout << "Status: " << plant->getStatus() << std::endl;
    plant->pauseOperation();
    std::cout << "Status 3: " << plant->getStatus() << std::endl;
    plant->executeOperation();
    std::cout << "Status 4: " << plant->getStatus() << std::endl;
    plant->undoChange();
    std::cout << "Status 5: " << plant->getStatus() << std::endl;
    plant->switchFuel();
    std::cout << plant->getEnergyType() << std::endl;
    std::cout << "Status: " << plant->getStatus() << std::endl;

    std::cout <<"=======================WATER TEST========================"<<std::endl;
    std::cout << "Water: " << water->getOutput() << std::endl;
    std::cout << "Status: " << water->getStatus() << std::endl;
    water->repairUtility();
    std::cout << "Status: " << water->getStatus() << std::endl;
    water->pauseOperation();
    std::cout << "Status: " << water->getStatus() << std::endl;
    water->executeOperation();
    std::cout << "Status: " << water->getStatus() << std::endl;
    water->undoChange();
    std::cout << "Status: " << water->getStatus() << std::endl;
    water->setOutput(1000);
    std::cout << "Status: " << water->getStatus() << std::endl;
    water->setMaxGallons(1000);
    std::cout << "Status: " << water->getStatus() << std::endl;

    std::cout <<"=======================WASTE TEST========================"<<std::endl;
    std::cout << "Waste: " << waste->getOutput() << std::endl;
    waste->repairUtility();
    std::cout << "Status: " << waste->getStatus() << std::endl;
    waste->pauseOperation();
    std::cout << "Status: " << waste->getStatus() << std::endl;
    waste->executeOperation();
    std::cout << "Status: " << waste->getStatus() << std::endl;
    waste->setProcessCapacity(189);
    std::cout << "Status: " << waste->getStatus() << std::endl;
    waste->undoChange();
    std::cout << "Status: " << waste->getStatus() << std::endl;

    std::cout <<"=======================SEWAGE TEST========================"<<std::endl;
    std::cout << "Sewage: " << sewage->getOutput() << std::endl;
    sewage->repairUtility();
    std::cout << "Status: " << sewage->getStatus() << std::endl;
    sewage->pauseOperation();
    std::cout << "Status: " << sewage->getStatus() << std::endl;
    sewage->executeOperation();
    std::cout << "Status: " << sewage->getStatus() << std::endl;
    sewage->setmaxWaste(1000);
    std::cout << "Status: " << sewage->getStatus() << std::endl;
    
    delete sewage;
    delete waste;
    delete water;
    delete plant;

    delete sewagefactory;
    delete wastefactory;
    delete waterfactory;
    delete plantfactory;
}

void TestCommands(){
    UtilityFactory *plantfactory = new PowerPlantFactory();
    UtilityFactory *waterfactory = new WaterFactory();
    UtilityFactory *wastefactory = new WasteFactory();
    UtilityFactory *sewagefactory = new SewageFactory();

    Utility* plant = plantfactory->createUtility(1000);
    Utility* water = waterfactory->createUtility(1000);
    Utility* waste = wastefactory->createUtility(1000);
    Utility* sewage = sewagefactory->createUtility(1000);

    UtilityManager* manager = new UtilityManager();
    Command* start = new StartCommand(plant);
    Command* stop = new StopCommand(plant);
    Command* undo = new UndoCommand(plant);
    Command* start2 = new StartCommand(water);
    Command* stop2 = new StopCommand(water);
    Command* undo2 = new UndoCommand(water);
    Command* start3 = new StartCommand(waste);
    Command* stop3 = new StopCommand(waste);
    Command* undo3 = new UndoCommand(waste);
    Command* start4 = new StartCommand(sewage);
    Command* stop4 = new StopCommand(sewage);
    Command* undo4 = new UndoCommand(sewage);

    manager->addCommand(start);
    manager->addCommand(stop);
    manager->addCommand(undo);
    manager->addCommand(start2);
    manager->addCommand(stop2);
    manager->addCommand(undo2);
    manager->addCommand(start3);
    manager->addCommand(stop3);
    manager->addCommand(undo3);
    manager->addCommand(start4);
    manager->addCommand(stop4);
    manager->addCommand(undo4);

    manager->executeElectricity();
    manager->executeWater();
    manager->executeWaste();
    manager->executeSewage();
    manager->LoadShedding();
    manager->UnfilledDam();
    manager->undoCommand();

    delete sewage;
    delete waste;
    delete water;
    delete plant;

    delete sewagefactory;
    delete wastefactory;
    delete waterfactory;
    delete plantfactory;
    delete manager;
    delete start;
    delete stop;
    delete undo;
    delete start2;
    delete stop2;
    delete undo2;
    delete start3;
    delete stop3;
    delete undo3;
    delete start4;
    delete stop4;
    delete undo4;
}

int main() {
    srand(time(0)); //random function used in TravelManager
    TravelManagerTest();
    checkStopIterator();
    checkBestRoute();

    TestFactories();
    TestUtilities();
    TestCommands();
}
