#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "BudgetAllocationSystem.h"
#include "CommercialTaxationSystem.h"
#include "ResidentialTaxationSystem.h"
#include "FinanceDepartment.h"
#include "Government.h"
#include "Shop.h"
#include "Mall.h"
#include "Office.h"
#include "Citizen.h"

TEST_CASE("Testing BudgetAllocationSystem") {
    BudgetAllocationSystem* budgetSystem = new BudgetAllocationSystem();
    double availableFunds = 1000.0;

    SUBCASE("Medical Center Fund Allocation") {
        double medicalFunds = budgetSystem->allocateMedicalCenterFunds(availableFunds);
        CHECK(medicalFunds > 0);
        CHECK(medicalFunds <= availableFunds);
    }

    SUBCASE("School Fund Allocation") {
        double schoolFunds = budgetSystem->allocateSchoolFunds(availableFunds);
        CHECK(schoolFunds > 0);
        CHECK(schoolFunds <= availableFunds);
    }

    SUBCASE("Police Station Fund Allocation") {
        double policeFunds = budgetSystem->allocatePoliceStationFunds(availableFunds);
        CHECK(policeFunds > 0);
        CHECK(policeFunds <= availableFunds);
    }

    delete budgetSystem;
}

TEST_CASE("Testing CommercialTaxationSystem") {
    CommercialTaxationSystem* taxSystem = new CommercialTaxationSystem();
    
    SUBCASE("Business Tax Collection") {
        double businessTaxRate = 0.15;
        double businessProfit = 500000.0;
        double businessTax = taxSystem->collectBusinessTax(businessTaxRate, businessProfit);
        CHECK(businessTax == doctest::Approx(75000.0)); // 15% of 500000
    }

    SUBCASE("Sales Tax Collection") {
        double salesTaxRate = 0.10;
        double salesAmount = 500000.0;
        double salesTax = taxSystem->collectSalesTax(salesTaxRate, salesAmount);
        CHECK(salesTax == doctest::Approx(50000.0)); // 10% of 500000
    }

    delete taxSystem;
}

TEST_CASE("Testing ResidentialTaxationSystem") {
    ResidentialTaxationSystem* taxSystem = new ResidentialTaxationSystem();
    
    SUBCASE("Income Tax Collection") {
        double incomeTaxRate = 0.18;
        double income = 350000.0;
        double incomeTax = taxSystem->collectIncomeTax(incomeTaxRate, income);
        CHECK(incomeTax == doctest::Approx(63000.0)); // 18% of 350000
    }

    SUBCASE("Property Tax Collection") {
        double propertyTaxRate = 0.05;
        double propertyValue = 350000.0;
        double propertyTax = taxSystem->collectPropertyTax(propertyTaxRate, propertyValue);
        CHECK(propertyTax == doctest::Approx(17500.0)); // 5% of 350000
    }

    delete taxSystem;
}

TEST_CASE("Testing FinanceDepartment") {
    FinanceDepartment* financeDept = new FinanceDepartment();
    
    SUBCASE("Setting Tax Rates") {
        financeDept->setResidentialIncomeTaxRate(0.10);
        financeDept->setResidentialPropertyTaxRate(0.012);
        financeDept->setCommercialBusinessTaxRate(0.25);
        financeDept->setCommercialSalesTaxRate(0.08);
        
        CHECK(financeDept->getResidentialIncomeTaxRate() == doctest::Approx(0.10));
        CHECK(financeDept->getResidentialPropertyTaxRate() == doctest::Approx(0.012));
        CHECK(financeDept->getCommercialBusinessTaxRate() == doctest::Approx(0.25));
        CHECK(financeDept->getCommercialSalesTaxRate() == doctest::Approx(0.08));
    }

    /*SUBCASE("Adding Commercial Buildings") {
        CommercialBuilding* shop = new Shop("TestShop", 100, 50, 2000.0, 100, 30, 1000.0f, 500.0f, 10);
        CommercialBuilding* mall = new Mall("TestMall", 200, 100, 5000.0, 150, 50, 3000.0f, 1500.0f, 50);
        
        financeDept->addCommercialBuilding(shop);
        financeDept->addCommercialBuilding(mall);
        
        CHECK(financeDept->getNumberOfCommercialBuildings() == 2);
    }

    SUBCASE("Adding Residents") {
        for(int i = 0; i < 5; i++) {
            CitizenInterface* citizen = new Citizen();
            financeDept->addResidents(citizen);
        }
        
        CHECK(financeDept->getNumberOfResidents() == 5);
    }*/

    SUBCASE("Fund Allocation Requests") {
        financeDept->setAvailableFunds(1000000.0);
        
        double publicServiceFunds = financeDept->delegateRequestForAllocationOfPublicServiceBuildingsFunds();
        double landmarkFunds = financeDept->delegateRequestForAllocationOfLandmarkBuildingsFunds();
        double transportFunds = financeDept->delegateRequestForAllocationOfTransportInfrastructureFunds();
        double utilitiesFunds = financeDept->delegateRequestForAllocationOfUtilitiesFunds();
        
        CHECK(publicServiceFunds > 0);
        CHECK(landmarkFunds > 0);
        CHECK(transportFunds > 0);
        CHECK(utilitiesFunds > 0);
        
        double totalAllocation = publicServiceFunds + landmarkFunds + transportFunds + utilitiesFunds;
        CHECK(totalAllocation <= 1000000.0);
    }

    delete financeDept;
}

TEST_CASE("Testing Government") {
    FinanceDepartment* financeDept = new FinanceDepartment();
    Government* government = new Government(financeDept);
    
    /*SUBCASE("Government Initialization") {
        CHECK(government != nullptr);
        CHECK(government->getFinanceDepartment() != nullptr);
    }

    SUBCASE("Citizen Attachment") {
        for(int i = 0; i < 10; i++) {
            CitizenInterface* citizen = new Citizen();
            government->attach(citizen);
        }
        CHECK(government->getNumberOfCitizens() == 10);
    }*/

    SUBCASE("Budget Setting and Getting") {
        double testBudget = 40000000.00;
        government->setBudget(testBudget);
        CHECK(government->getBudget() == doctest::Approx(testBudget));
    }

    SUBCASE("Tax Collection") {
        financeDept->setResidentialIncomeTaxRate(0.10);
        financeDept->setResidentialPropertyTaxRate(0.012);
        financeDept->setCommercialBusinessTaxRate(0.25);
        financeDept->setCommercialSalesTaxRate(0.08);
        financeDept->setAvailableFunds(40000000.00);

        double propertyTaxCollected = government->requestCollectionOfPropertyTax();
        double incomeTaxCollected = government->requestCollectionOfIncomeTax();
        double businessTaxCollected = government->requestCollectionOfBusinessTax();
        double salesTaxCollected = government->requestCollectionOfSalesTax();

        CHECK(propertyTaxCollected >= 0);
        CHECK(incomeTaxCollected >= 0);
        CHECK(businessTaxCollected >= 0);
        CHECK(salesTaxCollected >= 0);
    }

    SUBCASE("Fund Allocation") {
        government->setBudget(40000000.00);

        double utilitiesFunds = government->requestAllocationOfUtilitiesFunds();
        double publicServiceFunds = government->requestAllocationOfPublicServiceBuildingsFunds();
        double transportFunds = government->requestAllocationOfTransportFunds();
        double educationFunds = government->requestAllocationOfEducationFunds();
        double recreationFunds = government->requestAllocationOfRecreationFunds();

        CHECK(utilitiesFunds >= 0);
        CHECK(publicServiceFunds >= 0);
        CHECK(transportFunds >= 0);
        CHECK(educationFunds >= 0);
        CHECK(recreationFunds >= 0);

        double totalAllocation = utilitiesFunds + publicServiceFunds + transportFunds + 
                               educationFunds + recreationFunds;
        CHECK(totalAllocation <= government->getBudget());
    }

    SUBCASE("Integrated Tax Collection and Fund Allocation") {
        government->setBudget(40000000.00);
        financeDept->setResidentialIncomeTaxRate(0.10);
        financeDept->setResidentialPropertyTaxRate(0.012);
        financeDept->setCommercialBusinessTaxRate(0.25);
        financeDept->setCommercialSalesTaxRate(0.08);

        for(int i = 0; i < 5; i++) {
            CitizenInterface* citizen = new Citizen();
            government->attach(citizen);
        }

        double totalTaxes = government->requestCollectionOfPropertyTax() +
                           government->requestCollectionOfIncomeTax() +
                           government->requestCollectionOfBusinessTax() +
                           government->requestCollectionOfSalesTax();

        double totalAllocations = government->requestAllocationOfUtilitiesFunds() +
                                government->requestAllocationOfPublicServiceBuildingsFunds() +
                                government->requestAllocationOfTransportFunds() +
                                government->requestAllocationOfEducationFunds() +
                                government->requestAllocationOfRecreationFunds();

        CHECK(totalTaxes >= 0);
        CHECK(totalAllocations >= 0);
        CHECK(totalAllocations <= government->getBudget());
    }

    delete government;
    delete financeDept;
}
