#include "MapIterator.h"

MapIterator::MapIterator(RouteNode* cur) {
	this->current = cur;
	this->head = cur;
}

Stops* MapIterator::operator*() {
	return this->current->getData();
}

RouteNode* MapIterator::operator++() {
	this->current = this->current->travel();
	return this->current;
}

bool MapIterator::operator==(RouteNode* other) {
	return this->current == other;
}

RouteNode* MapIterator::currentNode() {
	return this->current;
}

RouteNode* MapIterator::headNode() {
	return this->head;
}
