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
class Buildings;

class FinanceDepartment {
private:
    ResidentialTaxationSystem* residentialTaxation;
    CommercialTaxationSystem* businessTaxation; 
    BudgetAllocationSystem* budgetAllocation;
	Citizen* residentsList;
	Buildings* commercialBuidlingsList;
    double incomeTaxRate;                        
    double propertyTaxRate;               
    double businessTaxRate;            
    double salesTaxRate;  
 	double totalbusinessProfits; 
 	double totalResidentsIncomes;  
	double availableFunds;                                           

public:
    void setResidentialTaxRates(double incomeTaxRate, double propertyTaxRate);
    void setCommercialTaxRates(double businessTaxRate, double salesTaxRate);
	void delegateRequestForCollectionOfTaxes();
	double delegateRequestForAllocationOfPublicServiceBuildingsFunds();
    double delegateRequestForAllocationOfUtilitiesFunds();
    double delegateRequestForAllocationOfTransportInfrastructureFunds();
    double delegateRequestForAllocationOfLandmarkBuildingsFunds();
};

#endif
