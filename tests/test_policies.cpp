#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Government.h"
#include "Policies.h"
#include "EconomicPolicies.h"
#include "PublicServicesPolicies.h"
#include "Citizen.h"

class MockGovernment : public Government {
public:
    bool policiesExecuted = false;
    void executePolicies() override { policiesExecuted = true; }
};

TEST_CASE("Testing Policy Classes") {
    SUBCASE("Test EconomicPolicies") {
        MockGovernment govt;
        EconomicPolicies econPolicies(&govt);
        Citizen testCitizen;
        PublicServicesPolicies psPolicies(&govt);
        
        econPolicies.citizen = &testCitizen;
        econPolicies.psPolicies = &psPolicies;
        
        SUBCASE("Economic Policy Execution") {
            econPolicies.execute();
            CHECK(govt.policiesExecuted);
        }
        
        SUBCASE("Economic Policy References") {
            CHECK(econPolicies.citizen != nullptr);
            CHECK(econPolicies.psPolicies != nullptr);
        }
    }
    
    SUBCASE("Test PublicServicesPolicies") {
        MockGovernment govt;
        PublicServicesPolicies psPolicies(&govt);
        Citizen testCitizen;
        EconomicPolicies econPolicies(&govt);
        
        psPolicies.citizen = &testCitizen;
        psPolicies.economicPolicies = &econPolicies;
        
        SUBCASE("Public Services Policy Execution") {
            psPolicies.execute();
            CHECK(govt.policiesExecuted);
        }
        
        SUBCASE("Public Services Policy References") {
            CHECK(psPolicies.citizen != nullptr);
            CHECK(psPolicies.economicPolicies != nullptr);
        }
    }
    
    SUBCASE("Test Policy Base Class") {
        MockGovernment govt;
        PublicServicesPolicies psPolicies(&govt);
        
        // Test that base class execute() calls derived executePolicy()
        Command* command = &psPolicies;
        command->execute();
        CHECK(govt.policiesExecuted);
    }
}