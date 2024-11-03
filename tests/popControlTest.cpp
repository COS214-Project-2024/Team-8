#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../doctest.h"
#include "../PopulationControl.h"
#include "../Buildings.h"
#include "../CommercialBuilding.h"
#include "../MedicalCenter.h"

// Test PopulationControl initialization
TEST_CASE("PopulationControl Initialization") {
    PopulationControl popControl;
    CHECK(popControl.getTotalPopulation() == 0);
}

// Test updating population with new buildings
TEST_CASE("PopulationControl::updatePopulation") {
    PopulationControl popControl;

    SUBCASE("Add building within max population limit") {
        Buildings* residentialBuilding = new Buildings(500);
        popControl.updatePopulation(residentialBuilding);
        CHECK(popControl.getTotalPopulation() == 500);
    }

    SUBCASE("Exceed max population limit") {
        popControl.increasePopulation(); // set near the max limit for testing
        popControl.updatePopulation(new Buildings(PopulationControl::MAX_POPULATION - 1));
        
        Buildings* overflowBuilding = new Buildings(100);
        popControl.updatePopulation(overflowBuilding);  // Should trigger control

        CHECK(popControl.getTotalPopulation() <= PopulationControl::MAX_POPULATION);
    }
}

// Test simulatePopulationGrowth with medical centers
TEST_CASE("PopulationControl::simulatePopulationGrowth") {
    PopulationControl popControl;

    SUBCASE("Births from Medical Centers") {
        Buildings* medCenter = new MedicalCenter(200); 
        popControl.updatePopulation(medCenter);
        
        int initialPopulation = popControl.getTotalPopulation();
        popControl.simulatePopulationGrowth();

        CHECK(popControl.getTotalPopulation() == initialPopulation + 50);
    }

    SUBCASE("Exceeding max population with births") {
        Buildings* medCenter = new MedicalCenter(PopulationControl::MAX_POPULATION - 100, 200);
        popControl.updatePopulation(medCenter);

        popControl.simulatePopulationGrowth();
        CHECK(popControl.getTotalPopulation() <= PopulationControl::MAX_POPULATION);
    }
}

// Test simulateMigration with commercial buildings
TEST_CASE("PopulationControl::simulateMigration") {
    PopulationControl popControl;

    SUBCASE("Migration effect based on jobs created") {
        CommercialBuilding* office = new CommercialBuilding(100, 200);  // Creates 200 jobs
        popControl.updatePopulation(office);

        int expectedMigration = static_cast<int>(200 * PopulationControl::MIGRATION_RATE_MULTIPLIER);
        CHECK(popControl.getTotalPopulation() == expectedMigration + office->getCapacity());
    }

    SUBCASE("Exceeding max population with migration") {
        popControl.increasePopulation();  // near max limit
        CommercialBuilding* largeOffice = new CommercialBuilding(100, 100000);
        popControl.updatePopulation(largeOffice);

        CHECK(popControl.getTotalPopulation() <= PopulationControl::MAX_POPULATION);
    }
}

// Test enforcing population control when limits exceeded
TEST_CASE("PopulationControl::enforcePopulationControl") {
    PopulationControl popControl;

    SUBCASE("Emigration reduces overflow population") {
        popControl.updatePopulation(new Buildings(PopulationControl::MAX_POPULATION));
        popControl.updatePopulation(new Buildings(1000));  // Triggers population control

        int overflow = popControl.getTotalPopulation() - PopulationControl::MAX_POPULATION;
        int expectedReduction = static_cast<int>(overflow * 0.10f);

        CHECK(popControl.getTotalPopulation() <= PopulationControl::MAX_POPULATION);
        CHECK(overflow - expectedReduction <= 0);
    }
}

// Test calculateMigration
TEST_CASE("PopulationControl::calculateMigration") {
    PopulationControl popControl;

    int jobsCreated = 1000;
    int expectedMigration = static_cast<int>(jobsCreated * PopulationControl::MIGRATION_RATE_MULTIPLIER);
    CHECK(popControl.calculateMigration(jobsCreated) == expectedMigration);
}
