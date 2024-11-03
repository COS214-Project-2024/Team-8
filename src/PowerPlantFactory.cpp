#include "PowerPlantFactory.h"

/**
 * @brief Create a Utility object of type UtilityPowerPlant
 * 
 * @param output The output of the UtilityPowerPlant
 * 
 * @return Utility* The Utility object created
 */
Utility* PowerPlantFactory::createUtility(float output) {
	Utility* utility = new UtilityPowerPlant(output);
	float maxWatts = output * 1.75;
	utility->setMaxWatts(maxWatts);
	return utility;
}
