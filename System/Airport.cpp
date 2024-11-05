#include "Airport.h"

/**
 * @file Airport.cpp
 * 
 * @brief This is the Airport class implementation file
 * 
 */

/**
 * @brief Construct a new Airport:: Airport object
 * 
 * @param name
 * @param length
 * Creates a new Airport object with the given name and length
 */
Airport::Airport(std::string name, float length) {
	this->name = name;
	this->length = length;
	this->symbol = 'A';
}

/**
 * @brief Get the Symbol object
 * 
 * @return char symbol of the Airport 
 */
char Airport::getSymbol() {
	return this->symbol;
}

/**
 * @brief Get the Distance object
 * 
 * @return float distance of the Airport 
 */
float Airport::getDistance() {
	return this->length;
}

/**
 * @brief Set the Ticket Cost object
 * 
 * @param cost a float value
 * 
 * Sets the ticket cost of the Airport
 */
void Airport::setTicketCost(float cost) {
	this->ticketCost = cost;
}

/**
 * @brief Get the Ticket Cost object
 * 
 * @return float the ticket cost of the Airport 
 */
float Airport::getTicketCost() {
	return this->ticketCost;
}

/**
 * @brief Get the Name object
 * 
 * @return string the name of the Airport
 */
std::string Airport::getName() {
	return Stops::getName();
}
