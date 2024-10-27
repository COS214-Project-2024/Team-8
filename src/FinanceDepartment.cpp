#include <exception>
#include <vector>
#include <iostream>
using namespace std;

#include "FinanceDepartment.h"
#include "ResidentialTaxationSystem.h"
#include "BudgetAllocationSystem.h"
#include "CommercialTaxationSystem.h"

void FinanceDepartment::setCommercialTaxRates(float businessTaxRate, float salesTaxRate)
{
    this->businessTaxRate = businessTaxRate;
    this->salesTaxRate = salesTaxRate;
    cout << "💼 Setting Commercial Tax Rates..." << endl;
    cout << "   - Business Tax Rate updated to: " << businessTaxRate * 100 << "%" << endl;
    cout << "   - Sales Tax Rate updated to: " << salesTaxRate * 100 << "%" << endl;
}

void FinanceDepartment::setResidentialTaxRates(float incomeTaxRate, float propertyTaxRate)
{
    this->incomeTaxRate = incomeTaxRate;
    this->propertyTaxRate = propertyTaxRate;
    cout << "🏠 Setting Residential Tax Rates..." << endl;
    cout << "   - Income Tax Rate updated to: " << incomeTaxRate * 100 << "%" << endl;
    cout << "   - Property Tax Rate updated to: " << propertyTaxRate * 100 << "%" << endl;
}

void FinanceDepartment::delegateRequestForCollectionOfTaxes()
{
    availableFunds += residentialTaxation->collectIncomeTaxes(incomeTaxRate, totalResidentsIncomes);
    availableFunds += residentialTaxation->collectPropertyTaxes(propertyTaxRate, totalResidentsIncomes);
    availableFunds += businessTaxation->collectBusinessTaxes(businessTaxRate, totalbusinessProfits);
    availableFunds += businessTaxation->collectSalesTaxes(salesTaxRate, totalbusinessProfits);
}

float FinanceDepartment::delegateRequestForAllocationOfUtilitiesFunds()
{
    float totalUtilitiesFunds = 0.0;
    totalUtilitiesFunds += budgetAllocation->allocatePowerPlantFunds(availableFunds);
    totalUtilitiesFunds += budgetAllocation->allocateWaterTowerFunds(availableFunds);
    totalUtilitiesFunds += budgetAllocation->allocateWastePlantFunds(availableFunds);
    totalUtilitiesFunds += budgetAllocation->allocateSewagePipeFunds(availableFunds);
    return totalUtilitiesFunds;
}

float FinanceDepartment::delegateRequestForAllocationOfTransportInfrastructureFunds()
{
    float totalTransportInfrastructureFunds = 0.0;
    totalTransportInfrastructureFunds += budgetAllocation->allocateRoadsFunds(availableFunds);
    totalTransportInfrastructureFunds += budgetAllocation->allocateAirportsFunds(availableFunds);
    totalTransportInfrastructureFunds += budgetAllocation->allocateTrainStationsFunds(availableFunds);
    return totalTransportInfrastructureFunds;
}
float FinanceDepartment::delegateRequestForAllocationOfPublicServiceBuildingsFunds()
{
    float totalPublicServiceBuildingsFunds = 0.0;
    totalPublicServiceBuildingsFunds += budgetAllocation->allocateMedicalCenterFunds(availableFunds);
    totalPublicServiceBuildingsFunds += budgetAllocation->allocateSchoolFunds(availableFunds);
    totalPublicServiceBuildingsFunds += budgetAllocation->allocatePoliceStationFunds(availableFunds);
    return totalPublicServiceBuildingsFunds;
}

float FinanceDepartment::delegateRequestForAllocationOfLandmarkBuildingsFunds()
{
    float totalLandmarkBuildingsFunds = 0.0;
    totalLandmarkBuildingsFunds += budgetAllocation->allocateParkFunds(availableFunds);
    totalLandmarkBuildingsFunds += budgetAllocation->allocateMonumentFunds(availableFunds);
    totalLandmarkBuildingsFunds += budgetAllocation->allocateCulturalCenterFunds(availableFunds);
    return totalLandmarkBuildingsFunds;
}