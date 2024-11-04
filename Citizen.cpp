#include "Citizen.h"
#include <iostream>

Citizen::Citizen(std::string name, float salary, int age, float satisfaction,
                 Government* government, bool isEmployed, bool ownsProperty)
    : name(name), salary(salary), satisfaction(satisfaction), age(age),
      isEmployed(isEmployed), ownsProperty(ownsProperty){
    currTaxRate = 0.10f;
    std::cout << "Citizen " << name << " has been created with a salary of $" << salary 
              << ", age " << age << ", satisfaction level " << satisfaction 
              << ", employment status: " << (isEmployed ? "Employed" : "Unemployed") 
              << ", property ownership status: " << (ownsProperty ? "Owner" : "Not an owner") 
              << "." << std::endl;
    tm = new TravelManager();
}


Citizen::Citizen(std::string name, float salary, int age, float satisfaction)
    : Citizen(name, salary, age, satisfaction, nullptr) {}

std::unique_ptr<CitizenInterface> Citizen::clone() {
    popControl->increasePopulation();
    return std::make_unique<Citizen>(*this);
}

Citizen::~Citizen() {
    std::cout << "Citizen " << name << " has been destroyed." << std::endl;
    delete tm;
    tm = nullptr;
}

float Citizen::getTaxRate()
{
    return this->currTaxRate ;
}

void Citizen::addKnownLocations(Stops *stop)
{
    tm->addStops(stop);
}

void Citizen::update(float newTaxRate) {
    std::cout << name << " is updating tax rate from " << currTaxRate 
              << " to " << newTaxRate << "." << std::endl;
    currTaxRate = newTaxRate;

    if (newTaxRate > currTaxRate) {
        adjustCitizenSatisfaction(-5);
        std::cout << name << " feels the pinch of higher taxes." << std::endl;
    } else {
        adjustCitizenSatisfaction(5);
        std::cout << name << " is pleased with the lower tax rate!" << std::endl;
    }
}

void Citizen::makeRequest(Government* government, std::string requestDetails) {
    if (government) {
        std::cout << name << " is making a request to the government: " << requestDetails << std::endl;
        government->handleRequest(requestDetails); // Pass first object in chain and set successors in main
        std::cout << "[Citizen] Government does not exist." << std::endl;
    }
}

void Citizen::useTransport(Stops *stop, int capacity, bool bestRoute){
    if(bestRoute){
        tm->BestRoute(capacity, stop);
    }else tm->Travel(capacity,stop);
}

void Citizen::adjustCitizenSatisfaction(float newSatisfaction) {
    this->satisfaction += newSatisfaction;

    // Ensure satisfaction is capped between 0 and 100
    if (satisfaction > 100) {
        satisfaction = 100;
    } else if (satisfaction < 0) {
        satisfaction = 0;
    }

    // If satisfaction falls below 50, request government assistance
    if (satisfaction < 50) {
        std::string requestDetails = "[Main] Work on citizen satisfaction";
        makeRequest(government, requestDetails);
    }
    std::cout << name << "'s satisfaction is now: " << satisfaction << "." << std::endl;
}

void Citizen::setEmploymentStatus(bool employmentStatus) {
    this->isEmployed = employmentStatus;
    std::cout << name << "'s employment status has been set to: " << (employmentStatus ? "Employed" : "Unemployed") << "." << std::endl;
}

void Citizen::setPropertyOwnership(bool ownsProperty) {
    this->ownsProperty = ownsProperty;
    std::cout << name << "'s property ownership status has been set to: " << (ownsProperty ? "Owner" : "Not an owner") << "." << std::endl;
}

float Citizen::getSalary() {
    // unemployed citizens get grants
    float effectiveSalary = isEmployed ? salary : 3500.0f;
    std::cout << name << "'s effective salary is $" << effectiveSalary << "." << std::endl;
    return effectiveSalary;
}

void Citizen::setSalary(float newSalary) {
    this->salary = newSalary;
    std::cout << name << "'s salary has been updated to $" << salary << "." << std::endl;
}

int Citizen::getAge() {
    return this->age;
}

std::string Citizen::getName() {
    return this->name;
}

float Citizen::getSatisfaction()
{
    return satisfaction;
}

void Citizen::requestPublicService(std::string serviceType, float impact) {
    std::cout << name << " has requested access to " << serviceType << " service." << std::endl;
    adjustCitizenSatisfaction(impact);
    std::cout << name << "'s satisfaction after using " << serviceType 
              << " service is now " << satisfaction << "." << std::endl;
}

void Citizen::attendEvent(std::string eventName, float impact) {
    std::cout << name << " is attending the event: " << eventName << "." << std::endl;
    adjustCitizenSatisfaction(impact);
    std::cout << name << "'s satisfaction after attending " << eventName 
              << " is now " << satisfaction << "." << std::endl;
}

float Citizen::evaluateHappiness() {
    float happiness = satisfaction + (salary / 1000);
    // Adjust based on bounds
    if (happiness > 100.0f) happiness = 100.0f;
    else if (happiness < 0.0f) happiness = 0.0f;

    std::cout << name << "'s overall happiness level is " << happiness << "." << std::endl;
    return happiness;
}

void Citizen::displayDetails() {
    std::cout << "\n===== Citizen Details =====" << std::endl;
    std::cout << "Name: " << name << std::endl;
    std::cout << "Age: " << age << " years" << std::endl;
    std::cout << "Employment Status: " << (isEmployed ? "Employed" : "Unemployed") << std::endl;
    std::cout << "Property Ownership: " << (ownsProperty ? "Owner" : "Not an Owner") << std::endl;
    std::cout << "Salary: $" << (isEmployed ? salary : 3500.0f) << std::endl; 
    std::cout << "Satisfaction: " << satisfaction << " / 100" << std::endl;
    std::cout << "Current Tax Rate: " << currTaxRate * 100 << "%" << std::endl;
    std::cout << "Overall Happiness: " << evaluateHappiness() << " / 100" << std::endl;
    std::cout << "===========================\n" << std::endl;
}

bool Citizen::getEmployementStatus()
{
    return isEmployed;
}

bool Citizen::getPropertyOwnershipStatus()
{
    return ownsProperty;
}

double Citizen::getBalance()
{
    return this->balance;
}

void Citizen::setBalance(double newBalance)
{
    this->balance = newBalance ; 
}

void Citizen::setSatisfaction(int newSatisfaction)
{
    this->satisfaction = newSatisfaction ; 
}
