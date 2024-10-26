#include "Citizen.h"
#include "Government.h"

Citizen::Citizen(const std::string& name, float salary, Government* government, bool hasJob, bool ownsProperty)
    : government(government), hasJob(hasJob), ownsProperty(ownsProperty) {
    this->name = name;
    this->salary = salary;
    this->satisfaction = 100.0f;
	this->currTaxRate = 0.10; 
}

Citizen::~Citizen() {}
float Citizen::calculateTax() {
	if(hasJob){
		return salary * currTaxRate;
	}
}

void Citizen::applyTax() {
	float taxAmount = calculateTax();
    salary -= taxAmount;
}

void Citizen::jobPromotion(float percentage) {
	float salaryIncrease = salary * (percentage/ 100.0f);
    salary += salaryIncrease;
}

std::unique_ptr<CitizenInterface> Citizen::clone() {
	popControl.increasePopulation();
	return std::make_unique<Citizen>(*this); // Creates a clone of the citizen
}

void Citizen::update(float newTaxRate) {
	currTaxRate =  newTaxRate;
	applyTax();

	if(newTaxRate > currTaxRate){
		adjustCitizenSatisfaction(-5);
	}else{
		adjustCitizenSatisfaction(5);
	}

}

void Citizen::makeRequest(Government* government, std::string& requestDetails)
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

void Citizen::adjustCitizenSatisfaction(float newSatisfaction)
{
	satisfaction += newSatisfaction;
	if(satisfaction > 100){
		satisfaction = 100;
	}else if (satisfaction < 0){
		satisfaction = 0;
	}
	if(satisfaction < 50){
		std::string& requestDetails = "[Main] Work on citizen satisfaction";
		makeRequest(government, requestDetails);
	}
}
