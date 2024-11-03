/**
 * @file government_unittest.cpp
 * @brief Test file for Chain of Responsibility pattern implementation
 * @author Design Wits
 * @date 2024-04-29
 */

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "FinanceSector.h"
#include "UtilitiesSector.h"
#include "GeneralSector.h"
#include "FinanceDepartment.h"
#include <memory>

TEST_SUITE("Chain of Responsibility Tests") {
    // Setup that's common for all tests
    struct ChainSetup {
        FinanceDepartment* financeDepartment;
        FinanceSector* financeSector;
        UtilitiesSector* utilitiesSector;
        GeneralSector* generalSector;

        ChainSetup() {
            financeDepartment = new FinanceDepartment();
            financeSector = new FinanceSector(financeDepartment);
            utilitiesSector = new UtilitiesSector(financeDepartment);
            generalSector = new GeneralSector(financeDepartment);

            // Set up the chain
            financeSector->setSuccessor(utilitiesSector);
            utilitiesSector->setSuccessor(generalSector);
        }

        ~ChainSetup() {
            delete generalSector;
            delete utilitiesSector;
            delete financeSector;
            delete financeDepartment;
        }
    };

    TEST_CASE("Testing Chain Setup") {
        ChainSetup setup;
        
        CHECK(setup.financeSector->getSuccessor() == setup.utilitiesSector);
        CHECK(setup.utilitiesSector->getSuccessor() == setup.generalSector);
        CHECK(setup.generalSector->getSuccessor() == nullptr);
    }

    TEST_CASE("Testing Finance Request Handling") {
        ChainSetup setup;
        
        // Test direct finance requests
        SUBCASE("Finance request is handled by Finance Sector") {
            std::string request = "FINANCE: Budget review needed";
            setup.financeSector->handleRequest(request);
            // Note: Since console output is used, we can't directly test the output
            // In a real system, we'd want to mock the output or use a different verification method
        }

        SUBCASE("Finance request with tax") {
            std::string request = "FINANCE: TAX collection review";
            setup.financeSector->handleRequest(request);
        }
    }

    TEST_CASE("Testing Utilities Request Handling") {
        ChainSetup setup;
        
        SUBCASE("Utilities request is handled by Utilities Sector") {
            std::string request = "UTILITIES: Power maintenance required";
            setup.financeSector->handleRequest(request);
        }

        SUBCASE("Utilities request with funds") {
            std::string request = "UTILITIES: FUNDS allocation needed";
            setup.financeSector->handleRequest(request);
        }
    }

    TEST_CASE("Testing General Request Handling") {
        ChainSetup setup;
        
        SUBCASE("General request is handled by General Sector") {
            std::string request = "General inquiry about services";
            setup.financeSector->handleRequest(request);
        }
    }

    TEST_CASE("Testing Request Propagation") {
        ChainSetup setup;
        
        SUBCASE("Non-finance request propagates to correct handler") {
            std::string request = "UTILITIES: Emergency maintenance";
            setup.financeSector->handleRequest(request);
            // Request should propagate to Utilities Sector
        }

        SUBCASE("Non-specific request propagates to General Sector") {
            std::string request = "General information needed";
            setup.financeSector->handleRequest(request);
            // Request should propagate to General Sector
        }
    }

    TEST_CASE("Testing Multiple Requests") {
        ChainSetup setup;
        
        std::vector<std::string> requests = {
            "FINANCE: Budget review",
            "UTILITIES: Power outage",
            "General inquiry",
            "FINANCE: TAX review",
            "UTILITIES: FUNDS needed"
        };

        for(const auto& request : requests) {
            setup.financeSector->handleRequest(request);
        }
    }

    TEST_CASE("Testing Null Request Handling") {
        ChainSetup setup;
        
        SUBCASE("Empty request string") {
            std::string request = "";
            setup.financeSector->handleRequest(request);
            // Should be handled by General Sector
        }
    }
}