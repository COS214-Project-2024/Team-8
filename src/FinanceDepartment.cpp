#include <exception>
#include <vector>
#include <iostream>
using namespace std;

#include "FinanceDepartment.h"
#include "ResidentialTaxationSystem.h"
#include "BudgetAllocationSystem.h"
#include "CommercialTaxationSystem.h"
#include "CommercialBuilding.h"
#include "Citizen.h"

FinanceDepartment::FinanceDepartment()
    : residentialTaxation(new ResidentialTaxationSystem()),
      businessTaxation(new CommercialTaxationSystem()),
      budgetAllocation(new BudgetAllocationSystem()),
      incomeTaxRate(0.0),
      propertyTaxRate(0.0),
      businessTaxRate(0.0),
      salesTaxRate(0.0),
      totalBusinessSales(0.0),
      totalBusinessProfits(0.0),
      totalResidentsIncomes(0.0),
      availableFunds(0.0) {}

FinanceDepartment::FinanceDepartment(
    std::vector<Citizen *> residentsList,
    std::vector<CommercialBuilding *> commercialBuildingsList
)
    : residentsList(std::move(residentsList)),               
      commercialBuildingsList(std::move(commercialBuildingsList)), 
      residentialTaxation(new ResidentialTaxationSystem()), 
      businessTaxation(new CommercialTaxationSystem()),
      budgetAllocation(new BudgetAllocationSystem()),
      incomeTaxRate(0.0),      
      propertyTaxRate(0.0),
      businessTaxRate(0.0),
      salesTaxRate(0.0),
      totalBusinessSales(0.0),
      totalBusinessProfits(0.0),
      totalResidentsIncomes(0.0),
      availableFunds(0.0){}

FinanceDepartment::~FinanceDepartment()
{
    delete residentialTaxation;
    delete businessTaxation;
    delete budgetAllocation;

    for (Citizen *resident : residentsList)
    {
        delete resident;
    }

    for (CommercialBuilding *building : commercialBuildingsList)
    {
        delete building;
    }

    residentsList.clear();
    commercialBuildingsList.clear();
}
void FinanceDepartment::setCommercialTaxRates(double businessTaxRate, double salesTaxRate)
{
    this->businessTaxRate = businessTaxRate;
    this->salesTaxRate = salesTaxRate;
    cout << "💼 Setting Commercial Tax Rates..." << endl;
    cout << "   - Business Tax Rate updated to: " << businessTaxRate * 100 << "%" << endl;
    cout << "   - Sales Tax Rate updated to: " << salesTaxRate * 100 << "%" << endl;
}

void FinanceDepartment::setResidentialTaxRates(double incomeTaxRate, double propertyTaxRate)
{
    this->incomeTaxRate = incomeTaxRate;
    this->propertyTaxRate = propertyTaxRate;
    cout << "🏠 Setting Residential Tax Rates..." << endl;
    cout << "   - Income Tax Rate updated to: " << incomeTaxRate * 100 << "%" << endl;
    cout << "   - Property Tax Rate updated to: " << propertyTaxRate * 100 << "%" << endl;
}

void FinanceDepartment::delegateRequestForCollectionOfTaxes()
{
    for (Citizen *resident : residentsList)
    {
        if (resident)
        {
            double incomeTax = residentialTaxation->collectIncomeTaxes(incomeTaxRate, resident->getSalary());
            double propertyTax = residentialTaxation->collectPropertyTaxes(propertyTaxRate, resident->getSalary());

            availableFunds += incomeTax;
            availableFunds += propertyTax;

            resident->setBalance(resident->getBalance() - (incomeTax + propertyTax));
        }
    }
    for (CommercialBuilding *building : commercialBuildingsList)
    {
        if (building)
        {
            double businessTaxc = businessTaxation->collectBusinessTaxes(businessTaxRate, building->getProfit());
            double salesTax = businessTaxation->collectSalesTaxes(salesTaxRate, building->getSales());

            availableFunds += businessTaxc;
            availableFunds += salesTax;

            building->setBalance(building->getBalance() - (businessTaxc + salesTax));
        }
    }
}

double FinanceDepartment::delegateRequestForAllocationOfUtilitiesFunds()
{
    double totalUtilitiesFunds = 0.0;
    totalUtilitiesFunds += budgetAllocation->allocatePowerPlantFunds(availableFunds);
    totalUtilitiesFunds += budgetAllocation->allocateWaterTowerFunds(availableFunds);
    totalUtilitiesFunds += budgetAllocation->allocateWastePlantFunds(availableFunds);
    totalUtilitiesFunds += budgetAllocation->allocateSewagePipeFunds(availableFunds);
    return totalUtilitiesFunds;
}

double FinanceDepartment::delegateRequestForAllocationOfTransportInfrastructureFunds()
{
    double totalTransportInfrastructureFunds = 0.0;
    totalTransportInfrastructureFunds += budgetAllocation->allocateRoadsFunds(availableFunds);
    totalTransportInfrastructureFunds += budgetAllocation->allocateAirportsFunds(availableFunds);
    totalTransportInfrastructureFunds += budgetAllocation->allocateTrainStationsFunds(availableFunds);
    return totalTransportInfrastructureFunds;
}
double FinanceDepartment::delegateRequestForAllocationOfPublicServiceBuildingsFunds()
{
    double totalPublicServiceBuildingsFunds = 0.0;
    totalPublicServiceBuildingsFunds += budgetAllocation->allocateMedicalCenterFunds(availableFunds);
    totalPublicServiceBuildingsFunds += budgetAllocation->allocateSchoolFunds(availableFunds);
    totalPublicServiceBuildingsFunds += budgetAllocation->allocatePoliceStationFunds(availableFunds);
    return totalPublicServiceBuildingsFunds;
}

double FinanceDepartment::delegateRequestForAllocationOfLandmarkBuildingsFunds()
{
    double totalLandmarkBuildingsFunds = 0.0;
    totalLandmarkBuildingsFunds += budgetAllocation->allocateParkFunds(availableFunds);
    totalLandmarkBuildingsFunds += budgetAllocation->allocateMonumentFunds(availableFunds);
    totalLandmarkBuildingsFunds += budgetAllocation->allocateCulturalCenterFunds(availableFunds);
    return totalLandmarkBuildingsFunds;
}

double FinanceDepartment::calculateTotalResidentsIncome()
{
    double totalIncome = 0.0;

    for (Citizen *resident : residentsList)
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
    double totalProfit = 0.0;
    for (CommercialBuilding *building : commercialBuildingsList)
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
    double totalSale = 0.0;
    for (CommercialBuilding *building : commercialBuildingsList)
    {
        if (building)
        {
            totalSale += building->getSales();
        }
    }
    return totalSale;
}

void FinanceDepartment::addResidents(Citizen *resident)
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