#include <string>
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
    std::string stateName;

public:
    /**
     * @brief Handles the operations specific to the current state.
     */
    virtual void handle() = 0;

    /**
     * @brief Changes the state of the building.
     */
    virtual void changeState() = 0;
    /**
     * @brief Virtual destructor to ensure proper cleanup of derived classes
     * 
     * This virtual destructor is necessary because the class hierarchy uses polymorphism
     * and objects may be deleted through pointers to the base class.
     */
  virtual ~State()= default;
};

#endif
