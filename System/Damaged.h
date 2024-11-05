#include <string>
#include <exception>
using namespace std;

#ifndef __Damaged_h__
#define __Damaged_h__

#include "State.h"

/**
 * @class Damaged
 * @brief Represents a damaged state in a building's lifecycle, inheriting from the State class.
 */
class Damaged : public State
{

protected:
    Buildings* building; ///< Pointer to the building associated with this state
    string stateName;

public:
    /**
     * @brief Constructs a new Damaged state object.
     */
    Damaged();

    /**
     * @brief Handles operations specific to the Damaged state.
     */
    void handle();

    /**
     * @brief Changes the state from Damaged to another state.
     */
    void changeState();

    /**
     * @brief Retrieves the name of the current state.
     * @return The name of the state as a string.
     */
    string getStateName();

};

#endif

