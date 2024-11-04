#include "BudgetAllocationSystem.h"
#include <iostream>

BudgetAllocationSystem::BudgetAllocationSystem() {}

// Public Service Buildings
double BudgetAllocationSystem::allocateMedicalCenterFunds(double availableFunds) {
    std::cout << "🏥 Medical Center: ";
    return availableFunds * 0.20; // 20% for Medical Center
}

double BudgetAllocationSystem::allocateSchoolFunds(double availableFunds) {
    std::cout << "📚 School: ";
    return availableFunds * 0.10; // 10% for School
}

double BudgetAllocationSystem::allocatePoliceStationFunds(double availableFunds) {
    std::cout << "🚔 Police Station: ";
    return availableFunds * 0.10; // 10% for Police Station
}

// Utilities
double BudgetAllocationSystem::allocatePowerPlantFunds(double availableFunds) {
    std::cout << "⚡ Power Plant: ";
    return availableFunds * 0.15; // 15% for Power Plant
}

double BudgetAllocationSystem::allocateWaterTowerFunds(double availableFunds) {
    std::cout << "🚰 Water Tower: ";
    return availableFunds * 0.10; // 10% for Water Tower
}

double BudgetAllocationSystem::allocateWastePlantFunds(double availableFunds) {
    std::cout << "♻️ Waste Plant: ";
    return availableFunds * 0.05; // 5% for Waste Plant
}

double BudgetAllocationSystem::allocateSewagePipeFunds(double availableFunds) {
    std::cout << "🚽 Sewage Pipe: ";
    return availableFunds * 0.05; // 5% for Sewage Pipe
}

// Transport Infrastructure
double BudgetAllocationSystem::allocateRoadsFunds(double availableFunds) {
    std::cout << "🛣️ Roads: ";
    return availableFunds * 0.10; // 10% for Roads
}

double BudgetAllocationSystem::allocateAirportsFunds(double availableFunds) {
    std::cout << "✈️ Airports: ";
    return availableFunds * 0.05; // 5% for Airports
}

double BudgetAllocationSystem::allocateTrainStationsFunds(double availableFunds) {
    std::cout << "🚆 Train Stations: ";
    return availableFunds * 0.05; // 5% for Train Stations
}

// Landmark Buildings
double BudgetAllocationSystem::allocateParkFunds(double availableFunds) {
    std::cout << "🌳 Park: ";
    return availableFunds * 0.05; // 5% for Park
}

double BudgetAllocationSystem::allocateMonumentFunds(double availableFunds) {
    std::cout << "⛲ Monument: ";
    return availableFunds * 0.025; // 2.5% for Monument
}

double BudgetAllocationSystem::allocateCulturalCenterFunds(double availableFunds) {
    std::cout << "🎭 Cultural Center: ";
    return availableFunds * 0.025; // 2.5% for Cultural Center
}