#include "Buildings.h"
#ifndef STATE_H
#define STATE_H

class Buildings;

/**
 * @class State
 * @brief Abstract class representing the state of a building.
 */
class State {

protected:
    Buildings* building; ///< Pointer to the building associated with this state

public:
    /**
     * @brief Handles the operations specific to the current state.
     */
    virtual void handle() = 0;

    /**
     * @brief Changes the state of the building.
     */
    virtual void changeState() = 0;
};

#endif

