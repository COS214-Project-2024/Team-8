#include <exception>
using namespace std;

#ifndef __BudgetAllocationSystem_h__
#define __BudgetAllocationSystem_h__

class BudgetAllocationSystem;

class BudgetAllocationSystem
{
	private: float _availableBudget;

	public: float allocateUtilitiesFunds(float aRequiredExpenditure);

	public: float allocateTransportFunds(float aRequiredExpenditure);

	public: float allocateHealthcareFunds(float aRequiredExpenditure);

	public: float allocateEducationFunds(float aRequiredExpenditure);

	public: float allocateSecurityServiceFunds(float aRequiredExpenditure);

	public: float allocateRecreationFunds(float aRequiredExpenditure);

	public: void setAvailableBudget(float aAvailableBudget);
};

#endif
