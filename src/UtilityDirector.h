#ifndef UTILITYDIRECTOR_H
#define UTILITYDIRECTOR_H

#include "UtilityBuilder.h"
class UtilityDirector {
private:
	UtilityBuilder* creator = nullptr;

public:
	void construct();
};

#endif
