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
        Government(FinanceDepartment* financeDepartment);
        void attach(Citizen* citizen);
        void detach(Citizen* citizen);
        void notify();
        virtual void handleRequest() = 0;
        void requestCollectionOfTaxes();
        void requestAllocationOfPublicServiceBuildingsFunds();
        void requestAllocationOfUtilitiesFunds();
        void requestAllocationOfTransportInfrastructureFunds();
        void requestAllocationOfLandmarkBuildingsFunds();
        
};

#endif
