#ifndef UTILITY_H
#define UTILITY_H

#include <iostream>
#include <thread>
#include <chrono>
#include <vector>
#include <string>
#include "EnergySource.h"

/**
 * @file Utility.h
 * 
 * @brief The header file for the Utility class, interface for the utilities
 */
class Utility {
protected:
    std::string status;
    std::vector<std::string> commandHistory;
    float Output;

public:
    virtual std::string getStatus() = 0;
    virtual void executeOperation() = 0;
    virtual void repairUtility() = 0;
    virtual void undoChange() = 0;
    virtual float getOutput();
    virtual void pauseOperation();
    virtual std::string getEnergyType() = 0;
    virtual void setOutput(float Output);
    virtual std::string getUtilityType() = 0;
    virtual Utility* clone() = 0;

    // Added implementations
    virtual void setMaxWatts(float max) {
        std::cout << "Max watts set to " << max << " for " << getUtilityType() << ".\n";
    }
    
    virtual void setFuel(EnergySource* fuel) {
        std::cout << "Fuel set for " << getUtilityType() << ".\n";
    }
    
    virtual void setmaxWaste(int max) {
        std::cout << "Max waste set to " << max << " for " << getUtilityType() << ".\n";
    }
    
    virtual void switchFuel() {
        std::cout << "Fuel switched for " << getUtilityType() << ".\n";
    }
    
    virtual void setMaxGallons(float max) {
        std::cout << "Max gallons set to " << max << " for " << getUtilityType() << ".\n";
    }
};

#endif // UTILITY_H
