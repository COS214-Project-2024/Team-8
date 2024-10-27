
using namespace std;
#ifndef __ResidentialTaxationSystem_h__
#define __ResidentialTaxationSystem_h__


class ResidentialTaxationSystem
{
	public:
		ResidentialTaxationSystem(){}
		double collectIncomeTax(double incomeTaxRate, double residentsIncome);
		double collectPropertyTax(double propertyTaxRate, double residentsIncome);
};

#endif
