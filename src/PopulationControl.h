#ifndef POPULATIONCONTROL_H
#define POPULATIONCONTROL_H

#include <iostream>
#include <vector>
#include "Buildings.h"
#include "MedicalCenter.h"
#include "CommercialBuilding.h"

/**
 * @class PopulationControl
 * @brief Class for managing population dynamics in a city.
 */
class PopulationControl {
public:
    /** 
     * @brief Constructor for the PopulationControl class. 
     */
    PopulationControl();

    /** 
     * @brief Destructor for the PopulationControl class, cleans up dynamically allocated buildings.
     */
    ~PopulationControl();

    /**
     * @brief Updates the population based on the building being added.
     * 
     * @param building Pointer to the building being added.
     */
    void updatePopulation(Buildings* building);

    /**
     * @brief Gets the current total population.
     * 
     * @return Current population as an integer.
     */
    int getTotalPopulation() ;

    /**
     * @brief Simulates population growth based on hospitals' birth rates.
     * 
     * @param numberOfHospitals The number of hospitals contributing to birth rates.
     */
    void simulatePopulationGrowth();

    /**
     * @brief Calculates migration based on commercial buildings' job creation.
     * 
     * @param jobsCreated The number of jobs created by new commercial buildings.
     */
    void simulateMigration(int jobsCreated);

private:
    std::vector<Buildings*> buildings; ///< List of buildings in the city
    int totalPopulation;                ///< Current total population
    static const int MAX_POPULATION;    ///< Maximum allowable population

    /**
     * @brief Calculates the migration effect based on created jobs.
     * 
     * @param jobsCreated The number of jobs created by new commercial buildings.
     * @return The calculated migration increase.
     */
    int calculateMigration(int jobsCreated) ;
};

#endif // POPULATIONCONTROL_H
