#include <exception>
#include <string>

using namespace std;

#ifndef __Government_h__
#define __Government_h__

// Forward declarations to prevent circular dependency issues
class Citizen;
class Policies;
class Buildings;

class Government
{
    private:
        Citizen* _citizenList;
        Government* _successor; // Changed type to pointer to allow for inheritance and chaining

    public:
        Government* _unnamed_Government_;
        Citizen* _requestee;
        Policies* _unnamed_Policies_;
        Buildings* _unnamed_Buildings_;

        // Attach and detach methods for managing citizens (using Citizen* instead of string)
        void attach(Citizen* citizen);
        void detach(Citizen* citizen);

        // Notify method to inform observers or related components
        void notify();

        // Pure virtual method, making Government an abstract base class
        virtual void handleRequest() = 0;

        // Tax collection methods
        void requestCollectionOfPropertyTax();
        void requestCollectionOfIncomeTax();
        void requestCollectionOfBusinessTax();
        void requestCollectionOfSalesTax();

        // Fund allocation methods returning float for allocated amounts
        float requestAllocationOfUtilitiesFunds();
        float requestAllocationOfHealthcareFunds();
        float requestAllocationOfTransportFunds();
        float requestAllocationOfEducationFunds();
        float requestAllocationOfRecreationFunds();
};

#endif
