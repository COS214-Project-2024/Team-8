#include <exception>
using namespace std;

#include "Government.h"
#include "Citizen.h"
#include "Policies.h"
#include "Buildings.h"
#include <iostream>
#include <iomanip>
using namespace std;

void Government:: attach(Citizen* citizen){

}
void Government:: detach(Citizen* citizen){

}

void Government:: notify(){

}
void Government::requestCollectionOfTaxes() {

    cout << "💰 Collecting taxes from residents (Income and Property Taxes) and businesses (Business and Sales Taxes)" << endl;
    financeDepartment->handleRequestForCollectionOfTaxes();
    cout  << "✅ Tax collection processed!"  << endl;
}

void Government::requestAllocationOfFunds(float requiredExpenUtilities, float requiredExpenTransport, 
                                          float requiredExpenHealth, float requiredExpenEducation, 
                                          float requiredExpenSecurity, float requiredExpenRecreation) {


    cout  << "💼 Allocating Government Funds..."  << endl;

    cout << "   Utilities:       "  << "R" << fixed << setprecision(2) << requiredExpenUtilities  << endl;
    cout << "   Transport:       "  << "R" << fixed << setprecision(2) << requiredExpenTransport  << endl;
    cout << "   Healthcare:      "  << "R" << fixed << setprecision(2) << requiredExpenHealth  << endl;
    cout << "   Education:       "  << "R" << fixed << setprecision(2) << requiredExpenEducation  << endl;
    cout << "   Security:        "  << "R" << fixed << setprecision(2) << requiredExpenSecurity  << endl;
    cout << "   Recreation:      "  << "R" << fixed << setprecision(2) << requiredExpenRecreation  << endl;

    financeDepartment->handleRequestForFundsAllocation(requiredExpenUtilities, requiredExpenTransport, 
                                                       requiredExpenHealth, requiredExpenEducation, 
                                                       requiredExpenSecurity, requiredExpenRecreation);

    cout  << "✅ Funds allocated successfully!"  << endl;
}