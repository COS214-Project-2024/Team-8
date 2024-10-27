using namespace std;

#ifndef __CommercialTaxationSystem_h__
#define __CommercialTaxationSystem_h__


class CommercialTaxationSystem
{
	public:
		CommercialTaxationSystem(){}
		double collectBusinessTax(double businessTaxRate,double businessProfit);
		double collectSalesTax(double salesTaxRate,double businessProfit);
};

#endif
