#include <exception>
using namespace std;

#include "PopulationMemento.h"
#include "State.h"
#include "PopulationHistory.h"

State PopulationMemento::getState() {
	return this->_state;
}

void PopulationMemento::setState(State aState) {
	throw "Not yet implemented";
}

