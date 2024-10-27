
using namespace std;
#ifndef __ResidentialTaxationSystem_h__
#define __ResidentialTaxationSystem_h__


class ResidentialTaxationSystem
{
	public:

		float collectIncomeTaxes(float businessTaxRate,float totalbusinessProfits);
		float collectPropertyTaxes(float salesTaxRate,float totalbusinessProfits);
};

#endif
