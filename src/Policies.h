/**
 * @file Policies.h
 * @brief Abstract base class for policy commands implementing Command pattern
 * @author Design Wits
 * @date 2024-04-29
 */

#ifndef POLICIES_H
#define POLICIES_H

#include "Government.h"
#include "Command.h"

class Government;
class Policies;

/**
 * @class Policies
 * @brief Abstract base class for policy commands
 * 
 * This class serves as the ConcreteCommand in the Command pattern,
 * providing a base interface for different types of government policies.
 * Each policy type inherits from this class and implements its specific
 * execution logic.
 */
class Policies : public Command {
protected:
    Government* government;  ///< Pointer to the government (Invoker)

public:
    /**
     * @brief Construct a new Policies object
     * @param govt Pointer to the government that will execute the policies
     */
    explicit Policies(Government* govt) : government(govt) {}

    /**
     * @brief Pure virtual function for policy execution logic
     * 
     * This function must be implemented by derived policy classes to
     * define their specific execution behavior.
     */
    virtual void executePolicy() = 0;

    /**
     * @brief Implementation of Command pattern's execute method
     * 
     * Calls the policy-specific executePolicy() method.
     */
    void execute() override { executePolicy(); }

    /**
     * @brief Virtual destructor
     */
    virtual ~Policies() = default;
};

#endif // POLICIES_H