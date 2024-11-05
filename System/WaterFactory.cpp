#include "WaterFactory.h"

/**
 * @brief Create a WaterSupply object
 * 
 * @param output The output of the WaterSupply
 * 
 * @return Utility* The WaterSupply object created
 */
Utility* WaterFactory::createUtility(float output) {
	Utility* utility = new WaterSupply(output);
	utility->setMaxGallons(output * 0.8);
	return utility;
}
