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
    double taxBreakRate;
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
    void setTaxBreakRate(double taxBreakRate);
    void setResidentialIncomeTaxRate(double incomeTaxRate);
    void setResidentialPropertyTaxRate(double propertyTaxRate);
    void setCommercialBusinessTaxRate(double businessTaxRate);
    void setCommercialSalesTaxRate(double salesTaxRate);
    double getTaxBreakRate(double taxBreakRate);
    double getResidentialIncomeTaxRate();
    double getResidentialPropertyTaxRate();
    double getCommercialBusinessTaxRate();
    double getCommercialSalesTaxRate();
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
