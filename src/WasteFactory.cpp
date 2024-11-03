#include "WasteFactory.h"

/**
 * @brief Create a WasteManagement object
 * 
 * @param output The output of the WasteManagement
 * 
 * @return Utility* The WasteManagement object created
 */
Utility* WasteFactory::createUtility(float output) {
	Utility* utility = new WasteManagement(output);
	utility->setmaxWaste(output * 0.8);
	return utility;
}
