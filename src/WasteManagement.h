#ifndef WASTEMANAGEMENT_H
#define WASTEMANAGEMENT_H

#include "Utility.h"
class WasteManagement : public Utility {
private:
	int processCapacity;
	int currentload;
	float recycledperc;

public:
	WasteManagement(int curload);

	std::string getStatus();

	void repairUtility();

	void executeOperation();

	int getCurrentLoad();

	void pauseOperation();

	void addCommand(Command* com);

	void setProcessCapacity(int pro);

	std::string getUtilityType();

	void undoChange();


};

#endif
