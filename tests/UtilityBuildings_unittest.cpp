#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Buildings.h"
#include <iostream>

#include "UtilityPowerPlant.h"
#include "Utility.h"
#include "SewageSystems.h"
#include "WaterSupply.h"
#include "WasteFactory.h"
#include "House.h"
#include "Apartment.h"
#include "TownHouse.h"
#include "Factories.h"
#include "PowerPlant.h"
#include "Warehouse.h"
#include "Shop.h"
#include "Mall.h"
#include "Office.h"
#include "School.h"
#include "PoliceStation.h"
#include "MedicalCenter.h"
#include "Park.h"
#include "Monument.h"
#include "CulturalCenter.h"

TEST_CASE("Testing Buildings and Utility's"){

    Utility* plant = new UtilityPowerPlant(1000);
	plant->setMaxWatts(1000*1.75);
    Utility* water = new WaterSupply(1000);
	water->setMaxGallons(1000 * 0.8);
    Utility* waste = new WasteManagement(1000);
	waste->setProcessCapacity(1000 * 0.8); 
    Utility* sewage = new SewageSystems(1000);
	sewage->setmaxWaste(1000 * 2.5);

    House* house = new House("Dream House", 5, 5, 5.0, 5, 5, 5);

    Apartment* apart = new Apartment("Dream Apartment", 5, 5, 5.0, 5, 5, 5);
    TownHouse* tHouse = new TownHouse("Dream House", 5, 5, 5.0, 5, 5, 5);
    //Shop(string bName, int pReq, int wReq, double mCost, int sCost, int waste, float sales, float profit, int emp);
    PowerPlant* power = new PowerPlant("Dream House", 5, 5, 5.0, 5, 5, 5);
    Warehouse* warehouse = new Warehouse("Dream House", 5, 5, 5.0, 5, 5, 5);
    Shop* shop = new Shop("Dream Shop", 5, 5, 5.0, 5, 5, 5.0, 5.0, 5);
    Mall* mall = new Mall("Dream Mall", 5, 5, 5.0, 5, 5, 5.0, 5.0, 5);
    Office* off = new Office("Dream Office", 5, 5, 5.0, 5, 5.0, 5.0, 5, 5, 5);
    School* school = new School("Dream", 5, 5, 5.0, 5, 5, 5, 5.0);
    PoliceStation* police = new PoliceStation("Dream Station", 5, 5, 5.0, 5, 5, 5, 5.0);
    MedicalCenter* medical = new MedicalCenter("Dream House", 5, 5, 5.0, 5, 5, 5, 5.0);
    Park* park = new Park("Dream Park", 5, 5, 5.0, 5, 5);
    Monument* monum = new Monument("Dream Monument", 5, 5, 5.0, 5, 5);
    CulturalCenter* cultural = new CulturalCenter("Dream Cultural Center", 5, 5, 5.0, 5, 5);




    SUBCASE("Apartment can Receive Resources"){
        plant->addBuilding(apart);
        water->addBuilding(apart);
        sewage->addBuilding(apart);
        waste->addBuilding(apart);
        bool result = apart->getPower();
        CHECK(result == true);
        result = apart->cleanSewage();
        CHECK(result == true);
        result = apart->getWater();
        CHECK(result == true);
        result = apart->cleanWaste();
        CHECK(result == true);
    }

    SUBCASE("Town House can Receive Resources"){
        plant->addBuilding(tHouse);
        water->addBuilding(tHouse);
        sewage->addBuilding(tHouse);
        waste->addBuilding(tHouse);
        bool result = tHouse->getPower();
        CHECK(result == true);
        result = tHouse->cleanSewage();
        CHECK(result == true);
        result = tHouse->getWater();
        CHECK(result == true);
        result = tHouse->cleanWaste();
        CHECK(result == true);
    }

    SUBCASE("Power House can Receive Resources"){
        plant->addBuilding(power);
        water->addBuilding(power);
        sewage->addBuilding(power);
        waste->addBuilding(power);
        bool result = power->getPower();
        CHECK(result == true);
        result = power->cleanSewage();
        CHECK(result == true);
        result = power->getWater();
        CHECK(result == true);
        result = power->cleanWaste();
        CHECK(result == true);
    }
    
    SUBCASE("Warehouse can Receive Resources"){
        plant->addBuilding(warehouse);
        water->addBuilding(warehouse);
        sewage->addBuilding(warehouse);
        waste->addBuilding(warehouse);
        bool result = warehouse->getPower();
        CHECK(result == true);
        result = warehouse->cleanSewage();
        CHECK(result == true);
        result = warehouse->getWater();
        CHECK(result == true);
        result = warehouse->cleanWaste();
        CHECK(result == true);
    }

    SUBCASE("Shop can Receive Resources"){
        plant->addBuilding(shop);
        water->addBuilding(shop);
        sewage->addBuilding(shop);
        waste->addBuilding(shop);
        bool result = shop->getPower();
        CHECK(result == true);
        result = shop->cleanSewage();
        CHECK(result == true);
        result = shop->getWater();
        CHECK(result == true);
        result = shop->cleanWaste();
        CHECK(result == true);
    }

    SUBCASE("Mall can Receive Resources"){
        plant->addBuilding(mall);
        water->addBuilding(mall);
        sewage->addBuilding(mall);
        waste->addBuilding(mall);
        bool result = mall->getPower();
        CHECK(result == true);
        result = mall->cleanSewage();
        CHECK(result == true);
        result = mall->getWater();
        CHECK(result == true);
        result = mall->cleanWaste();
        CHECK(result == true);
    }

    SUBCASE("Office can Receive Resources"){
        plant->addBuilding(off);
        water->addBuilding(off);
        sewage->addBuilding(off);
        waste->addBuilding(off);
        bool result = off->getPower();
        CHECK(result == true);
        result = off->cleanSewage();
        CHECK(result == true);
        result = off->getWater();
        CHECK(result == true);
        result = off->cleanWaste();
        CHECK(result == true);
    }

    SUBCASE("School can Receive Resources"){
        plant->addBuilding(school);
        water->addBuilding(school);
        sewage->addBuilding(school);
        waste->addBuilding(school);
        bool result = school->getPower();
        CHECK(result == true);
        result = school->cleanSewage();
        CHECK(result == true);
        result = school->getWater();
        CHECK(result == true);
        result = school->cleanWaste();
        CHECK(result == true);
    }

    SUBCASE("Police can Receive Resources"){
        plant->addBuilding(police);
        water->addBuilding(police);
        sewage->addBuilding(police);
        waste->addBuilding(police);
        bool result = police->getPower();
        CHECK(result == true);
        result = police->cleanSewage();
        CHECK(result == true);
        result = police->getWater();
        CHECK(result == true);
        result = police->cleanWaste();
        CHECK(result == true);
    }

    SUBCASE("Medical can Receive Resources"){
        plant->addBuilding(medical);
        water->addBuilding(medical);
        sewage->addBuilding(medical);
        waste->addBuilding(medical);
        bool result = medical->getPower();
        CHECK(result == true);
        result = medical->cleanSewage();
        CHECK(result == true);
        result = medical->getWater();
        CHECK(result == true);
        result = medical->cleanWaste();
        CHECK(result == true);
    }

    SUBCASE("Park can Receive Resources"){
        plant->addBuilding(park);
        water->addBuilding(park);
        sewage->addBuilding(park);
        waste->addBuilding(park);
        bool result = medical->getPower();
        CHECK(result == true);
        result = medical->cleanSewage();
        CHECK(result == true);
        result = medical->getWater();
        CHECK(result == true);
        result = medical->cleanWaste();
        CHECK(result == true);
    }

    SUBCASE("Monument can Receive Resources"){
        plant->addBuilding(park);
        water->addBuilding(park);
        sewage->addBuilding(park);
        waste->addBuilding(park);
        bool result = medical->getPower();
        CHECK(result == true);
        result = medical->cleanSewage();
        CHECK(result == true);
        result = medical->getWater();
        CHECK(result == true);
        result = medical->cleanWaste();
        CHECK(result == true);
    }

SUBCASE("Cutlural Centers can Receive Resources"){
        plant->addBuilding(park);
        water->addBuilding(park);
        sewage->addBuilding(park);
        waste->addBuilding(park);
        bool result = medical->getPower();
        CHECK(result == true);
        result = medical->cleanSewage();
        CHECK(result == true);
        result = medical->getWater();
        CHECK(result == true);
        result = medical->cleanWaste();
        CHECK(result == true);
    }
    
    delete house;
    delete apart;
    delete tHouse;
    delete power;
    delete power;
    delete warehouse;
    delete shop;
    delete mall;
    delete off;
    delete school;
    delete police;
    delete medical;
    delete park;
    delete monum;
    delete cultural;

    delete sewage;
    delete waste;
    delete water;
    delete plant;

}