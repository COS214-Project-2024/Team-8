#ifndef MAPITERATOR_H
#define MAPITERATOR_H

#include "RouteNode.h"
/**
 * @file MapIterator.h
 * 
 * @brief This file implements the MapIterator class 
 * 
 * This class is used to iterate through the RouteNode to simulate travelling
 */
class MapIterator {
protected:
	RouteNode* head;
	RouteNode* current;

public:
	MapIterator(RouteNode* cur);

	Stops* operator*();

	RouteNode* operator++();

	bool operator==(RouteNode* other);

	RouteNode* currentNode();

	RouteNode* headNode();
};

#endif
