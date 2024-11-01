#include "Train.h"
/**
 * @file Train.cpp
 * 
 * @brief This file implements the Train class
 */

/**
 * @brief Construct a new Train object
 * 
 * @param capacity 
 * 
 * Sets the capacity of the train to the given capacity
 * Sets the train to not be cargo by default
 * Sets the number of passengers to 1 by default
 * Sets the weight of the cargo to 0 by default because it is not cargo
 */
Train::Train(int capacity) {
	this->capacity = capacity;
	this->isCargo = false;
	this->passengers = 1;
	this->weight = 0;
}

/**
 * @brief Set the number of passengers on the train
 * 
 * @param pass is the number of passengers
 * 
 * Sets the number of passengers on the train
 * Sets the train to not be cargo
 * Don't confuse weight with the weight of the train, this is the weight of the cargo
 */
void Train::setNumPassenger(int pass) {
	this->passengers = pass;
	this->isCargo = false;
	this->weight = 0;
	this->transportType = "Passenger Train";
}

/**
 * @brief Set the weight of the cargo on the train
 * 
 * @param weight is the weight of the cargo
 * 
 */
float Train::getWeight(){
	return this->weight;
}

/**
 * @brief Get the number of passengers on the train
 * 
 * @return int the number of passengers
 */
int Train::getPassengers(){
	return this->passengers;
}

/**
 * @brief Set the weight of the cargo on the train
 * 
 * @param weight is the weight of the cargo
 * 
 * Sets the weight of the cargo on the train
 * Sets the train to be cargo
 * Sets the number of passengers to 1 by default
 */
void Train::setCargoWeight(float weight) {
	this->weight = weight;
	this->isCargo = true;
	this->passengers = 1;
	this->transportType = "Cargo Train";
}

/**
 * @brief Travels to the stop using the route accessible through the travel manager
 * 
 * @param stop is the stop to travel to
 * @param head is the head of the route
 * @param best is the flag to travel on "T" symbols(best route)
 * 
 * @return float the distance traveled
 */
float Train::travel(Stops* stop, RouteNode* head, bool best) {
	MapIterator* iter = new MapIterator(head);
	float distance = 0;
	if(best){
		//would skip symbols 'R" and 'A' in the route
		while(iter->currentNode() != nullptr && iter->operator*() != stop){
			if(iter->operator*()->getSymbol() == 'R' || iter->operator*()->getSymbol() == 'A'){
				iter->operator++();
				continue;
			}
			distance += iter->operator*()->getDistance();
			iter->operator++();
		}
	}else{
		while(iter->currentNode() != nullptr && iter->operator*() != stop){
			if(iter->operator*()->getSymbol() == 'A'){
				iter->operator++();
				continue;
			}
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
 * @brief Get the type of the train
 * 
 * @return string the type of the train
 */
std::string Train::getType() {
	return this->transportType;
}

/**
 * @brief Set the capacity of the train
 * 
 * @param capacity is the capacity of the train
 */
void Train::setCapacity(int capacity) {
	this->capacity = capacity;
}

/**
 * @brief Get the capacity of the train
 * 
 * @return int the capacity of the train
 */
int Train::getCapacity() {
	return this->capacity;
}
