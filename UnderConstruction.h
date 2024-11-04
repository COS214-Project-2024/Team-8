#ifndef __UnderConstruction_h__
#define __UnderConstruction_h__

#include <string>
#include "State.h"
#include "Buildings.h"

/**
 * @class UnderConstruction
 * @brief Represents the state of a building that is under construction.
 */
class UnderConstruction : public State
{
protected:
    Buildings* building; ///< Pointer to the building associated with this state
    std::string stateName;

public:
    /**
     * @brief Constructor for the UnderConstruction state.
     */
    UnderConstruction();

    /**
     * @brief Handles actions specific to the UnderConstruction state.
     */
    void handle() override;

    /**
     * @brief Changes the state of the building from UnderConstruction to another state.
     */
    void changeState() override;

    /**
     * @brief Gets the name of the current state.
     * @return The name of the state as a string.
     */
    std::string getStateName() ;
};

#endif // __UnderConstruction_h__  // Fixed the include guard
