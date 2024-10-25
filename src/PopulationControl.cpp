#include "PopulationControl.h"

// Define the maximum population
const int PopulationControl::MAX_POPULATION = 1000000;
 // 5% per 1000 jobs
const float PopulationControl::MIGRATION_RATE_MULTIPLIER = 0.05f;
 // Birth rate increment per hospital
const float PopulationControl::BIRTH_RATE_PER_HOSPITAL = 15.0f;

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

        // Simulate migration based on jobs created for commercial buildings
        CommercialBuilding* commercialBuilding = dynamic_cast<CommercialBuilding*>(building);
        if (commercialBuilding != nullptr) {
            simulateMigration(commercialBuilding->getJobsCreated());
        }
    } else {
        std::cout << "Cannot add building: population limit exceeded! Enforcing population policy." << std::endl;
        delete building;
        // Enforce policy to manage population overflow
        enforcePopulationControl();
    }
}

int PopulationControl::getTotalPopulation(){
    return totalPopulation;
}

void PopulationControl::simulatePopulationGrowth() {
    int totalBirths = 0;
    for (size_t i = 0; i < buildings.size(); ++i) {
        MedicalCenter* hospital = dynamic_cast<MedicalCenter*>(buildings[i]);
        if (hospital != nullptr) {
            totalBirths += hospital->getBirthRate();
        }
    }


    totalPopulation += totalBirths;

    if (totalPopulation > MAX_POPULATION) {
        enforcePopulationControl();
    }
}

void PopulationControl::simulateMigration(int jobsCreated) {
    int migrationEffect = calculateMigration(jobsCreated);
    totalPopulation += migrationEffect;

    if (totalPopulation > MAX_POPULATION) {
        enforcePopulationControl();
    }
}

int PopulationControl::calculateMigration(int jobsCreated) {
    return (int)(jobsCreated * MIGRATION_RATE_MULTIPLIER);
}

void PopulationControl::enforcePopulationControl() {
    int overflow = totalPopulation - MAX_POPULATION;
    // Reduce population through emigration incentive
    if (overflow > 0) {
         // Emigrate 10% of overflow
        int emigration = (int)(overflow * 0.10); 
        std::cout << "Population exceeds maximum limit. Emigrating " << emigration << " people." << std::endl;
        totalPopulation -= emigration;
    }

    // Cap the population at the maximum threshold
    if (totalPopulation > MAX_POPULATION) {
        totalPopulation = MAX_POPULATION;
    }
}
