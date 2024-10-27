

#ifndef __BudgetAllocationSystem_h__
#define __BudgetAllocationSystem_h__

class BudgetAllocationSystem
{
public:
    // Public Service Buildings
    float allocateMedicalCenterFunds(float availableFunds);
    float allocateSchoolFunds(float availableFunds);
    float allocatePoliceStationFunds(float availableFunds);

    // Utilities
    float allocatePowerPlantFunds(float availableFunds);
    float allocateWaterTowerFunds(float availableFunds);
    float allocateWastePlantFunds(float availableFunds);
    float allocateSewagePipeFunds(float availableFunds);

    // Transport Infrastructure
    float allocateRoadsFunds(float availableFunds);
    float allocateAirportsFunds(float availableFunds);
    float allocateTrainStationsFunds(float availableFunds);

    // Landmark Buildings
    float allocateParkFunds(float availableFunds);
    float allocateMonumentFunds(float availableFunds);
    float allocateCulturalCenterFunds(float availableFunds);
};

#endif
