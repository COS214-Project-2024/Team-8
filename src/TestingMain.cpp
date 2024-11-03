#include <iostream>
#include <ctime> 

#include "TravelManager.h"
#include "Road.h"
#include "Plane.h"
#include "Train.h"
#include "Airpot.h"
#include "BestRouteNode.h"
#include "AccesibleRoute.h"
#include "TrainStation.h"
#include "MapIterator.h"

/**
 * @brief This function checks the stop iterator
 */
void checkStopIterator(){
    Stops* stop1 = new Road("HighWay", 10.0f);
    Stops* stop2 = new Airpot("LAX", 10.0f);
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
    Stops* stop2 = new Airpot("LAX", 10.0f);
    Stops* stop3 = new TrainStation("Union Station", 10.0f);
    Stops* stop4 = new Road("N2", 10.0f);
    Stops* stop5 = new Airpot("OR Tambo", 10.0f);
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
    Stops* stop2 = new Airpot("LAX", 10.0f);
    Stops* stop3 = new TrainStation("Union Station", 10.0f);
    Stops* stop4 = new Road("N2", 10.0f);
    Stops* stop5 = new Airpot("OR Tambo", 10.0f);
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

int main() {
    std::cout << "\033[35m####### ######     #    #     #  #####  ######  ####### ######  #######" << std::endl;
    std::cout << "   #    #     #   # #   ##    # #     # #     # #     # #     #    #   " << std::endl;
    std::cout << "   #    #     #  #   #  # #   # #       #     # #     # #     #    #   " << std::endl;
    std::cout << "   #    ######  #     # #  #  #  #####  ######  #     # ######     #   " << std::endl;
    std::cout << "   #    #   #   ####### #   # #       # #       #     # #   #      #   " << std::endl;
    std::cout << "   #    #    #  #     # #    ## #     # #       #     # #    #     #   " << std::endl;
    std::cout << "   #    #     # #     # #     #  #####  #       ####### #     #    #   \033[0m" << std::endl;

    srand(time(0)); //random function used in TravelManager
    TravelManagerTest();
    checkStopIterator();
    checkBestRoute();
}
