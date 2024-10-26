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
	Buildings* industrialBuidlingsList;
    float incomeTaxRate;                        
    float propertyTaxRate;               
    float businessTaxRate;            
    float salesTaxRate;  
 	float totalbusinessProfits; 
 	float totalResidentsIncomes;  
	float totalRevenue;                                           

public:
    void setResidentialTaxRates(float incomeTaxRate, float propertyTaxRate);
    void setCommercialTaxRates(float businessTaxRate, float salesTaxRate);
	void delegateRequestForCollectionOfTaxes();
	void delegateRequestOfAllocationOfFunds(float requiredExpenUtilities, float requiredExpenTransport, 
                                          float requiredExpenHealth, float requiredExpenEducation, 
                                          float requiredExpenSecurity, float requiredExpenRecreation);
};

#endif
