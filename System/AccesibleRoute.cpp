#include "AccesibleRoute.h"

/**
 * @file AccesibleRoute.cpp
 * 
 * @brief This is the AccesibleRoute class implementation file
 * A subclass of RouteNode
 */

/**
 * @brief Construct a new AccesibleRoute:: AccesibleRoute object
 * 
 * Creates a new AccesibleRoute object
 * Sets the data and successor to nullptr
 */
AccesibleRoute::AccesibleRoute() {
	this->data = nullptr;
	this->successor = nullptr;
}

/**
 * @brief Add a Stops object to the AccesibleRoute object
 * 
 * @param data a Stops object
 * 
 * Adds a Stop to current object or delegates to the successor
 */
void AccesibleRoute::add(Stops* data) {
	if(this->data == nullptr){
		this->data = data;
		return;
	}

	if(successor){
		successor->add(data);
	}
	else{
		successor = new AccesibleRoute();
		successor->add(data);
	}
}

/**
 * @brief Get the Distance object
 * 
 * @return float the distance of the AccesibleRoute object
 */
float AccesibleRoute::getDistance() {
	return data->getDistance();
}

/**
 * @brief Get the Data object
 * 
 * @return Stops* the data of the AccesibleRoute object
 */
Stops* AccesibleRoute::getData() {
	return data;
}

/**
 * @brief Travel to the next RouteNode object
 * 
 * @return RouteNode* the successor of the current object
 */
RouteNode* AccesibleRoute::travel() {
	return successor;
}

