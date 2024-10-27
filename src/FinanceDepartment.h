#include <exception>
#include <vector>
using namespace std;

#ifndef __FinanceDepartment_h__
#define __FinanceDepartment_h__

class ResidentialTaxationSystem;
class CommercialTaxationSystem;
class BudgetAllocationSystem;
class Citizen;
class Policies;
class CommercialBuilding;

class FinanceDepartment
{
private:
    ResidentialTaxationSystem *residentialTaxation;
    CommercialTaxationSystem *businessTaxation;
    BudgetAllocationSystem *budgetAllocation;
    std::vector<Citizen *> residentsList;
    std::vector<CommercialBuilding *> commercialBuildingsList;
    double incomeTaxRate;
    double propertyTaxRate;
    double businessTaxRate;
    double salesTaxRate;
    double totalBusinessSales;
    double totalBusinessProfits;
    double totalResidentsIncomes;
    double availableFunds;

public:
    FinanceDepartment();
    FinanceDepartment::FinanceDepartment(
    std::vector<Citizen *> residentsList,
    std::vector<CommercialBuilding *> commercialBuildingsList
    );
    ~FinanceDepartment();
    void setResidentialTaxRates(double incomeTaxRate, double propertyTaxRate);
    void setCommercialTaxRates(double businessTaxRate, double salesTaxRate);
    void delegateRequestForCollectionOfTaxes();
    double delegateRequestForAllocationOfPublicServiceBuildingsFunds();
    double delegateRequestForAllocationOfUtilitiesFunds();
    double delegateRequestForAllocationOfTransportInfrastructureFunds();
    double delegateRequestForAllocationOfLandmarkBuildingsFunds();
    double calculateTotalResidentsIncome();
    double calculateTotalBusinessProfit();
    double calculateTotalBusinessSale();
    void addResidents(Citizen *resident);
    void addCommercialBuilding(CommercialBuilding *commercialBuilding);
};

#endif
