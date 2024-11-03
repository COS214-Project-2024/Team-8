#include "Utility.h"

/**
 * @brief return the output of the Utility
 * 
 * @return float The output of the Utility
 */
float Utility::getOutput() {
	return this->Output;
}

/**
 * @brief Set the max watts of the Utility
 * 
 * @throw NOT A MEMBER OF SAID CLASS
 * 
 * This function only works for the PowerPlant class
 */
std::string Utility::getEnergyType() {
	throw "NOT A MEMBER OF SAID CLASS";
}

/**
 * @brief Set the output of the Utility
 * 
 * @param Output The output of the Utility
 * 
 */
void Utility::setOutput(float Output) {
	this->Output = Output;
}

