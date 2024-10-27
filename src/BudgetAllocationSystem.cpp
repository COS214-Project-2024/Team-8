using namespace std;
#include <iostream>

#include "BudgetAllocationSystem.h"
// Public Service Buildings
float allocateMedicalCenterFunds(float availableFunds)
{
    std::cout << "🏥 Medical Center: ";
    return availableFunds * 0.20; // 20% for Medical Center
}

float allocateSchoolFunds(float availableFunds)
{
    std::cout << "📚 School: ";
    return availableFunds * 0.10; // 10% for School
}

float allocatePoliceStationFunds(float availableFunds)
{
    std::cout << "🚔 Police Station: ";
    return availableFunds * 0.10; // 10% for Police Station
}

// Utilities
float allocatePowerPlantFunds(float availableFunds)
{
    std::cout << "⚡ Power Plant: ";
    return availableFunds * 0.15; // 15% for Power Plant
}

float allocateWaterTowerFunds(float availableFunds)
{
    std::cout << "🚰 Water Tower: ";
    return availableFunds * 0.10; // 10% for Water Tower
}

float allocateWastePlantFunds(float availableFunds)
{
    std::cout << "♻️ Waste Plant: ";
    return availableFunds * 0.05; // 5% for Waste Plant
}

float allocateSewagePipeFunds(float availableFunds)
{
    std::cout << "🚽 Sewage Pipe: ";
    return availableFunds * 0.05; // 5% for Sewage Pipe
}

// Transport Infrastructure
float allocateRoadsFunds(float availableFunds)
{
    std::cout << "🛣️ Roads: ";
    return availableFunds * 0.10; // 10% for Roads
}

float allocateAirportsFunds(float availableFunds)
{
    std::cout << "✈️ Airports: ";
    return availableFunds * 0.05; // 5% for Airports
}

float allocateTrainStationsFunds(float availableFunds)
{
    std::cout << "🚆 Train Stations: ";
    return availableFunds * 0.05; // 5% for Train Stations
}

// Landmark Buildings
float allocateParkFunds(float availableFunds)
{
    std::cout << "🌳 Park: ";
    return availableFunds * 0.05; // 5% for Park
}

float allocateMonumentFunds(float availableFunds)
{
    std::cout << "⛲ Monument: ";
    return availableFunds * 0.025; // 2.5% for Monument
}

float allocateCulturalCenterFunds(float availableFunds)
{
    std::cout << "🎭 Cultural Center: ";
    return availableFunds * 0.025; // 2.5% for Cultural Center
}