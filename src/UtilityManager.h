#ifndef UTILITYMANAGER_H
#define UTILITYMANAGER_H

#include "StartCommand.h"
#include "StopCommand.h"
#include <vector>
#include <iostream>
class UtilityManager {
private:
	std::vector<Command*> history;
public:
	UtilityManager();

	void executeWaste();

	void undoCommand();

	void LoadShedding();

	void UnfilledDam();

	void executeSewage();

	void executeWater();

	void executeElectricity();

	void addCommand(Command* com);
};

#endif
