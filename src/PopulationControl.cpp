#include "PopulationControl.h"

// Define the maximum population constant
const int PopulationControl::MAX_POPULATION = 1000000;

PopulationControl::PopulationControl() : totalPopulation(0) {}

PopulationControl::~PopulationControl() {
    for (Buildings* building : buildings) {
        delete building;
    }
}

void PopulationControl::updatePopulation(Buildings* building) {
    int capacity = building->getCapacity();

    // Check if adding this building will exceed the maximum population
    if (totalPopulation + capacity <= MAX_POPULATION) {
        totalPopulation += capacity; 
        buildings.push_back(building);

        // If the building is a commercial one, simulate migration based on jobs created
        if (dynamic_cast<CommercialBuilding*>(building)) {
            int jobsCreated = building->getJobsCreated(); // Assume this method exists
            simulateMigration(jobsCreated);
        }
    } else {
        // Handle case where the population would exceed the threshold
        std::cout << "Cannot add building: population limit exceeded!" << std::endl;
        delete building;
    }
}

int PopulationControl::getTotalPopulation() {
    return totalPopulation;
}

void PopulationControl::simulatePopulationGrowth() {
    int totalBirths = 0;

    // Sum births from all hospitals
    for (Buildings* building : buildings) {
        if (dynamic_cast<MedicalCenter*>(building)) {
            totalBirths += building->getBirthRate();
        }
    }

    totalPopulation += totalBirths;

    // Ensure population does not exceed the maximum limit
    if (totalPopulation > MAX_POPULATION) {
        totalPopulation = MAX_POPULATION;
    }
}

void PopulationControl::simulateMigration(int jobsCreated) {
    // Calculate migration based on the number of jobs created
    int migrationEffect = calculateMigration(jobsCreated);
    totalPopulation += migrationEffect;

    // Ensure population does not exceed the maximum limit
    if (totalPopulation > MAX_POPULATION) {
        totalPopulation = MAX_POPULATION;
    }
}

int PopulationControl::calculateMigration(int jobsCreated) {
    //Migration rate of 5% per 1000 jobs created
    return static_cast<int>(jobsCreated * 0.05);
}
