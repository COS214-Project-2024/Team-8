#include "SewageFactory.h"

/**
 * @brief Create a SewageSystems object
 * 
 * @param output The output of the SewageSystems
 * 
 * @return Utility* The SewageSystems object created
 */
Utility* SewageFactory::createUtility(float output) {
	Utility* utility = new SewageSystems(output);
	utility->setmaxWaste(output * 2.5);
	return utility;
}
