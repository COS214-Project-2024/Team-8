#include <exception>
#include <vector>
using namespace std;

#ifndef __FinanceDepartment_h__
#define __FinanceDepartment_h__

// #include "ResidentialTaxationSystem.h"
// #include "BudgetAllocationSystem.h"

class ResidentialTaxationSystem;
class BudgetAllocationSystem;
class FinanceDepartment;

class FinanceDepartment
{
	private: ResidentialTaxationSystem* _residentialTaxation;
	private: CommericalTaxationSystem* _commercialTaxation;
	private: BudgetAllocationSystem* _budgetAllocation;
	private: vector<> _residentsIncomes;
	private: vector<> _businessProfits;
	private: float _totalRevenue;
	private: vector<> _totalIncomeTaxes;
	private: vector<> _totalPropertyTaxes;
	private: vector<> _totalBusinessTaxes;
	private: vector<> _totalSalesTaxes;

	public: void setCommercialTaxRates(float aBusinessTaxRate, float aSalesTaxRate);

	public: void setResidentialTaxRates(float aIncomeTaxRate, float aPropertyTaxRate);

	public: void handleRequestForIncomeTaxCollection();

	public: void handleRequestForPropertyTaxCollection();

	public: void handleRequestForBusinessTaxCollection();

	public: void handleRequestForSalesTaxCollection();

	public: float handleRequestForUtilitiesFundsAllocation(float aRequiredExpenditure);

	public: float handleRequestForTransportFundsAllocation(float aRequiredExpenditure);

	public: float handleRequestForHealthcareFundsAllocation(float aRequiredExpenditure);

	public: float handleRequestForEducationFundsAllocation(float aRequiredExpenditure);

	public: float handleRequestForRecreationFundsAllocation(float aRequiredExpenditure);

	public: float calculateTotalRevenue(float aRequiredExpenditure);
};

#endif
