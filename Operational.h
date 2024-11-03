#include <string>
#include <exception>
using namespace std;

#ifndef __Operational_h__
#define __Operational_h__

#include "State.h"

/**
 * @class Operational
 * @brief Represents the operational state of a building or system.
 */
class Operational: public State
{
	public: 
		/**
		 * @brief Constructor for the Operational class.
		 */
		Operational();

		/**
		 * @brief Handles the operational logic for the state.
		 */
		void handle();

		/**
		 * @brief Changes the state to another state.
		 */
		void changeState();

		/**
		 * @brief Gets the name of the current state.
		 * @return String representing the name of the state.
		 */
		string getStateName();
};

#endif

