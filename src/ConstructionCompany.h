#include <exception>
#include <list>
using namespace std;

#ifndef __ConstructionCompany_h__
#define __ConstructionCompany_h__

#include "Buildings.h"
#include "TownHouse.h"
#include "Apartment.h"
#include "Factories.h"
#include "PowerPlant.h"
#include "Warehouse.h"
#include "MedicalCenter.h"
#include "School.h"
#include "PoliceStation.h"
#include "Office.h"
#include "Park.h"
#include "CulturalCenter.h"
#include "Monument.h"

class Buildings;
class ConstructionCompany;

class ConstructionCompany
{
	private: 
		std::vector<House*> houses;
		std::vector<TownHouse*> townHouses;
		std::vector<Apartment*> apartments;
		std::vector<Factories*> factories;
		std::vector<PowerPlant*> powerplants;
		std::vector<Warehouse*> warehouses;
		std::vector<MedicalCenter*> medicalCenters;
		std::vector<School*> schools;
		std::vector<PoliceStation*> policeStations;
		std::vector<Office*> offices;
		std::vector<Mall*> malls;
		std::vector<Shop*> shops;
		std::vector<Park*> parks;
		std::vector<Monument*> monuments;
		std::vector<CulturalCenter*> culturalCenters;

	
	public: 
		House* constructHouse();
		TownHouse* constructTownHouse();
		Apartment* constructApartment();
		Factories* constructFactory();
		PowerPlant* constructPowerPlant();
		Warehouse* constructWarehouse();
		MedicalCenter* constructMedicalCenter();
		School* constructSchool();
		PoliceStation* constructPoliceStation();
		Office* constructOffice();
		Mall* constructMall();
		Shop* ConstructShop();
		Park* constructPark();
		Monument* constructMonument();
		CulturalCenter* constructCulturalCenter();
		
};

#endif
