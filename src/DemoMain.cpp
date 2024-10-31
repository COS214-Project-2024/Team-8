#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h> //saved in the doctest folder

#include <iostream>
#include <sstream>

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
 * @file DemoMain.cpp
 * @brief Unit Testing for the TravelManager class
 * 
 */

/**
 * @brief This function checks the stop iterator
 * 
 */
TEST_CASE("Testing the MapIterator"){
    Stops* stop1 = new Road("HighWay", 10.0f);
    Stops* stop2 = new Airpot("LAX", 10.0f);
    Stops* stop3 = new TrainStation("Union Station", 10.0f);
    RouteNode* head = new BestRouteNode();
    head->add(stop1);
    head->add(stop2);
    head->add(stop3);
    RouteNode* head2 = head;
    CHECK(head2->getData() == stop1); //check if the getData function works
    CHECK(head2->travel()->getData() == stop2); //check if the travel function works

    std::cout << "MapIterator" << std::endl;
    MapIterator* iter = new MapIterator(head);
    while(iter->currentNode() != nullptr){
        std::cout << "Current Node: " << iter->operator*()->getName() << std::endl;
        CHECK(iter->operator*() == head2->getData()); //check if traversal consistent with chain of nodes
        head2 = head2->travel();
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
 * 
 */
TEST_CASE("Testing Best Route Travel"){
    TravelManager* manager = new TravelManager();
    Stops* stop1 = new Road("HighWay", 10.0f);
    Stops* stop2 = new Airpot("LAX", 10.0f);
    Stops* stop3 = new TrainStation("Union Station", 10.0f);
    Stops* stop4 = new Road("N2", 10.0f);
    Stops* stop5 = new Airpot("OR Tambo", 10.0f);
    Stops* stop6 = new TrainStation("Gauteng Station", 10.0f);
    Stops* stop7 = new Road("N1", 10.0f);

    std::ostringstream oss;
    std::streambuf* p_cout_streambuf = std::cout.rdbuf(); //save old buf
    std::cout.rdbuf(oss.rdbuf()); //redirect std::cout to oss

    manager->addStops(stop1);
    manager->addStops(stop2);
    manager->addStops(stop3);
    manager->addStops(stop4);
    manager->addStops(stop5);
    manager->addStops(stop6);
    manager->BestRoute(140, stop6);
    std::cout.rdbuf(p_cout_streambuf); //reset to standard output
    CHECK(oss.str().find("Travel Summary") != std::string::npos);
    manager->BestRoute(140, stop7);
    std::cout.rdbuf(p_cout_streambuf); //reset to standard output
    CHECK(oss.str().find("No route found\n") == std::string::npos);

    delete stop7;
    delete stop6;
    delete stop5;
    delete stop4;
    delete stop3;
    delete stop2;
    delete stop1;
    delete manager;	

}