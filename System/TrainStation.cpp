#include "TrainStation.h"
/**
 * @file TrainStation.cpp
 * 
 * @brief This file implements the TrainStation class
 * 
 */

/**
 * @brief Construct a new Train Station:: Train Station object
 * 
 * @param name string value of the name of the station
 * @param length float value of the distance to the station
 * Sets the name, length, and symbol of the station
 */
TrainStation::TrainStation(std::string name, float length) {
	this->name = name;
	this->length = length;
	this->symbol = 'T';
}

/**
 * @brief Get the Symbol object
 * 
 * @return char the symbol of the station
 */
char TrainStation::getSymbol() {
	return this->symbol;
}

/**
 * @brief Get the Distance object
 * 
 * @return float the distance to the station
 */
float TrainStation::getDistance() {
	return this->length;
}

/**
 * @brief Set the Ticket Cost object
 * 
 * @param cost float value of the ticket cost
 */
void TrainStation::setTicketCost(float cost) {
	this->ticketCost = cost;
}

/**
 * @brief Get the Ticket object
 * 
 * @return float the ticket cost
 */
float TrainStation::getTicket() {
	return this->ticketCost;
}

/**
 * @brief Get the Name object
 * 
 * @return string the name of the station
 */
std::string TrainStation::getName() {
	return Stops::getName();
}


