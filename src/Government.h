#include <exception>
using namespace std;

#ifndef __Government_h__
#define __Government_h__

// #include "Citizen.h"
// #include "Policies.h"
// #include "Buildings.h"

class Citizen;
class Policies;
class Buildings;
class Government;

__abstract class Government
{
	private: Citizen* _citizenList;
	private: Government _successor;
	public: Government* _unnamed_Government_;
	public: Citizen* _requestee;
	public: Policies* _unnamed_Policies_;
	public: Buildings* _unnamed_Buildings_;

	public: void attach(string a:_Citizen);

	public: void detach(string a:_Citizen);

	public: void notify();

	public: virtual void handleRequest() = 0;

	public: void requestCollectionOfIPropertyTax();

	public: void requestCollectionOfIncomeTax();

	public: void requestCollectionOfIBusinessTax();

	public: float requestAllocationOfIUntilitiesFunds();

	public: float requestAllocationOfHealthcareFunds();

	public: void requestCollectionOfISalesTax();

	public: float requestAllocationOfTransportFunds();

	public: float requestAllocationOfEducationFunds();

	public: float requestAllocationOfRecreationFunds();
};

#endif
