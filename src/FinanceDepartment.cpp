#include <exception>
#include <vector>
#include <iostream>
using namespace std;

#include "FinanceDepartment.h"
#include "ResidentialTaxationSystem.h"
#include "BudgetAllocationSystem.h"
#include "CommercialTaxationSystem.h"
 

void FinanceDepartment::setCommercialTaxRates(float businessTaxRate, float salesTaxRate) {
    this->businessTaxRate = businessTaxRate;
    this->salesTaxRate = salesTaxRate;
    cout << "💼 Setting Commercial Tax Rates..." << endl;
    cout << "   - Business Tax Rate updated to: " << businessTaxRate * 100 << "%" << endl;
    cout << "   - Sales Tax Rate updated to: " << salesTaxRate * 100 << "%" << endl;
}

void FinanceDepartment::setResidentialTaxRates(float incomeTaxRate, float propertyTaxRate) {
    this->incomeTaxRate = incomeTaxRate;
    this->propertyTaxRate = propertyTaxRate;
    cout << "🏠 Setting Residential Tax Rates..." << endl;
    cout << "   - Income Tax Rate updated to: " << incomeTaxRate * 100 << "%" << endl;
    cout << "   - Property Tax Rate updated to: " << propertyTaxRate * 100 << "%" << endl;
}

void FinanceDepartment:: delegateRequestForCollectionOfTaxes(){
	totalRevenue+=residentialTaxation->collectIncomeTaxes(incomeTaxRate,totalResidentsIncomes);
	totalRevenue+=residentialTaxation->collectPropertyTaxes(propertyTaxRate,totalResidentsIncomes);
	totalRevenue+=businessTaxation->collectBusinessTaxes(businessTaxRate,totalbusinessProfits);
	totalRevenue+=businessTaxation->collectSalesTaxes(salesTaxRate,totalbusinessProfits);
}

void FinanceDepartment:: delegateRequestOfAllocationOfFunds(float requiredExpenUtilities, float requiredExpenTransport, 
                                          float requiredExpenHealth, float requiredExpenEducation, 
                                          float requiredExpenSecurity, float requiredExpenRecreation){
									
}
