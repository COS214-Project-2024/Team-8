#include "Plane.h"

/**
 * @file Plane.cpp
 * 
 * @brief This file implements the Plane class
 */

/**
 * @brief Construct a new Plane:: Plane object
 * 
 * @param capacity is the capacity of the plane
 * 
 * Set the capacity of the plane and set the passengers to 2(co-pilot and pilot)
 * 
 * Don't confuse weight with the weight of the plane, this is the weight of the cargo
 */
Plane::Plane(int capacity) {
	this->capacity = capacity;
	this->isCargo = false;
	this->passengers = 2;
	this->weight = 0;
}

/**
 * @brief Set the Num Passenger object
 * 
 * @param pass is the number of passengers
 * 
 * Sets the number of passengers and sets the plane to passenger plane(disabling cargo type)
 * Don't confuse weight with the weight of the plane, this is the weight of the cargo
 */
void Plane::setNumPassenger(int pass) {
	this->passengers = pass;
	this->isCargo = false;
	this->weight = 0;
	this->transportType = "Passenger Plane";
}

/**
 * @brief Set the Cargo Weight object
 * 
 * @param weight is the weight of the cargo
 * 
 * Sets the weight of the cargo and sets the plane to cargo plane(disabling passenger type)
 */
void Plane::setCargoWeight(float weight) {
	this->weight = weight;
	this->isCargo = true;
	this->passengers = 2;
	this->transportType = "Cargo Plane";
}

/**
 * @brief Travels to the stop using the route accessible through the travel manager
 * 
 * @param stop is the stop to travel to
 * @param head is the head of the route
 * @param best is the flag to skip symbols 'T' in the route
 * 
 * @return float the distance traveled
 */
float Plane::travel(Stops* stop, RouteNode* head, bool best) {
	MapIterator* iter = new MapIterator(head);
	float distance = 0;
	if(best){
		//would skip symbols 'T' in the route
		while(iter->currentNode() != nullptr && iter->operator*() != stop){
			if(iter->operator*()->getSymbol() == 'T'){
				iter->operator++();
				continue;
			}
			distance += iter->operator*()->getDistance();
			iter->operator++();
		}
	}else{
		while(iter->currentNode() != nullptr && iter->operator*() != stop){
			distance += iter->operator*()->getDistance();
			iter->operator++();
		}
	}

	if(iter->currentNode() == nullptr){
		delete iter;
		return 0;
	}
	else{
		distance += iter->headNode()->getDistance();
		std::cout << "Traveling to " << stop->getName() << " by " << this->getType() << std::endl;
		delete iter;
		return distance;
	}
}

/**
 * @brief Get the Type object(Transport type)
 * 
 * @return string the type of the transport
 */
std::string Plane::getType() {
	return this->transportType;
}

/**
 * @brief Set the Capacity object
 * 
 * @param capacity is the capacity of the plane
 * 
 * Sets the capacity of the plane
 */
void Plane::setCapacity(int capacity) {
	this->capacity = capacity;
}

/**
 * @brief Get the Capacity object
 * 
 * @return int the capacity of the plane
 */
int Plane::getCapacity() {
	return this->capacity;
}

/**
 * @brief Get the Passengers object
 * 
 * @return int the number of passengers
 */
int Plane::getPassengers() {
	return this->passengers;
}

/**
 * @brief Get the Weight object
 * 
 * @return float the weight of the cargo
 */
float Plane::getWeight() {
	return this->weight;
}
