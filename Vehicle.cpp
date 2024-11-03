#include "Vehicle.h"
/**
 * @file Vehicle.cpp
 * 
 * @brief This file implements the Vehicle class
 */

/**
 * @brief Construct a new Vehicle object
 * 
 * @param capacity the capacity of the vehicle
 * 
 * Sets the capacity of the vehicle to the given capacity
 * Sets the train to not be cargo by default
 * Sets the number of passengers to 1 by default
 * Sets the weight of the cargo to 0 by default because it is not cargo
 */
Vehicle::Vehicle(int capacity) {
	setCapacity(capacity);
	this->isCargo = false;
	this->passengers = 1;
	this->weight = 0;
}

/**
 * @brief Set the number of passengers on the vehicle
 * 
 * @param pass is the number of passengers
 * 
 * Sets the number of passengers on the vehicle
 * Sets the vehicle to not be cargo
 * Don't confuse weight with the weight of the vehicle, this is the weight of the cargo
 */
void Vehicle::setNumPassenger(int pass) {
	this->passengers = pass;
	this->isCargo = false;
	this->weight = 0;
}

/**
 * @brief Set the weight of the cargo on the vehicle
 * 
 * @param weight is the weight of the cargo
 * 
 * Sets the weight of the cargo on the vehicle
 * Sets the vehicle to be a Truck(carries cargo)
 * Sets the number of passengers to 1 by default
 */
void Vehicle::setCargoWeight(float weight) {
	this->weight = weight;
	this->isCargo = true;
	this->passengers = 1;
	this->transportType = "Truck";
}

/**
 * @brief Travels to the stop using the route accessible through the travel manager
 * 
 * @param stop is the stop to travel to
 * @param head is the head of the route
 * @param best is the flag to travel on "R" symbols(best route)
 * 
 * @return float the distance traveled
 */
float Vehicle::travel(Stops* stop, RouteNode* head, bool best) {
	MapIterator* iter = new MapIterator(head);
	float distance = 0;
	if(best){
		//would skip symbols 'T" and 'A' in the route
		while(iter->currentNode() != nullptr && iter->operator*() != stop){
			if(iter->operator*()->getSymbol() == 'T' || iter->operator*()->getSymbol() == 'A'){
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
 * @brief Get the weight of the vehicle
 * 
 * @return float the weight of the vehicle
 */
float Vehicle::getWeight(){
	return this->weight;
}

/**
 * @brief Get the number of passengers on the vehicle
 * 
 * @return int the number of passengers
 */
int Vehicle::getPassengers(){
	return this->passengers;
}

/**
 * @brief Get the type of the vehicle
 * 
 * @return string the type of the vehicle
 */
std::string Vehicle::getType() {
	std::stringstream ss;
	if(this->isCargo) {
		ss << "Cargo";
	}
	else {
		ss << "Passenger";
	}
	ss << " " << this->transportType;
	return ss.str();
}

/**
 * @brief Set the capacity of the vehicle
 * 
 * @param capacity is the capacity of the vehicle
 * 
 * Sets the capacity of the vehicle
 * If the capacity is less than or equal to 18, the vehicle is a car
 * If the capacity is greater than 18, the vehicle is a bus
 */
void Vehicle::setCapacity(int capacity) {
	this->capacity = capacity;
	if(capacity <= 18){
		this->transportType = "Car";
	}
	else this->transportType = "Bus";
}

/**
 * @brief Get the capacity of the vehicle
 * 
 * @return int the capacity of the vehicle
 */
int Vehicle::getCapacity() {
	return this->capacity;
}
