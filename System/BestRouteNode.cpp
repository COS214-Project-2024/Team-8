#include "BestRouteNode.h"

/**
 * @brief Default constructor for BestRouteNode.
 * 
 * Initializes a BestRouteNode instance with default parameters
 */
BestRouteNode::BestRouteNode() {
	this->data = nullptr;
	this->successor = nullptr;
}

/**
 * @brief Adds a stop to the best route.
 * 
 * Adds a stop to the best route and calculates the distance based on the stops.
 * 
 * @param data The stop to add to the best route
 */
void BestRouteNode::add(Stops* data) {
	if(this->data == nullptr){
		this->data = data;
		return;
	}

	else
	if(successor){
		successor->add(data);
	}
	else{
		successor = new BestRouteNode();
		successor->add(data);
	}
}

/**
 * @brief Gets the distance of the best route.
 * 
 * @return float The distance of the best route
 */
float BestRouteNode::getDistance() {
	return data->getDistance();
}

/**
 * @brief Gets the stop data of the best route.
 * 
 * @return Stops* The stop data of the best route
 */
Stops* BestRouteNode::getData() {
	return data;
}

/**
 * @brief Travels to the next stop in the best route.
 * 
 * @return RouteNode* The next stop in the best route
 */
RouteNode* BestRouteNode::travel() {
	return successor;
}