#include <exception>
#include <vector>
using namespace std;

#ifndef __ResidentialTaxationSystem_h__
#define __ResidentialTaxationSystem_h__

class ResidentialTaxationSystem;

class ResidentialTaxationSystem
{
	private: float _incomeTaxRate;
	private: float _propertyTaxRate;

	public: void setResidentialTaxRates(float aIncomeTaxRate, float aPropertyTaxRate);

	public: void collectIncomeTax(vector<> aResidentsIncomes, vector<> aTotalIncomeTaxes);

	public: void collectPropertyTax(vector<> aResidentsIncomes);
};

#endif
