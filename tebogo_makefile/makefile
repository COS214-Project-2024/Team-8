# Compiler and flags
CC = g++ -c -std=c++17 -g -Wall -Werror

# Object files for TebogosMain and other classes
all = TebogosMain.o Citizen.o PopulationControl.o Utility.o WaterSupply.o WasteManagement.o SewageSystems.o  Utility.o MedicalCenter.o State.o UnderConstruction.o  Operational.o Damaged.o CitizenType.o EmployedCitizen.o PropertyOwner.o \
       OfficeFactory.o Office.o HouseFactory.o House.o Stops.o TrainStation.o Airpot.o Road.o RouteNode.o BestRouteNode.o AccesibleRoute.o MapIterator.o \
	Transport.o Train.o Vehicle.o Plane.o TransportBuilder.o PlaneBuilder.o TrainBuilder.o \
	VehicleBuilder.o TravelManager.o

# Pattern rule for compiling .cpp files to .o files
%.o: %.cpp %.h
	$(CC) $<

# Target for building the main application
main: $(all)
	g++ $(all) -o main

# Run the main application
run: main
	./main

# Run the main application with Valgrind
valgrind: main
	valgrind --leak-check=full ./main

# Clean up all generated files
clean:
	rm -f *.o main
