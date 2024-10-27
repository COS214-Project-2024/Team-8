using namespace std;

#ifndef __CommercialTaxationSystem_h__
#define __CommercialTaxationSystem_h__


class CommercialTaxationSystem
{
	public:

		double collectBusinessTaxes(double businessTaxRate,double totalbusinessProfits);
		double collectSalesTaxes(double salesTaxRate,double totalbusinessProfits);
};

#endif
