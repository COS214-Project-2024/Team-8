#include "Airpot.h"

/**
 * @file Airpot.cpp
 * 
 * @brief This is the Airpot class implementation file
 * 
 */

/**
 * @brief Construct a new Airpot:: Airpot object
 * 
 * @param name
 * @param length
 * Creates a new Airpot object with the given name and length
 */
Airpot::Airpot(std::string name, float length) {
	this->name = name;
	this->length = length;
	this->symbol = 'A';
}

/**
 * @brief Get the Symbol object
 * 
 * @return char symbol of the Airpot 
 */
char Airpot::getSymbol() {
	return this->symbol;
}

/**
 * @brief Get the Distance object
 * 
 * @return float distance of the Airpot 
 */
float Airpot::getDistance() {
	return this->length;
}

/**
 * @brief Set the Ticket Cost object
 * 
 * @param cost a float value
 * 
 * Sets the ticket cost of the Airpot
 */
void Airpot::setTicketCost(float cost) {
	this->ticketCost = cost;
}

/**
 * @brief Get the Ticket Cost object
 * 
 * @return float the ticket cost of the Airpot 
 */
float Airpot::getTicketCost() {
	return this->ticketCost;
}

/**
 * @brief Get the Name object
 * 
 * @return string the name of the Airpot
 */
std::string Airpot::getName() {
	return Stops::getName();
}
