#include <exception>
using namespace std;
#include "FinanceDepartment.h"
#include "Government.h"
#include "Citizen.h"
#include "Policies.h"
#include "Buildings.h"
#include <iostream>
#include <iomanip>
#include <iostream>
using namespace std;

void Government::attach(Citizen *citizen)
{
}
void Government::detach(Citizen *citizen)
{
}

void Government::notify()
{
}
Government::Government(FinanceDepartment *financeDepartment)
    : financeDepartment(financeDepartment),
      citizenList(nullptr),
      successor(nullptr) {}
void Government::requestCollectionOfTaxes()
{

    cout << "💰 Collecting taxes from residents (Income and Property Taxes) and businesses (Business and Sales Taxes)" << endl;
    financeDepartment->delegateRequestForCollectionOfTaxes();
    cout << "✅ Tax collection processed!" << endl;
}

void Government::requestAllocationOfPublicServiceBuildingsFunds()
{
    double totalPublicServiceBuildingsFunds = 0.0;
    totalPublicServiceBuildingsFunds = financeDepartment->delegateRequestForAllocationOfPublicServiceBuildingsFunds();
    std::cout << "🏛️ Public Service Buildings Funds Allocated: R"
              << totalPublicServiceBuildingsFunds << std::endl;
}

void Government::requestAllocationOfUtilitiesFunds()
{
    double totalUtilitiesFunds = 0.0;
    totalUtilitiesFunds = financeDepartment->delegateRequestForAllocationOfUtilitiesFunds();
    std::cout << "💧 Utilities Funds Allocated: R"
              << totalUtilitiesFunds << std::endl;
}

void Government::requestAllocationOfTransportInfrastructureFunds()
{
    double totalTransportInfrastructureFunds = 0.0;
    totalTransportInfrastructureFunds = financeDepartment->delegateRequestForAllocationOfTransportInfrastructureFunds();
    std::cout << "🚆 Transport Infrastructure Funds Allocated: R"
              << totalTransportInfrastructureFunds << std::endl;
}

void Government::requestAllocationOfLandmarkBuildingsFunds()
{
    double totalLandmarkBuildingsFunds = 0.0;
    totalLandmarkBuildingsFunds = financeDepartment->delegateRequestForAllocationOfLandmarkBuildingsFunds();
    std::cout << "🏰 Landmark Buildings Funds Allocated: R"
              << totalLandmarkBuildingsFunds << std::endl;
}
