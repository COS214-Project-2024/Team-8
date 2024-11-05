#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../System/doctest.h"
#include "../System//PopulationControl.h"
#include "../System/Buildings.h"
#include "../System/CommercialBuilding.h"
#include "../System/MedicalCenter.h"
#include "../System/Apartment.h"

TEST_SUITE("PopulationControl Tests") {
    TEST_CASE("Initial Population") {
        PopulationControl popControl;
        CHECK(popControl.getTotalPopulation() == 0);
    }

    TEST_CASE("Update Population with Residential Building") {
        PopulationControl popControl;
        
        SUBCASE("Adding residential building increases population") {
            auto* building = new Apartment(100);House::House(string bName,int pReq, int wReq, double mCost, int sCost, int waste, int capacity)
            popControl.updatePopulation(building);
            CHECK(popControl.getTotalPopulation() == 100);
            delete building;
        }

        SUBCASE("Adding multiple residential buildings") {
            auto* building1 = new MockResidentialBuilding(100);
            auto* building2 = new MockResidentialBuilding(150);
            
            popControl.updatePopulation(building1);
            popControl.updatePopulation(building2);
            CHECK(popControl.getTotalPopulation() == 250);
            
            delete building1;
            delete building2;
        }
    }

    TEST_CASE("Population Growth Simulation") {
        PopulationControl popControl;
        auto* residential = new MockResidentialBuilding(100);
        popControl.updatePopulation(residential);

        SUBCASE("Population growth with medical centers") {
            auto* hospital = new MockMedicalCenter();
            popControl.simulatePopulationGrowth();
            CHECK(popControl.getTotalPopulation() > 100);
            delete hospital;
        }
        
        delete residential;
    }

    TEST_CASE("Migration Simulation") {
        PopulationControl popControl;
        
        SUBCASE("Migration increases population based on jobs") {
            auto* residential = new MockResidentialBuilding(100);
            popControl.updatePopulation(residential);

            auto* commercial = new MockCommercialBuilding(50);
            int jobsCreated = commercial->getJobsCreated();
            popControl.simulateMigration(jobsCreated);
            
            CHECK(popControl.getTotalPopulation() > 100);
            
            delete residential;
            delete commercial;
        }
    }

    TEST_CASE("Population Control Enforcement") {
        PopulationControl popControl;
        
        SUBCASE("Population cannot exceed maximum limit") {
            // Add population up to near maximum
            for(int i = 0; i < 10; i++) {
                auto* building = new MockResidentialBuilding(PopulationControl::MAX_POPULATION / 10);
                popControl.updatePopulation(building);
                delete building;
            }
            
            // Try to add more population
            auto* extraBuilding = new MockResidentialBuilding(1000);
            popControl.updatePopulation(extraBuilding);
            
            CHECK(popControl.getTotalPopulation() <= PopulationControl::MAX_POPULATION);
            delete extraBuilding;
        }
    }

    TEST_CASE("Population Increase") {
        PopulationControl popControl;
        int initialPop = popControl.getTotalPopulation();
        
        SUBCASE("Increase population directly") {
            popControl.increasePopulation();
            CHECK(popControl.getTotalPopulation() > initialPop);
        }
    }
}
