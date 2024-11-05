/**
 * @file government_unittest.cpp
 * @brief Test file for Government implementations including Chain of Responsibility, Observer, and Command patterns
 * @author Design Wits
 * @date 2024-04-29
 */

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Government.h"
#include "FinanceSector.h"
#include "UtilitiesSector.h"
#include "GeneralSector.h"
#include "FinanceDepartment.h"
#include "Policies.h"
#include "EconomicPolicies.h"
#include "PublicServicesPolicies.h"
#include "Citizen.h"
#include "Transport.h"
#include <memory>

// Mock classes for testing
class MockGovernment : public Government {
public:
    MockGovernment(FinanceDepartment* financeDepartment) : Government(financeDepartment) {}
    bool policiesExecuted = false;
    void executePolicies() { policiesExecuted = true; }
};

class MockCitizen : public Citizen {
public:
    bool wasNotified = false;
    
    // Constructor using Citizen's constructor
    MockCitizen() : Citizen("MockCitizen", 50000.0f, 30, 75.0f) {}

    // Override only the update function to track notification
    void update(float newTaxRate) override {
        wasNotified = true;
        Citizen::update(newTaxRate);
    }
};

// Setup structure for Chain of Responsibility tests
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

TEST_CASE("Chain of Responsibility Basic Tests") {
    ChainSetup setup;
    
    SUBCASE("Chain Setup Verification") {
        CHECK(setup.financeSector->getSuccessor() == setup.utilitiesSector);
        CHECK(setup.utilitiesSector->getSuccessor() == setup.generalSector);
        CHECK(setup.generalSector->getSuccessor() == nullptr);
    }

    SUBCASE("Finance Request Handling") {
        std::string request = "FINANCE: Budget review needed";
        setup.financeSector->handleRequest(request);
    }

    SUBCASE("Utilities Request Handling") {
        std::string request = "UTILITIES: Power maintenance required";
        setup.financeSector->handleRequest(request);
    }

    SUBCASE("General Request Handling") {
        std::string request = "General inquiry about services";
        setup.financeSector->handleRequest(request);
    }
}

TEST_CASE("Policy Implementation Tests") {
    FinanceDepartment* financeDepartment = new FinanceDepartment();
    MockGovernment govt(financeDepartment);
    
    SUBCASE("Economic Policies") {
        EconomicPolicies econPolicies(&govt);
        MockCitizen testCitizen;
        PublicServicesPolicies psPolicies(&govt);
        
        econPolicies.execute();
        CHECK(govt.policiesExecuted);
    }

    SUBCASE("Public Services Policies") {
        PublicServicesPolicies psPolicies(&govt);
        psPolicies.execute();
        CHECK(govt.policiesExecuted);
    }

    delete financeDepartment;
}

TEST_CASE("Observer Pattern Implementation") {
    FinanceDepartment* financeDepartment = new FinanceDepartment();
    Government govt(financeDepartment);
    MockCitizen citizen1, citizen2;
    
    SUBCASE("Attachment and Notification") {
        govt.attach(&citizen1);
        govt.attach(&citizen2);
        govt.notify();
        
        CHECK(citizen1.wasNotified);
        CHECK(citizen2.wasNotified);
    }
    
    SUBCASE("Detachment Verification") {
        govt.attach(&citizen1);
        govt.detach(&citizen1);
        govt.notify();
        
        CHECK_FALSE(citizen1.wasNotified);
    }

    delete financeDepartment;
}

TEST_CASE("Multiple Request Processing") {
    ChainSetup setup;
    
    SUBCASE("Multiple Request Types") {
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

    SUBCASE("Empty Request Handling") {
        std::string request = "";
        setup.financeSector->handleRequest(request);
    }
}