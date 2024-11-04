#ifndef WATERSUPPLY_H
#define WATERSUPPLY_H

#include "Utility.h"
#include <iostream>
#include "Command.h"
#include <string>

/**
 * @file WaterSupply.h
 * 
 * @brief The header file for the WaterSupply class
 */
class WaterSupply : public Utility {
private:
    int maxGallons;
    float purityPercentage;
	

public:
    WaterSupply(float curSupply);
	WaterSupply(int gallons,  float purity);
	std::string getEnergyType() override;
    void addCommand(Command* com);
    
    std::string getStatus() ;
    
    void repairUtility() override;

    void pauseOperation() override;

    void executeOperation() override;

    void setMaxGallons(float max) override;

    float getOutput() override;

    void undoChange() override;

    Utility* clone() override;

    std::string getUtilityType() override;
};

#endif // WATERSUPPLY_H
