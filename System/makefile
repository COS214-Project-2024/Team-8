# Compiler and flags
CC = g++
CFLAGS = -c -std=c++17 -g -Wall

# Main executable name
TARGET = citybuilder

# Object files
OBJECTS = main.o \
    Citizen.o \
    PopulationControl.o \
    Utility.o \
    WaterSupply.o \
    WasteManagement.o \
    SewageSystems.o \
    MedicalCenter.o \
    State.o \
    UnderConstruction.o \
    Operational.o \
    Damaged.o \
    CitizenType.o \
    EmployedCitizen.o \
    PropertyOwner.o \
    BuildingController.o \
    Buildings.o \
    OfficeFactory.o \
    Office.o \
    HouseFactory.o \
    House.o \
    ApartmentFactory.o \
    Apartment.o \
    ShopFactory.o \
    Shop.o \
    MallFactory.o \
    Mall.o \
    Stops.o \
    TrainStation.o \
    Airport.o \
    Road.o \
    RouteNode.o \
    BestRouteNode.o \
    AccesibleRoute.o \
    MapIterator.o \
    Transport.o \
    Train.o \
    Vehicle.o \
    Plane.o \
    TransportBuilder.o \
    PlaneBuilder.o \
    TrainBuilder.o \
    VehicleBuilder.o \
    TravelManager.o \
    Government.o \
    FinanceDepartment.o \
    FinanceSector.o \
    UtilitiesSector.o \
    GeneralSector.o \
    Command.o \
    Policies.o \
    EconomicPolicies.o \
    PublicServicesPolicies.o \
    ResidentialTaxationSystem.o \
    CommercialTaxationSystem.o \
    BudgetAllocationSystem.o \
    PublicServiceBuilding.o \
    School.o \
    PoliceStation.o \
    Monument.o \
    Park.o \
    CulturalCenter.o \

# Header files (for dependencies)
HEADERS = $(wildcard *.h)

# Default target
all: $(TARGET)

# Linking rule
$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(TARGET)

# Compilation pattern rule
%.o: %.cpp $(HEADERS)
	$(CC) $(CFLAGS) $< -o $@

# Specific rules for main (if needed)
main.o: main.cpp $(HEADERS)
	$(CC) $(CFLAGS) main.cpp

# Clean rule
clean:
	rm -f $(OBJECTS) $(TARGET)

# Rebuild everything
rebuild: clean all

# Run the program
run: $(TARGET)
	./$(TARGET)

# Debug with valgrind
valgrind: $(TARGET)
	valgrind --leak-check=full ./$(TARGET)

# Help target
help:
	@echo "Available targets:"
	@echo "  make all      - Build the city builder game"
	@echo "  make run      - Run the game"
	@echo "  make clean    - Remove compiled files"
	@echo "  make rebuild  - Clean and rebuild all"
	@echo "  make valgrind - Run with memory leak checker"

# Phony targets
.PHONY: all clean rebuild run valgrind help