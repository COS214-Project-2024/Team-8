#include "AccesibleRoute.h"

AccesibleRoute::AccesibleRoute() {
	this->data = nullptr;
	this->successor = nullptr;
}

void AccesibleRoute::add(Stops* data) {
	if(successor){
		successor->add(data);
	}
	else{
		successor = new AccesibleRoute();
		successor->add(data);
	}
}

float AccesibleRoute::getDistance() {
	return data->getDistance();
}

Stops* AccesibleRoute::getData() {
	return data;
}

RouteNode* AccesibleRoute::travel() {
	return successor;
}

