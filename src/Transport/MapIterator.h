#ifndef MAPITERATOR_H
#define MAPITERATOR_H

#include "RouteNode.h"
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
