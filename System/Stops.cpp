#include "Stops.h"

/**
 * @file Stops.cpp
 * 
 * @brief This file implements the Stops getName
 * 
 * The functions should be implemented in the subclasses, this is to allow for polymorphism
 */

/**
 * @brief Get the cost of the stop
 * @pre getCost is not a member of the subclass
 * @throw "NOT A MEMBER OF SAID CLASS"
 */
float Stops::getCost() {
	throw "NOT A MEMBER OF SAID CLASS";
}

/**
 * @brief Get the symbol of the stop
 * @pre symbol has been set by the subclass
 * @throw "NOT A MEMBER OF SAID CLASS"
 */
void Stops::setTicketCost(float cost) {
	throw "NOT A MEMBER OF SAID CLASS";
}

/**
 * @brief Get the distance of the stop
 * @pre getDistance is not a member of the subclass
 * @throw "NOT A MEMBER OF SAID CLASS"
 */
float Stops::getTicketCost() {
	throw "NOT A MEMBER OF SAID CLASS";
}

/**
 * @brief Get the name of the stop
 * @pre name has been set by the subclass
 */
std::string Stops::getName() {
	return this->name;
}

/**
 * @brief Set the speed limit of the stop
 * @pre setSpeedLimit is not a member of the subclass
 * @throw "NOT A MEMBER OF SAID CLASS"
 */
void Stops::setSpeedLimit(int limit) {
	throw "NOT A MEMBER OF SAID CLASS";
}

/**
 * @brief Get the speed limit of the stop
 * @pre getSpeedLimit is not a member of the subclass
 * @throw "NOT A MEMBER OF SAID CLASS"
 */
int Stops::getSpeedLimit() {
	throw "NOT A MEMBER OF SAID CLASS";
}
