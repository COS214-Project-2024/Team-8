#include <exception>
#include <iostream>
using namespace std;

#include "GeneralSector.h"

void GeneralSector::handleRequest(std::string requestDetails) {
    if (requestDetails.find("GENERAL") != std::string::npos) {
        std::cout << "[COR] General Sector handling request: " << requestDetails << std::endl;
    } else if (getSuccessor()) {
        getSuccessor()->handleRequest(requestDetails);
    } else {
        // Handle unmatched requests at the end of the chain
        std::cout << "[COR] End of chain reached. No handler found for: " << requestDetails << std::endl;
    }
}