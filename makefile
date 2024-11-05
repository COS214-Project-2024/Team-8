# Compiler and flags
CC = g++ -c -std=c++17 -g -Wall -Werror

# Main executable name
TARGET = main

# Object files for unified city management simulation
OBJECTS = TebogosMain.o Citizen.o PopulationControl.o Utility.o WaterSupply.o \
    WasteManagement.o SewageSystems.o MedicalCenter.o State.o \
    UnderConstruction.o Operational.o Damaged.o CitizenType.o EmployedCitizen.o \
    PropertyOwner.o BuildingController.o OfficeFactory.o Office.o HouseFactory.o \
    House.o ApartmentFactory.o Apartment.o ShopFactory.o Shop.o MallFactory.o Mall.o \
    Stops.o TrainStation.o Airpot.o Road.o RouteNode.o BestRouteNode.o AccesibleRoute.o \
    MapIterator.o Transport.o Train.o Vehicle.o Plane.o TransportBuilder.o PlaneBuilder.o \
    TrainBuilder.o VehicleBuilder.o TravelManager.o Government.o FinanceDepartment.o \
    FinanceSector.o UtilitiesSector.o GeneralSector.o Command.o Policies.o \
    EconomicPolicies.o PublicServicesPolicies.o ResidentialTaxationSystem.o \
    CommercialTaxationSystem.o BudgetAllocationSystem.o Buildings.o PublicServiceBuilding.o \

# Pattern rule for compiling .cpp files to .o files
%.o: %.cpp %.h
	$(CC) $<

# Special rule for main file since it doesn't need a header
TebogosMain.o: TebogosMain.cpp
	$(CC) $<

# Target for building the main application
$(TARGET): $(OBJECTS)
	g++ $(OBJECTS) -o $(TARGET)

# Default target
all: $(TARGET)

# Run the application
run: $(TARGET)
	./$(TARGET)

# Run with Valgrind for memory leak checking
valgrind: $(TARGET)
	valgrind --leak-check=full ./$(TARGET)

# Clean up compiled files
clean:
	rm -f *.o $(TARGET)

# Clean and rebuild
rebuild: clean all

# Help target
help:
	@echo "Available targets:"
	@echo "  make all      - Build the city management simulation"
	@echo "  make run      - Run the simulation"
	@echo "  make valgrind - Run with Valgrind memory checker"
	@echo "  make clean    - Remove compiled files"
	@echo "  make rebuild  - Clean and rebuild all"