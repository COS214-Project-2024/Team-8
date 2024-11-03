#include <exception>
#include <iostream>
using namespace std;

#include "FinanceSector.h"

void FinanceSector::handleRequest(std::string requestDetails) {
    if (requestDetails.find("FINANCE") != std::string::npos) {
        std::cout << "[COR] Finance Sector handling request: " << requestDetails << std::endl;
    } else if (getSuccessor()) {
        getSuccessor()->handleRequest(requestDetails);
    }
}