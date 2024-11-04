/**
 * @file Utility.h
 * @brief The header file for the Utility class, interface for the utilities
 * @author Design Wits
 * @date 2024-04-29
 */

#ifndef UTILITY_H
#define UTILITY_H

#include <iostream>
#include <thread>
#include <chrono>
#include <vector>
#include <string>
#include "EnergySource.h"

/**
 * @class Utility
 * @brief Abstract base class for all utility types in the city
 */
class Utility {
protected:
    std::string status;              /**< Current status of the utility */
    std::vector<std::string> commandHistory; /**< History of commands executed */
    float Output;                    /**< Current output level of the utility */

public:
    /**
     * @brief Virtual destructor for proper cleanup
     */
    virtual ~Utility() = default;

    /**
     * @brief Get the current status of the utility
     * @return String representation of current status
     */
    virtual std::string getStatus() = 0;

    /**
     * @brief Execute the main operation of the utility
     */
    virtual void executeOperation() = 0;

    /**
     * @brief Repair the utility when damaged
     */
    virtual void repairUtility() = 0;

    /**
     * @brief Undo the last operation
     */
    virtual void undoChange() = 0;

    /**
     * @brief Get the current output level
     * @return Float value of current output
     */
    virtual float getOutput();

    /**
     * @brief Temporarily pause utility operation
     */
    virtual void pauseOperation();

    /**
     * @brief Get the type of energy used
     * @return String describing energy type
     */
    virtual std::string getEnergyType() = 0;

    /**
     * @brief Set the output level
     * @param Output New output level
     */
    virtual void setOutput(float Output);

    /**
     * @brief Get the type of utility
     * @return String describing utility type
     */
    virtual std::string getUtilityType() = 0;

    /**
     * @brief Create a clone of this utility
     * @return Pointer to new cloned utility
     */
    virtual Utility* clone() = 0;

    /**
     * @brief Set maximum watts for power utilities
     * @param max Maximum wattage
     */
    virtual void setMaxWatts(float max) {
        std::cout << "Max watts set to " << max << " for " << getUtilityType() << ".\n";
    }
    
    /**
     * @brief Set fuel type for the utility
     * @param fuel Pointer to energy source
     */
    virtual void setFuel(EnergySource* fuel) {
        std::cout << "Fuel set for " << getUtilityType() << ".\n";
    }
    
    /**
     * @brief Set maximum waste capacity
     * @param max Maximum waste amount
     */
    virtual void setmaxWaste(int max) {
        std::cout << "Max waste set to " << max << " for " << getUtilityType() << ".\n";
    }
    
    /**
     * @brief Switch to alternative fuel source
     */
    virtual void switchFuel() {
        std::cout << "Fuel switched for " << getUtilityType() << ".\n";
    }
    
    /**
     * @brief Set maximum gallons for liquid utilities
     * @param max Maximum gallons
     */
    virtual void setMaxGallons(float max) {
        std::cout << "Max gallons set to " << max << " for " << getUtilityType() << ".\n";
    }
};

#endif // UTILITY_H