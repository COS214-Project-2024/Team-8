#include <exception>
#include <iostream>
using namespace std;

#include "UtilitiesSector.h"

void UtilitiesSector::handleRequest(std::string requestDetails) {
    if (requestDetails.find("UTILITIES") != std::string::npos) {
        std::cout << "[COR] Utilities Sector handling request: " << requestDetails << std::endl;
    } else if (getSuccessor()) {
        getSuccessor()->handleRequest(requestDetails);
    }
}