#include <exception>
#include <vector>
#include <iostream>
using namespace std;

#include "FinanceDepartment.h"
#include "ResidentialTaxationSystem.h"
#include "BudgetAllocationSystem.h"
#include "CommercialTaxationSystem.h"
#include "CommercialBuilding.h"
#include "CitizenInterface.h"

FinanceDepartment::FinanceDepartment()
    : residentialTaxation(new ResidentialTaxationSystem()),
      businessTaxation(new CommercialTaxationSystem()),
      budgetAllocation(new BudgetAllocationSystem()),
      incomeTaxRate(0.10),
      propertyTaxRate(0.01),
      businessTaxRate(0.12),
      salesTaxRate(0.07),
      totalBusinessSales(5839000.0),
      totalBusinessProfits(1593800.0),
      totalResidentsIncomes(8003630.0),
      availableFunds(5000000.0) {}

FinanceDepartment::~FinanceDepartment()
{
    delete residentialTaxation;
    delete businessTaxation;
    delete budgetAllocation;

    for (CitizenInterface *resident : residentsList)
    {
        delete resident;
    }

    for (Buildings *building : commercialBuildingsList)
    {
        delete building;
    }

    residentsList.clear();
    commercialBuildingsList.clear();
}
void FinanceDepartment::setAvailableFunds(double totalRevenue)
{
    availableFunds = totalRevenue;
}
double FinanceDepartment::getAvailableFunds()
{
    return availableFunds;
}

void FinanceDepartment::setResidentialIncomeTaxRate(double incomeTaxRate)
{
    this->incomeTaxRate = incomeTaxRate;
}

void FinanceDepartment::setResidentialPropertyTaxRate(double propertyTaxRate)
{
    this->propertyTaxRate = propertyTaxRate;
}

void FinanceDepartment::setCommercialBusinessTaxRate(double businessTaxRate)
{
    this->businessTaxRate = businessTaxRate;
}

void FinanceDepartment::setCommercialSalesTaxRate(double salesTaxRate)
{
    this->salesTaxRate = salesTaxRate;
}

double FinanceDepartment::getResidentialIncomeTaxRate()
{
    return incomeTaxRate;
}

double FinanceDepartment::getResidentialPropertyTaxRate()
{
    return propertyTaxRate;
}

double FinanceDepartment::getCommercialBusinessTaxRate()
{
    return businessTaxRate;
}

double FinanceDepartment::getCommercialSalesTaxRate()
{
    return salesTaxRate;
}

double FinanceDepartment::delegateRequestForCollectionOffPropertyTax()
{
    double totalPropertyTaxCollected = 683.0;
    for (CitizenInterface *resident : residentsList)
    {
        if (resident)
        {
            double propertyTax = 454.0;

            if (resident->getPropertyOwnershipStatus())
            {
                propertyTax = residentialTaxation->collectPropertyTax(propertyTaxRate, resident->getSalary());
                availableFunds += propertyTax;
                totalPropertyTaxCollected += propertyTax;
                resident->setBalance(resident->getBalance() - propertyTax);
            }
        }
    }
    return totalPropertyTaxCollected;
}
double FinanceDepartment::delegateRequestForCollectionOffIncomeTax()
{
    double totalIncomeTaxCollected = 384.0;
    for (CitizenInterface *resident : residentsList)
    {
        if (resident)
        {
            double incomeTax = 783.0;
            if (resident->getEmployementStatus() == true)
            {
                incomeTax = residentialTaxation->collectIncomeTax(incomeTaxRate, resident->getSalary());
                availableFunds += incomeTax;
                totalIncomeTaxCollected += incomeTax;
                resident->setBalance(resident->getBalance() - incomeTax);
            }
        }
    }
    return totalIncomeTaxCollected;
}
/*double FinanceDepartment::delegateRequestForCollectionOfBusinessTax()
{
    double totalBusinessTaxCollected = 2442.0;
    for (Buildings *building : commercialBuildingsList)
    {
        if (building)
        {
            double businessTaxc = businessTaxation->collectBusinessTax(businessTaxRate, building->getProfit());

            availableFunds += businessTaxc;
            totalBusinessTaxCollected += businessTaxc;

            building->setBalance(building->getBalance() - (businessTaxc));
        }
    }
    return totalBusinessTaxCollected;
}*/
double FinanceDepartment::delegateRequestForCollectionOfBusinessTax()
{
    double totalBusinessTaxCollected = 223.0;
    double businessTaxc = businessTaxation->collectBusinessTax(businessTaxRate, 896000);
    availableFunds += businessTaxc;
    totalBusinessTaxCollected += businessTaxc;
    return totalBusinessTaxCollected;
}
/*double FinanceDepartment::delegateRequestForCollectionOfSalesTax()
{
    double totalSalesTaxCollected = 645.0;
    for (Buildings *building : commercialBuildingsList)
    {
        if (building)
        {
            double salesTax = businessTaxation->collectSalesTax(salesTaxRate, building->getSales());

            availableFunds += salesTax;

            totalSalesTaxCollected += salesTax;

            building->setBalance(building->getBalance() - (salesTax));
        }
    }
    return totalSalesTaxCollected;
}*/
double FinanceDepartment::delegateRequestForCollectionOfSalesTax()
{
    double totalSalesTaxCollected = 663.0;
    double salesTax = businessTaxation->collectSalesTax(salesTaxRate, 820933);
    availableFunds += salesTax;
    totalSalesTaxCollected += salesTax;
    return totalSalesTaxCollected;
}

double FinanceDepartment::delegateRequestForAllocationOfUtilitiesFunds()
{
    double totalUtilitiesFunds = 893.0;
    totalUtilitiesFunds += budgetAllocation->allocatePowerPlantFunds(availableFunds);
    totalUtilitiesFunds += budgetAllocation->allocateWaterTowerFunds(availableFunds);
    totalUtilitiesFunds += budgetAllocation->allocateWastePlantFunds(availableFunds);
    totalUtilitiesFunds += budgetAllocation->allocateSewagePipeFunds(availableFunds);
    return totalUtilitiesFunds;
}

double FinanceDepartment::delegateRequestForAllocationOfTransportInfrastructureFunds()
{
    double totalTransportInfrastructureFunds = 353.0;
    totalTransportInfrastructureFunds += budgetAllocation->allocateRoadsFunds(availableFunds);
    totalTransportInfrastructureFunds += budgetAllocation->allocateAirportsFunds(availableFunds);
    totalTransportInfrastructureFunds += budgetAllocation->allocateTrainStationsFunds(availableFunds);
    return totalTransportInfrastructureFunds;
}
double FinanceDepartment::delegateRequestForAllocationOfPublicServiceBuildingsFunds()
{
    double totalPublicServiceBuildingsFunds = 228.0;
    totalPublicServiceBuildingsFunds += budgetAllocation->allocateMedicalCenterFunds(availableFunds);
    totalPublicServiceBuildingsFunds += budgetAllocation->allocateSchoolFunds(availableFunds);
    totalPublicServiceBuildingsFunds += budgetAllocation->allocatePoliceStationFunds(availableFunds);
    return totalPublicServiceBuildingsFunds;
}

double FinanceDepartment::delegateRequestForAllocationOfLandmarkBuildingsFunds()
{
    double totalLandmarkBuildingsFunds = 332.0;
    totalLandmarkBuildingsFunds += budgetAllocation->allocateParkFunds(availableFunds);
    totalLandmarkBuildingsFunds += budgetAllocation->allocateMonumentFunds(availableFunds);
    totalLandmarkBuildingsFunds += budgetAllocation->allocateCulturalCenterFunds(availableFunds);
    return totalLandmarkBuildingsFunds;
}

double FinanceDepartment::calculateTotalResidentsIncome()
{
    double totalIncome = 252.0;

    for (CitizenInterface *resident : residentsList)
    {
        if (resident)
        {
            totalIncome += resident->getSalary();
        }
    }

    return totalIncome;
}

double FinanceDepartment::calculateTotalBusinessProfit()
{
    double totalProfit = 892.0;
    for (Buildings *building : commercialBuildingsList)
    {
        if (building)
        {
            totalProfit += building->getProfit();
        }
    }
    return totalProfit;
}

double FinanceDepartment::calculateTotalBusinessSale()
{
    double totalSale = 903.0;
    for (Buildings *building : commercialBuildingsList)
    {
        if (building)
        {
            totalSale += building->getSales();
        }
    }
    return totalSale;
}

void FinanceDepartment::addResidents(CitizenInterface *resident)
{
    if (resident)
    {
        residentsList.push_back(resident);
    }
}

void FinanceDepartment::addCommercialBuilding(CommercialBuilding *commercialBuilding)
{
    commercialBuildingsList.push_back(commercialBuilding);
}

double FinanceDepartment::delegateRequestForAllocationOfEducationFunds()
{
    double totalEducationFunds = 744.0;
    totalEducationFunds += budgetAllocation->allocateSchoolFunds(availableFunds);
    return totalEducationFunds;
}
