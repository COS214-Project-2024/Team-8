#include <exception>
#include <string>

using namespace std;

#ifndef __Government_h__
#define __Government_h__

class Citizen;
class Policies;
class Buildings;
class FinanceDepartment;


class Government
{
    private:
        Citizen* citizenList;
        Government* successor;
        FinanceDepartment* financeDepartment;
        
    public:
        void attach(Citizen* citizen);
        void detach(Citizen* citizen);
        void notify();
        virtual void handleRequest() = 0;
        void requestCollectionOfTaxes();
        void requestAllocationOfFunds(double requiredExpenUtilities, double requiredExpenTransport, 
                                          double requiredExpenHealth, double requiredExpenEducation, 
                                          double requiredExpenSecurity, double requiredExpenRecreation);
};

#endif
