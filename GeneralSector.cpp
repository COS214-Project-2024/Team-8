#include <exception>
#include <iostream>
using namespace std;

#include "GeneralSector.h"

void GeneralSector::handleRequest(std::string requestDetails) {
    std::cout << "[COR] General Sector handling request: " << requestDetails << std::endl;
}