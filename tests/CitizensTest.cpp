#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../Citizen.h"
#include "../EmployedCitizen.h"
#include "../PropertyOwner.h"


TEST_CASE("Citizen Initialization") {
    // Create a Citizen with given parameters
    Citizen citizen("Alice", 5000.0f, 30, 80.0f, nullptr, true, true);
    
    // Test initial values
    CHECK(citizen.getName() == "Alice");
    CHECK(citizen.getSalary() == 5000.0f);
    CHECK(citizen.getAge() == 30);
    CHECK(citizen.evaluateHappiness() == doctest::Approx(85.0f).epsilon(0.01)); // Based on example happiness calculation
    CHECK(citizen.getSatisfaction() == doctest::Approx(80.0f).epsilon(0.01));
}

TEST_CASE("Employment Status and Salary Adjustment") {
    Citizen citizen("Bob", 3500.0f, 25, 60.0f, nullptr, false, false);

    SUBCASE("Setting Employment Status") {
        CHECK_FALSE(citizen.getEmployementStatus());
        citizen.setEmploymentStatus(true);
        CHECK(citizen.getEmployementStatus() == true);
    }

    SUBCASE("Setting Salary") {
        CHECK(citizen.getSalary() == 3500.0f);
        citizen.setSalary(4500.0f);
        CHECK(citizen.getSalary() == 4500.0f);
    }
}

TEST_CASE("Property Ownership") {
    Citizen citizen("Charlie", 4000.0f, 40, 70.0f, nullptr, true, false);

    CHECK_FALSE(citizen.getPropertyOwnershipStatus());

    citizen.setPropertyOwnership(true);
    CHECK(citizen.getPropertyOwnershipStatus() == true);
}

TEST_CASE("Satisfaction Adjustment and Limits") {
    Citizen citizen("Dana", 3000.0f, 20, 50.0f);

    SUBCASE("Increase Satisfaction") {
        citizen.adjustCitizenSatisfaction(20.0f);
        CHECK(citizen.getSatisfaction() == doctest::Approx(70.0f).epsilon(0.01));
    }

    SUBCASE("Decrease Satisfaction") {
        citizen.adjustCitizenSatisfaction(-30.0f);
        CHECK(citizen.getSatisfaction() == doctest::Approx(20.0f).epsilon(0.01));
    }

    SUBCASE("Upper Limit on Satisfaction") {
        citizen.adjustCitizenSatisfaction(100.0f);
        CHECK(citizen.getSatisfaction() == 100.0f); // Should be capped at 100
    }

    SUBCASE("Lower Limit on Satisfaction") {
        citizen.adjustCitizenSatisfaction(-100.0f);
        CHECK(citizen.getSatisfaction() == 0.0f); // Should be capped at 0
    }
}

TEST_CASE("Request Public Service") {
    Citizen citizen("Eve", 3200.0f, 22, 65.0f);
    citizen.requestPublicService("Healthcare", 10.0f);
    
    // Expect satisfaction to increase
    CHECK(citizen.getSatisfaction() == doctest::Approx(75.0f).epsilon(0.01));
}

TEST_CASE("Attend Event") {
    Citizen citizen("Frank", 2900.0f, 29, 45.0f);
    citizen.attendEvent("Festival", 15.0f);

    // Expect satisfaction to increase
    CHECK(citizen.getSatisfaction() == doctest::Approx(60.0f).epsilon(0.01));
}

TEST_CASE("Evaluate Happiness") {
    Citizen citizen("Grace", 2000.0f, 35, 50.0f);
    float happiness = citizen.evaluateHappiness();

    // Calculate expected happiness based on satisfaction and salary contribution
    CHECK(happiness == doctest::Approx(52.0f).epsilon(0.01));
}

TEST_CASE("Simulate Employment and Promotion") {
    // Create a unique pointer for the Citizen instance
    auto citizenPtr = std::make_unique<Citizen>("Hank", 4000.0f, 28, 55.0f);
    
    // Create an EmployedCitizen using the unique pointer
    EmployedCitizen employedCitizen(std::move(citizenPtr));

    SUBCASE("Employment Status and Salary After Employment") {
        // Assuming getEmployed is a method that sets employment status and adjusts salary
        employedCitizen.getEmployed(new Buildings()); // Use appropriate arguments
        CHECK(employedCitizen.getEmployementStatus() == true);
        CHECK(employedCitizen.getSalary() > 4000.0f); // Salary should reflect increase from employment
    }

    SUBCASE("Promotion Effect on Salary") {
        employedCitizen.jobPromotion(10.0f); // Assuming this method increases salary by 10%
        CHECK(employedCitizen.getSalary() == doctest::Approx(4400.0f).epsilon(0.01));
    }
}
TEST_CASE("Simulate Property Ownership and Residence Management") {

    auto citizenPtr = std::make_unique<Citizen>("Hank", 4000.0f, 28, 55.0f);

    PropertyOwner propertyOwner(std::move(citizenPtr));
    
    Buildings* newBuilding = new Buildings(); 

    SUBCASE("Move into Residence") {
        propertyOwner.moveIntoResidence(newBuilding);
        CHECK(propertyOwner.getPropertyOwnershipStatus() == true); 
        CHECK(propertyOwner.getSatisfaction() == 65.0f); 
    }

    SUBCASE("Upgrade Residence") {
        propertyOwner.moveIntoResidence(newBuilding);
        float initialSatisfaction = propertyOwner.getSatisfaction();
        // Upgrade with a satisfaction boost of 15
        propertyOwner.upgradeResidence(15.0f); 

        // Check if satisfaction reflects the increase after upgrading
        CHECK(propertyOwner.getSatisfaction() == doctest::Approx(initialSatisfaction + 15.0f).epsilon(0.01));
    }
    
    // Clean up dynamically allocated memory
    delete newBuilding;
}
