#include "Utility.h"
#include "Resource.h"
#include "Buildings.h"
/**
 * @brief Construct a new Resource Mediator:: Resource Mediator object
 * 
 * @param resources 
 */
Utility::Utility(){
    //this->resources = resources;
    //this->utilities = utilities;
}

/**
 * @brief From Buildings to Power Resource object. If available, decrease the available power of the power resource object and return true, otherwise return false. Decrease the power according to the units parameter.
 * 
 * @param units 
 * @param sender
 * @return true 
 * @return false 
 */

bool Utility::usePower(float units, Buildings* sender){
    if(resources->find("Power")->second->giveResource(units)){
        std::cout << "There is enough power" << std::endl;
        return true;
    }
    std::cout << "Make more resources for Power" << std::endl;
    return false;
}

/**
 * @brief Call powerResource object and increase the available power by the "units" parameter.
 * 
 * @param units 
 */
float Utility::replenishPower(){
    float total = 0;
    for(Utility* util : *utilities){

        WaterSupply* specificUtil = dynamic_cast<WaterSupply*>(util);
        if(specificUtil){
            total += specificUtil->getOutput();
        }

    }

    return total;
}
/**
 * @brief From Buildings to Power Resource object. If available, decrease the available power of the power resource object and return true, otherwise return false. Decrease the power according to the units parameter.
 * 
 * @param units 
 * @param sender
 * @return true 
 * @return false 
 */

bool Utility::useWater(float units, Buildings* sender){
    if(resources->find("Water")->second->giveResource(units)){
        std::cout << "There is enough Water" << std::endl;
        return true;
    }
    std::cout << "Make more resources for Water" << std::endl;
    return false;
}

/**
 * @brief Call waterResource object and increase the available water by the "units" parameter.
 * 
 * @param units 
 */
float Utility::replenishWater(){
    float total = 0;
    for(Utility* util : *utilities){

        WaterSupply* specificUtil = dynamic_cast<WaterSupply*>(util);
        if(specificUtil){
        total += specificUtil->getOutput();
        }

    }

    return total;
}

/**
 * @brief From Buildings to revenue Resource object. If available, decrease the available revenue of the revenue resource object and return true, otherwise return false. Decrease the revenue according to the units parameter.
 * 
 * @param units 
 * @param sender
 * @return true 
 * @return false 
 */

bool Utility::useRevenue(float units, Buildings* sender){
    if(resources->find("Revenue")->second->giveResource(units)){
        std::cout << "There is enough Money" << std::endl;
        return true;
    }
    std::cout << "Make more resources for Money" << std::endl;
    return false;
}


/**
 * @brief From Buildings to waste Managment Resources object. If available, decrease the available waste cleaning capabilities of the waste managment resource object and return true, otherwise return false. Decrease the available waste cleaning resource according to the units parameter.
 * 
 * @param units 
 * @param sender
 * @return true 
 * @return false 
 */

bool Utility::cleanWaste(float units, Buildings* sender){
    if(resources->find("Waste")->second->giveResource(units)){
        std::cout << "There is enough Waste cleaning resources" << std::endl;
        return true;
    }
    std::cout << "Make more resources for Waste cleaning resources" << std::endl;
    return false;
}


/**
 * @brief Call the wasteManagmentResource object and increase the available resource by the "units" parameter.
 * 
 * @param units 
 */
float Utility::gainWasteCleaning(){
    float total = 0;
    for(Utility* util : *utilities){

        WasteManagement* specificUtil = dynamic_cast<WasteManagement*>(util);
        if(specificUtil){
        total += specificUtil->getOutput() ;
        }
    }

    return total;
}

/**
 * @brief From Buildings to sewage Managment Resources object. If available, decrease the available sewage cleaning capabilities of the sewage managment resource object and return true, otherwise return false. Decrease the available sewage cleaning resource according to the units parameter.
 * 
 * @param units 
 * @param sender
 * @return true 
 * @return false 
 */

bool Utility::cleanSewage(float units, Buildings* sender){
    if(resources->find("Sewage")->second->giveResource(units)){
        std::cout << "There is enough sewage cleaning resources" << std::endl;
        return true;
    }
    std::cout << "Make more resources for sewage cleaning resources" << std::endl;
    return false;
}


/**
 * @brief Call the sewageManagmentResource object and increase the available resource by the "units" parameter.
 * 
 * @param units 
 */
float Utility::gainSewageCleaning(){
    float total = 0;
    for(Utility* util : *utilities){

        SewageSystems* specificUtil = dynamic_cast<SewageSystems*>(util);
        if(specificUtil){
        total += specificUtil->getOutput() ;
        }

    }

    return total;
}


/**
 * @brief Call constructionResource object and increase the available construction resources by the "units" parameter.
 * 
 * @param units 
 */
float Utility::replenishRevenue(){
    float total = 0;
    for(Utility* util : *utilities){

        WaterSupply* specificUtil = dynamic_cast<WaterSupply*>(util);
        if(specificUtil){
        total += specificUtil->getOutput();
        }

    }

    return total;
}
/**
 * @brief From Buildings to construction Resource object. If available, decrease the available construction resources of the construction resource object and return true, otherwise return false. Decrease the construction resources according to the units parameter.
 * 
 * @param units 
 * @param sender 
 * @return true 
 * @return false 
 */

bool Utility::useConstResource(float units, Buildings* sender){
    if(resources->find("Water")->second->giveResource(units)){
        std::cout << "There is enough Water" << std::endl;
        return true;
    }
    std::cout << "Make more resources for Water" << std::endl;
    return false;
}
float Utility::replenishConstResource(){
    float total = 0;
    for(Utility* util : *utilities){

        WaterSupply* specificUtil = dynamic_cast<WaterSupply*>(util);
        if(specificUtil){
        total += specificUtil->getOutput();
        }

    }

    return total;
}

void Utility::setResources(std::map<std::string, Resource*>* resources){
    this->resources = resources;
}
void Utility::setUtilities(std::vector<Utility*>* utilities){
    this->utilities = utilities;
}