
using namespace std;
#ifndef __ResidentialTaxationSystem_h__
#define __ResidentialTaxationSystem_h__


class ResidentialTaxationSystem
{
	public:
		ResidentialTaxationSystem(){}
		double collectIncomeTaxes(double businessTaxRate,double totalbusinessProfits);
		double collectPropertyTaxes(double salesTaxRate,double totalbusinessProfits);
};

#endif
