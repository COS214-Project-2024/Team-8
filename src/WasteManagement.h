#ifndef WASTEMANAGEMENT_H
#define WASTEMANAGEMENT_H

#ifndef WASTEMANAGEMENT_H
#define WASTEMANAGEMENT_H

#include "Utility.h"
/**
 * @file WasteManagement.h
 * 
 * @brief The header file for the WasteManagement class
 */
class WasteManagement : public Utility {

private:
	int processCapacity;
	float recycledperc;

public:
	WasteManagement(float output);

	std::string getStatus();
	std::string getStatus();

	void repairUtility();
	void repairUtility();

	void executeOperation();
	void executeOperation();

	float getOutput();

	void pauseOperation();
	void pauseOperation();

	std::string getUtilityType();

	Utility* clone();

	void setProcessCapacity(int pro);

	void undoChange();
};

#endif
