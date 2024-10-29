#include <exception>
#include <string>

using namespace std;

#ifndef __Government_h__
#define __Government_h__

class Citizen;
class Policies;
class FinanceDepartment; // USED BY FACADE DESIGN PATTERN


class Government
{
    private:
        Citizen* citizenList;
        Government* successor;
        FinanceDepartment* financeDepartment;// USED BY FACADE DESIGN PATTERN
        
    public:
        Government(FinanceDepartment* financeDepartment);// USED BY FACADE DESIGN PATTERN
        void attach(Citizen* citizen);
        void detach(Citizen* citizen);
        void notify();
        virtual void handleRequest() = 0;
        void requestCollectionOfTaxes();// USED BY FACADE DESIGN PATTERN
        void requestAllocationOfPublicServiceBuildingsFunds();// USED BY FACADE DESIGN PATTERN
        void requestAllocationOfUtilitiesFunds();// USED BY FACADE DESIGN PATTERN
        void requestAllocationOfTransportInfrastructureFunds();// USED BY FACADE DESIGN PATTERN
        void requestAllocationOfLandmarkBuildingsFunds();// USED BY FACADE DESIGN PATTERN
        
};

#endif
