#include <exception>
#include <vector>
using namespace std;

#ifndef __FinanceDepartment_h__
#define __FinanceDepartment_h__

class ResidentialTaxationSystem;
class CommercialTaxationSystem;
class BudgetAllocationSystem;
class CitizenType;
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
    std::vector<Citizen*> residentsList,
    std::vector<CommercialBuilding *> commercialBuildingsList
    );
    ~FinanceDepartment();

    void setAvailableFunds(double totalRevenue);
    void setResidentialIncomeTaxRate(double incomeTaxRate);
    void setResidentialPropertyTaxRate(double propertyTaxRate);
    void setCommercialBusinessTaxRate(double businessTaxRate);
    void setCommercialSalesTaxRate(double salesTaxRate);

    double getResidentialIncomeTaxRate();
    double getResidentialPropertyTaxRate();
    double getCommercialBusinessTaxRate();
    double getCommercialSalesTaxRate();
    double getAvailableFunds();

    double delegateRequestForCollectionOffPropertyTax();
    double delegateRequestForCollectionOffIncomeTax();
    double delegateRequestForCollectionOfBusinessTax();
    double delegateRequestForCollectionOfSalesTax();

    double delegateRequestForAllocationOfPublicServiceBuildingsFunds();
    double delegateRequestForAllocationOfUtilitiesFunds();
    double delegateRequestForAllocationOfTransportInfrastructureFunds();
    double delegateRequestForAllocationOfLandmarkBuildingsFunds(); //SYNONYMOUS WITH Recreation


    double calculateTotalResidentsIncome();
    double calculateTotalBusinessProfit();
    double calculateTotalBusinessSale();
    void addResidents(Citizen *resident);
    void addCommercialBuilding(CommercialBuilding *commercialBuilding);
};

#endif
