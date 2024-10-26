using namespace std;

#ifndef __CommercialTaxationSystem_h__
#define __CommercialTaxationSystem_h__


class CommercialTaxationSystem
{
	public:

		float collectBusinessTaxes(float businessTaxRate,float totalbusinessProfits);
		float collectSalesTaxes(float salesTaxRate,float totalbusinessProfits);
};

#endif
