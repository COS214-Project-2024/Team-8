#include "Road.h"

/**
 * @file Road.cpp
 * 
 * @brief This file implements the Road class
 */

/**
 * @brief Construct a new Road:: Road object
 * 
 * @param name string value of the name
 * @param length float value of the length(distance)
 * 
 * Creates a new Road object with a name and length
 * Assign the symbol 'R' to the Road object
 */
Road::Road(std::string name, float length) {
	this->name = name;
	this->length = length;
	this->symbol = 'R';
}

/**
 * @brief Get the Symbol object
 * @pre The symbol has been set
 */
char Road::getSymbol() {
	return this->symbol;
}

/**
 * @brief Get the Distance object
 * @pre The distance has been set
 */
float Road::getDistance() {
	return this->length;
}

/**
 * @brief Set the Speed Limit object
 * 
 * @param limit integer value of the speed limit
 */
void Road::setSpeedLimit(int limit) {
	this->speedLimit = limit;
}

/**
 * @brief Get the Speed Limit object
 * @pre The speed limit has been set
 */
int Road::getSpeedLimit() {
	return this->speedLimit;
}

/**
 * @brief Get the Name object
 * @pre The name has been set
 */
std::string Road::getName() {
	return Stops::getName();
}
