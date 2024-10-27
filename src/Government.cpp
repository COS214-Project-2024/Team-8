#include <exception>
using namespace std;
#include "FinanceDepartment.h"
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
    financeDepartment->delegateRequestForCollectionOfTaxes();
    cout  << "✅ Tax collection processed!"  << endl;
}

