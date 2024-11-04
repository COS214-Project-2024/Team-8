#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>
#include <iostream>
#include <vector>
#include <memory>

// Include all necessary headers
#include "ResidentialTaxationSystem.h"
#include "CommercialTaxationSystem.h"
#include "BudgetAllocationSystem.h"
#include "FinanceDepartment.h"
#include "Government.h"
#include "Citizen.h"
#include "CommercialBuilding.h"

// ResidentialTaxationSystem Tests
TEST_CASE("ResidentialTaxationSystem") {
    ResidentialTaxationSystem taxSystem;

    SUBCASE("Income Tax Collection") {
        // Redirect cout to capture output
        std::streambuf* old_cout = std::cout.rdbuf();
        std::stringstream ss;
        std::cout.rdbuf(ss.rdbuf());

        double taxRate = 0.2;  // 20% tax rate
        double income = 50000.0;
        double incomeTax = taxSystem.collectIncomeTax(taxRate, income);

        // Restore cout
        std::cout.rdbuf(old_cout);

        CHECK_EQ(incomeTax, doctest::Approx(10000.0));
        CHECK(ss.str().find("Income Tax Collected: R 10000") != std::string::npos);
    }

    SUBCASE("Property Tax Collection") {
        // Redirect cout to capture output
        std::streambuf* old_cout = std::cout.rdbuf();
        std::stringstream ss;
        std::cout.rdbuf(ss.rdbuf());

        double taxRate = 0.1;  // 10% tax rate
        double income = 50000.0;
        double propertyTax = taxSystem.collectPropertyTax(taxRate, income);

        // Restore cout
        std::cout.rdbuf(old_cout);

        CHECK_EQ(propertyTax, doctest::Approx(5000.0));
        CHECK(ss.str().find("Property Tax Collected: R 5000") != std::string::npos);
    }
}

// CommercialTaxationSystem Tests
TEST_CASE("CommercialTaxationSystem") {
    CommercialTaxationSystem taxSystem;

    SUBCASE("Business Tax Collection") {
        // Redirect cout to capture output
        std::streambuf* old_cout = std::cout.rdbuf();
        std::stringstream ss;
        std::cout.rdbuf(ss.rdbuf());

        double taxRate = 0.25;  // 25% tax rate
        double businessProfit = 100000.0;
        double businessTax = taxSystem.collectBusinessTax(taxRate, businessProfit);

        // Restore cout
        std::cout.rdbuf(old_cout);

        CHECK_EQ(businessTax, doctest::Approx(25000.0));
        CHECK(ss.str().find("Total Business Taxes Collected: R 25000") != std::string::npos);
    }

    SUBCASE("Sales Tax Collection") {
        // Redirect cout to capture output
        std::streambuf* old_cout = std::cout.rdbuf();
        std::stringstream ss;
        std::cout.rdbuf(ss.rdbuf());

        double taxRate = 0.15;  // 15% tax rate
        double businessProfit = 80000.0;
        double salesTax = taxSystem.collectSalesTax(taxRate, businessProfit);

        // Restore cout
        std::cout.rdbuf(old_cout);

        CHECK_EQ(salesTax, doctest::Approx(12000.0));
        CHECK(ss.str().find("Total Sales Taxes Collected: R 12000") != std::string::npos);
    }
}

// BudgetAllocationSystem Tests
TEST_CASE("BudgetAllocationSystem") {
    // Note: Since BudgetAllocationSystem methods are not in a class, 
    // we'll test the global functions directly

    SUBCASE("Medical Center Funds Allocation") {
        double availableFunds = 1000000.0;
        double medicalCenterFunds = allocateMedicalCenterFunds(availableFunds);

        CHECK_EQ(medicalCenterFunds, doctest::Approx(200000.0)); // 20% of available funds
    }

    SUBCASE("School Funds Allocation") {
        double availableFunds = 1000000.0;
        double schoolFunds = allocateSchoolFunds(availableFunds);

        CHECK_EQ(schoolFunds, doctest::Approx(100000.0)); // 10% of available funds
    }

    // Add similar tests for other allocation functions
    SUBCASE("Police Station Funds Allocation") {
        double availableFunds = 1000000.0;
        double policeStationFunds = allocatePoliceStationFunds(availableFunds);

        CHECK_EQ(policeStationFunds, doctest::Approx(100000.0)); // 10% of available funds
    }
}

// FinanceDepartment Tests (Mock some dependencies)
TEST_CASE("FinanceDepartment") {
    // Mocking minimal dependencies
    class MockCitizen : public CitizenInterface {
    public:
        std::string citizenType() override { return "Employed"; }
        double getSalary() override { return 50000.0; }
        double getBalance() override { return 100000.0; }
        void setBalance(double bal) override { balance = bal; }
    private:
        double balance = 100000.0;
    };

    class MockCommercialBuilding : public CommercialBuilding {
    public:
        double getProfit() override { return 200000.0; }
        double getSales() override { return 500000.0; }
        double getBalance() override { return 300000.0; }
        void setBalance(double bal) override { balance = bal; }
    private:
        double balance = 300000.0;
    };

    SUBCASE("Tax Collection and Fund Allocation") {
        std::vector<CitizenInterface*> residents = { new MockCitizen() };
        std::vector<CommercialBuilding*> buildings = { new MockCommercialBuilding() };

        FinanceDepartment financeDept(residents, buildings);

        // Set tax rates
        financeDept.setResidentialIncomeTaxRate(0.2);   // 20%
        financeDept.setResidentialPropertyTaxRate(0.1); // 10%
        financeDept.setCommercialBusinessTaxRate(0.25); // 25%
        financeDept.setCommercialSalesTaxRate(0.15);    // 15%

        // Set initial available funds
        financeDept.setAvailableFunds(1000000.0);

        // Test tax collection methods
        SUBCASE("Income Tax Collection") {
            double collectedTax = financeDept.delegateRequestForCollectionOffIncomeTax();
            CHECK_EQ(collectedTax, doctest::Approx(10000.0)); // 20% of 50000.0
        }

        SUBCASE("Business Tax Collection") {
            double collectedTax = financeDept.delegateRequestForCollectionOfBusinessTax();
            CHECK_EQ(collectedTax, doctest::Approx(50000.0)); // 25% of 200000.0
        }

        // Clean up memory (in a real scenario, use smart pointers)
        for(auto resident : residents) delete resident;
        for(auto building : buildings) delete building;
    }
}

// Government Tests (Minimal mock setup)
TEST_CASE("Government") {
    // Mock FinanceDepartment for testing
    class MockFinanceDepartment : public FinanceDepartment {
    public:
        double getAvailableFunds() override { return 1000000.0; }
        double delegateRequestForCollectionOffIncomeTax() override { return 50000.0; }
        // Implement other mocked methods as needed
    };

    SUBCASE("Budget and Revenue Management") {
        MockFinanceDepartment mockFinanceDept;
        Government govt(&mockFinanceDept);

        // Test budget and revenue methods
        govt.setBudget(500000.0);
        CHECK_EQ(govt.getBudget(), 500000.0);

        govt.setTotalRevenue(1000000.0);
        CHECK_EQ(govt.getTotalRevenue(), 1000000.0);
    }
}
