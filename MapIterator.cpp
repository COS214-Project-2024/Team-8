#include "MapIterator.h"

/**
 * @file MapIterator.cpp
 * 
 * @brief This file implements the MapIterator class 
 */

/**
 * @brief Construct a new Map Iterator:: Map Iterator object
 * 
 * @param cur has reference to the current node
 * 
 * Set the head and current node to the current node
 */
MapIterator::MapIterator(RouteNode* cur) {
	this->current = cur;
	this->head = cur;
}

/**
 * @brief Get the Stops object
 * 
 * @return Stops* data of the current object
 */
Stops* MapIterator::operator*() {
	return this->current->getData();
}

/**
 * @brief Overload the ++ operator
 * 
 * @return RouteNode* pointer of the current object
 */
RouteNode* MapIterator::operator++() {
	this->current = this->current->travel();
	return this->current;
}

/**
 * @brief Overload the == operator
 * 
 * @param other is the other RouteNode
 * 
 * @return true if the current node is equal to the other node
 */
bool MapIterator::operator==(RouteNode* other) {
	return this->current == other;
}

/**
 * @brief Get the current node
 * 
 * @return RouteNode* pointer of the current object
 */
RouteNode* MapIterator::currentNode() {
	return this->current;
}

/**
 * @brief Get the head node
 * 
 * @return RouteNode* pointer of the head object
 */
RouteNode* MapIterator::headNode() {
	return this->head;
}
