#ifndef SEWAGEBUILDER_H
#define SEWAGEBUILDER_H

#include "UtilityBuilder.h"
class SewageBuilder : public UtilityBuilder {
public:
	SewageSystems* getSewageSystem();

	SewageBuilder(int curload);

	void addCommand(Command* com);

	void setMaxWaste(int max);
};

#endif
