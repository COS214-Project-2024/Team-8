#include <exception>
#include <vector>
using namespace std;

#ifndef __CommercialTaxationSystem_h__
#define __CommercialTaxationSystem_h__

class CommercialTaxationSystem;

class CommercialTaxationSystem
{
	private: float _businessTaxRate;
	private: float _salesTaxRate;

	public: void setCommercialTaxRates(float aBusinessTaxRate, float aSalesTaxRate);

	public: void collectBusinessTax(vector<> aBusinessProfits, vector<> aTotalBusinessTaxes);

	public: void collectSalesTax(vector<> aBusinessProfits);
};

#endif
