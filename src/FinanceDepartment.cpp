#include <exception>
#include <vector>
using namespace std;

#include "FinanceDepartment.h"
#include "ResidentialTaxationSystem.h"
#include "BudgetAllocationSystem.h"

void FinanceDepartment::setCommercialTaxRates(float aBusinessTaxRate, float aSalesTaxRate) {
	cout<<"finance section changed"<<endl;
}

void FinanceDepartment::setResidentialTaxRates(float aIncomeTaxRate, float aPropertyTaxRate) {
	throw "Not yet implemented";
}

void FinanceDepartment::handleRequestForIncomeTaxCollection() {
	throw "Not yet implemented";
}

void FinanceDepartment::handleRequestForPropertyTaxCollection() {
	throw "Not yet implemented";
}

void FinanceDepartment::handleRequestForBusinessTaxCollection() {
	throw "Not yet implemented";
}

void FinanceDepartment::handleRequestForSalesTaxCollection() {
	throw "Not yet implemented";
}

float FinanceDepartment::handleRequestForUtilitiesFundsAllocation(float aRequiredExpenditure) {
	throw "Not yet implemented";
}

float FinanceDepartment::handleRequestForTransportFundsAllocation(float aRequiredExpenditure) {
	throw "Not yet implemented";
}

float FinanceDepartment::handleRequestForHealthcareFundsAllocation(float aRequiredExpenditure) {
	throw "Not yet implemented";
}

float FinanceDepartment::handleRequestForEducationFundsAllocation(float aRequiredExpenditure) {
	throw "Not yet implemented";
}

float FinanceDepartment::handleRequestForRecreationFundsAllocation(float aRequiredExpenditure) {
	throw "Not yet implemented";
}

float FinanceDepartment::calculateTotalRevenue(float aRequiredExpenditure) {
	throw "Not yet implemented";
}

