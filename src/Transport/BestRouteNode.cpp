#include "BestRouteNode.h"

BestRouteNode::BestRouteNode() {
	this->data = nullptr;
	this->successor = nullptr;
}

void BestRouteNode::add(Stops* data) {
	if(successor){
		successor->add(data);
	}
	else{
		successor = new BestRouteNode();
		successor->add(data);
	}
}

float BestRouteNode::getDistance() {
	return data->getDistance();
}

Stops* BestRouteNode::getData() {
	return data;
}

RouteNode* BestRouteNode::travel() {
	return successor;
}