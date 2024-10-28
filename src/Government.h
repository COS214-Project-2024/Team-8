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
        FinanceDepartment* financeDepartment;//NEW 
        
    public:
        Government(FinanceDepartment* financeDepartment);//NEW 
        void attach(Citizen* citizen);
        void detach(Citizen* citizen);
        void notify();
        virtual void handleRequest() = 0;
        void requestCollectionOfTaxes();//NEW 
        void requestAllocationOfPublicServiceBuildingsFunds();//NEW 
        void requestAllocationOfUtilitiesFunds();//NEW 
        void requestAllocationOfTransportInfrastructureFunds();//NEW 
        void requestAllocationOfLandmarkBuildingsFunds();//NEW 
        
};

#endif
