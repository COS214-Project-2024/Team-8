#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Government.h"
#include "UtilitiesSector.h"
#include "FinanceSection.h"
#include "Citizen.h"

class MockCitizen : public CitizenInterface {
public:
    bool wasNotified = false;
    void update() override { wasNotified = true; }
};

TEST_CASE("Testing Government Sectors") {
    SUBCASE("Test Government Observer Pattern") {
        Government govt;
        MockCitizen citizen1, citizen2;
        
        SUBCASE("Attach and Notify Citizens") {
            govt.attach(&citizen1);
            govt.attach(&citizen2);
            govt.notify();
            
            CHECK(citizen1.wasNotified);
            CHECK(citizen2.wasNotified);
        }
        
        SUBCASE("Detach Citizens") {
            govt.attach(&citizen1);
            govt.detach(&citizen1);
            govt.notify();
            
            CHECK_FALSE(citizen1.wasNotified);
        }
    }
    
    SUBCASE("Test UtilitiesSector") {
        UtilitiesSector utilities;
        
        SUBCASE("Handle Utilities Request") {
            utilities.setBudget(1000.0);
            float funds = utilities.requestAllocationOfUtilitiesFunds();
            CHECK(funds > 0);
        }
        
        SUBCASE("Custom Request Handling") {
            utilities.handleRequest("utilities maintenance");
            CHECK(utilities.getBudget() >= 0);
        }
    }
    
    SUBCASE("Test FinanceSection") {
        FinanceSection finance;
        
        SUBCASE("Handle Finance Request") {
            finance.setBudget(1000.0);
            double tax = finance.requestCollectionOfPropertyTax();
            CHECK(tax > 0);
            CHECK(finance.getTotalRevenue() > 0);
        }
        
        SUBCASE("Custom Request Handling") {
            finance.handleRequest("tax collection");
            CHECK(finance.getTotalRevenue() >= 0);
        }
    }
}