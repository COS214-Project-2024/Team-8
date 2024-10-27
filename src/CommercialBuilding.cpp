#include "CommercialBuilding.h"
#include <iostream>

// Implement the requestState function
void CommercialBuilding::requestState() {
    // Implementation for requesting the state of the building
    std::cout << "Requesting state for the commercial building." << std::endl;
}

// Implement the getMaintenanceCost function
double CommercialBuilding::getMaintenanceCost() {
    // Placeholder implementation; return a sample maintenance cost
    return 1000.0; // Change this value based on your logic
}

// Implement the getPowerReq function
int CommercialBuilding::getPowerReq() {
    // Placeholder implementation; return a sample power requirement
    return 150; // Change this value based on your logic
}

// Implement the getSewageCost function
int CommercialBuilding::getSewageCost() {
    // Placeholder implementation; return a sample sewage cost
    return 200; // Change this value based on your logic
}

// Implement the getWaterCost function
int CommercialBuilding::getWaterCost() {
    // Placeholder implementation; return a sample water cost
    return 300; // Change this value based on your logic
}

// Implement the getWasteCost function
int CommercialBuilding::getWasteCost() {
    // Placeholder implementation; return a sample waste cost
    return 150; // Change this value based on your logic
}

// Implement the getSales function
double CommercialBuilding::getSales() {
    return sales; // Return the current sales value
}

// Implement the getProfit function
double CommercialBuilding::getProfit() {
    return profit; // Return the current profit value
}

// Implement the getBalance function
double CommercialBuilding::getBalance() {
    return balance; // Return the current balance value
}

// Implement the setSales function
void CommercialBuilding::setSales(double sale) {
    sales = sale; // Set the sales value
}

// Implement the setProfit function
void CommercialBuilding::setProfit(double profit) {
    this->profit = profit; // Set the profit value
}

// Implement the setBalance function
void CommercialBuilding::setBalance(double balance) {
    this->balance = balance; // Set the balance value
}
