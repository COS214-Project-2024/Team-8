#include "Citizen.h"
#include "Government.h"

Citizen::Citizen(std::string name, float salary, int age, float satisfaction, 
                 Government* government, bool hasJob, bool ownsProperty)
    : name(name), salary(salary), age(age), satisfaction(satisfaction),
      government(government), isEmployed(hasJob), ownsProperty(ownsProperty),
      currTaxRate(0.10f)
{
    popControl.increasePopulation();
}

Citizen::Citizen(std::string name, float salary, int age, float satisfaction)
    : Citizen(name, salary, age, satisfaction, nullptr) {}


std::unique_ptr<CitizenInterface> Citizen::clone() {
    popControl.increasePopulation();
    return std::make_unique<Citizen>(*this);
}

Citizen::~Citizen() {}

void Citizen::update(float newTaxRate) {
	currTaxRate =  newTaxRate;
	if(newTaxRate > currTaxRate){
		adjustCitizenSatisfaction(-5);
	}else{
		adjustCitizenSatisfaction(5);
	}
}

void Citizen::makeRequest(Government* government, std::string requestDetails)
{
	if(government){
		government->handleRequest(requestDetails);
	}else{
		std::cout<<"[Citizen] Government does not exist"<<std::endl;
	}
    
}

void Citizen::useTransport(Transport *transport)
{
	if(transport){
		transport->travel();
	}else{
		std::cout<<"[Citizen] Transport does not exist"<<std::endl;
	}
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
    std::cout << name << "'s satisfaction is now: " << satisfaction << std::endl;
}

void Citizen::setEmploymentStatus(bool employmentStatus)
{
	this->isEmployed = employmentStatus;
}

void Citizen::setPropertyOwnership(bool ownsProperty)
{
	this->ownsProperty = ownsProperty;
}

float Citizen::getSalary()
{
	// unemployed citizens get grants
    return 3500.0f;
}

void Citizen::setSalary(float newSalary)
{
    this->salary = newSalary;
}

int Citizen::getAge()
{
    return this->age;
}
void Citizen::requestPublicService(std::string serviceType, float impact) {
    std::cout << name << " has requested access to " << serviceType << " service.\n";
    adjustCitizenSatisfaction(impact);
    std::cout << name << "'s satisfaction after using " << serviceType << " service is now " << satisfaction << ".\n";
}

void Citizen::attendEvent(std::string eventName, float impact) {
    std::cout << name << " is attending the event: " << eventName << ".\n";
    adjustCitizenSatisfaction(impact);
    std::cout << name << "'s satisfaction after attending " << eventName << " is now " << satisfaction << ".\n";
}

float Citizen::evaluateHappiness()  {
    float happiness = satisfaction + (salary / 1000); 
    // Adjust based on bounds
    if (happiness > 100.0f) happiness = 100.0f;
    else if (happiness < 0.0f) happiness = 0.0f;

    std::cout << name << "'s overall happiness level is " << happiness << ".\n";
    return happiness;
}

