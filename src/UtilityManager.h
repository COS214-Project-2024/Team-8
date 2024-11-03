#ifndef UTILITYMANAGER_H
#define UTILITYMANAGER_H

#include "StartCommand.h"
#include "StopCommand.h"
#include "UndoCommand.h"
#include <vector>
#include <iostream>
/**
 * @brief The UtilityManager class
 * 
 * The UtilityManager class is used to manage the utilities in the city
 */
class UtilityManager {
private:
	std::vector<Command*> commands;
public:
	UtilityManager();

	void executeWaste();

	void undoCommand();

	void LoadShedding();

	void UnfilledDam();

	void executeSewage();

	void executeWater();
	void executeWater();

	void executeElectricity();
	void executeElectricity();

	void addCommand(Command* com);
	void addCommand(Command* com);
};

#endif
