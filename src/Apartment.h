#include <string>
using namespace std;

#ifndef APARTMENT_H
#define APARTMENT_H

class ResourceMediator;
class Citizen;
#include "ResidentialBuilding.h";

class Apartment : ResidentialBuilding {

// Attributes
    private: 
        State* state;
        int capacity;
        std::unique_ptr<Citizen> listOfCitizens; //using a smart pointer to avoid memory leaks
        int powerReq;
        int waterReq;
        double maintenanceCost;
        int sewageCost;
        int waste;
		// added attribute
        string buildingType;
        string buildingName;

    public: 
		Apartment(string bName,int pReq, int wReq, double mCost, int sCost, int waste, int capacity);
        void requestState();
        int getCapacity();
        std::unique_ptr<Citizen> getListOfResidents();
        double getMaiantenanceCost();
        int getPowerReq();
        int getWaterReq();
        int getSewageCost();
        int getWasteCost();
		//added functions
		void setState();
        int getCapacity();
        string getName();
    ~Apartment();

};

#endif
