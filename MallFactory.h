/**
 * @file MallFactory.h
 * @brief Defines the MallFactory class for creating mall buildings
 */

#ifndef MALLFACTORY_H
#define MALLFACTORY_H

#include "CommercialFactory.h"
#include "Buildings.h"
#include "Mall.h"

/**
 * @class MallFactory
 * @brief Factory class for creating mall buildings
 * 
 * This class implements the CommercialFactory interface to create Mall objects
 */
class MallFactory : public CommercialFactory {
public:
    /**
     * @brief Default constructor
     */
    MallFactory();

    /**
     * @brief Virtual destructor
     */
    virtual ~MallFactory();

    /**
     * @brief Creates a new mall building
     * @return Pointer to a newly created Mall object
     */
    virtual Buildings* createBuilding() override;
};

#endif // MALLFACTORY_H