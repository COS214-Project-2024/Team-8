#include <exception>
using namespace std;

#ifndef GOVERNMENT_H
#define GOVERNMENT_H

#include <vector>
#include <memory>
#include "Command.h"

#include "Citizen.h"
// #include "Policies.h"
// #include "Buildings.h"

class Citizen;
class Policies;
class Buildings;
class Government;

class Government
{
	private:
	 Citizen* citizenList;
 	 Government* successor;
	 Citizen* requestee;
	 vector<unique_ptr<Command>> commands;
	 double budget;
	 double totalRevenue;

	public: Government* _unnamed_Government_;
	 Citizen* _requestee;
	 Policies* _unnamed_Policies_;
	 Buildings* _unnamed_Buildings_;

 	void attach(Citizen* citizen);
 	void detach(Citizen* citizen);
 	void notify();
	void addCommand(unique_ptr<Command> command);
	void executeCommands();
	void requestCollectionOfPropertyTax();
	void requestCollectionOfIncomeTax();
	void requestCollectionOfBusinessTax();
	float requestAllocationOfUtilitiesFunds();
	float requestAllocationOfHealthcareFunds();
	void requestCollectionOfSalesTax();
	float requestAllocationOfTransportFunds();
	float requestAllocationOfEducationFunds();
	float requestAllocationOfRecreationFunds();
	void setBudget(double b);
	double getBudget();
	double getTotalRevenue();

	public: virtual void handleRequest() = 0;


};

#endif
