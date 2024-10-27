

#ifndef __BudgetAllocationSystem_h__
#define __BudgetAllocationSystem_h__

class BudgetAllocationSystem
{
public:
    // Public Service Buildings
    double allocateMedicalCenterFunds(double availableFunds);
    double allocateSchoolFunds(double availableFunds);
    double allocatePoliceStationFunds(double availableFunds);

    // Utilities
    double allocatePowerPlantFunds(double availableFunds);
    double allocateWaterTowerFunds(double availableFunds);
    double allocateWastePlantFunds(double availableFunds);
    double allocateSewagePipeFunds(double availableFunds);

    // Transport Infrastructure
    double allocateRoadsFunds(double availableFunds);
    double allocateAirportsFunds(double availableFunds);
    double allocateTrainStationsFunds(double availableFunds);

    // Landmark Buildings
    double allocateParkFunds(double availableFunds);
    double allocateMonumentFunds(double availableFunds);
    double allocateCulturalCenterFunds(double availableFunds);
};

#endif
