#include <string>
#include <exception>
using namespace std;

#ifndef __UnderConstruction_h__
#define __UnderConstruction_h__

#include "State.h"

/**
 * @class UnderConstruction
 * @brief Represents the state of a building that is under construction.
 */
class UnderConstruction : public State
{
public: 
    /**
     * @brief Constructor for the UnderConstruction state.
     */
    UnderConstruction();
    
    /**
     * @brief Handles actions specific to the UnderConstruction state.
     */
    void handle();
    
    /**
     * @brief Changes the state of the building from UnderConstruction to another state.
     */
    void changeState();
    
    /**
     * @brief Gets the name of the current state.
     * @return The name of the state as a string.
     */
    string getStateName();
};

#endif

