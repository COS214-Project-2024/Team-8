#include <exception>
using namespace std;

#include "ConstructionCompany.h"
#include "Buildings.h"
#include "ResidentialBuilding.h"
#include "House.h"
#include "Shop.h"

House* ConstructionCompany::constructHouse()
{
	House* temp = new House("house", 500,600,5600,345,500,1000);
	temp->buildPart();
	this->houses.push_back(temp);
	return temp;
}

TownHouse* ConstructionCompany::constructTownHouse()
{
	TownHouse* temp = new TownHouse("town house", 500,600,5600,345,500,1000);
	temp->buildPart();
	this->townHouses.push_back(temp);
	return temp;
}

Apartment* ConstructionCompany::constructApartment()
{
	Apartment* temp = new Apartment("apartment", 500,600,5600,345,500,1000);
	temp->buildPart();
	this->apartments.push_back(temp);
	return temp;
}

Factories* ConstructionCompany::constructFactory()
{
	Factories* temp = new Factories("factory",500,500,564.50,600,800,600);
	temp->buildPart();
	this->factories.push_back(temp);
	return temp;
}

PowerPlant* ConstructionCompany::constructPowerPlant()
{
	PowerPlant* temp = new PowerPlant("power plant",500,500,567.90,500,340,500);
	temp->buildPart();
	this->powerplants.push_back(temp);
	return temp;
}
		
Warehouse* ConstructionCompany::constructWarehouse()
{
	Warehouse* temp  = new Warehouse("warehouse",5000,5000,4550.50,600,345,500);
	temp->buildPart();
	this->warehouses.push_back(temp);
	return temp;
}

MedicalCenter* ConstructionCompany::constructMedicalCenter()
{
	MedicalCenter* temp = new MedicalCenter("medical center",5000,5000,4550.50,600,345,500,50000);
	temp->buildPart();
	this->medicalCenters.push_back(temp);
	return temp;
}

School* ConstructionCompany::constructSchool()
{
	School* temp = new School("school",500,500,564.50,600,800,600,5600);
	temp->buildPart();
	this->schools.push_back(temp);
	return temp;
}

PoliceStation* ConstructionCompany::constructPoliceStation()
{
	PoliceStation* temp = new PoliceStation("police station",500,500,564.50,600,800,600,5600);
	temp->buildPart();
	this->policeStations.push_back(temp);
	return temp;
}

Office* ConstructionCompany::constructOffice()
{
	Office* temp = new Office("office",500,500,546.50,600,700,546.90,450000.60,600,600000);
	temp->buildPart();
	this->offices.push_back(temp);
	return temp;
}

Mall* ConstructionCompany::constructMall()
{
	Mall* temp = new Mall("mall",500,500,564.50,600,800,50.0,5600.50,500);
	temp->buildPart();
	this->malls.push_back(temp);
	return temp;
}

Shop* ConstructionCompany::ConstructShop()
{
	Shop* temp = new Shop("shop",500,500,564.50,600,800,50.0,5600.50,500);
	temp->buildPart();
	this->shops.push_back(temp);
	return temp;
}

Park* ConstructionCompany::constructPark()
{
	Park* temp =  new Park("park",500,500,564.50,600,800);
	temp->buildPart();
	this->parks.push_back(temp);
	return temp;
}

Monument* ConstructionCompany::constructMonument()
{
	Monument* temp = new Monument("monument",500,500,564.50,600,800);
	temp->buildPart();
	this->monuments.push_back(temp);
	return temp;
}

CulturalCenter* ConstructionCompany::constructCulturalCenter()
{
	CulturalCenter* temp = new CulturalCenter("cultural center",500,500,564.50,600,800);
	temp->buildPart();
	this->culturalCenters.push_back(temp);
	return temp;
}
