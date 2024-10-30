#include "SewageBuilder.h"

SewageSystems* SewageBuilder::getSewageSystem() {
	return dynamic_cast<SewageSystems*>(this->utility);
}

SewageBuilder::SewageBuilder(int curload) {
	this->utility = new SewageSystems(curload);
}

void SewageBuilder::addCommand(Command* com) {
	this->utility->addCommand(com);
}

void SewageBuilder::setMaxWaste(int max) {
	this->utility->setmaxWaste(max);
}
