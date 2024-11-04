CC = g++ -c -std=c++17 -g -Wall -Werror

all = TebogosMain.o Citizen.o PopulationControl.o Utility.o UtilityPowerPlant.o WaterSupply.o WasteManagement.o SewageSystems.o  ResourceMediator.o MedicalCenter.o State.o UnderConstruction.o  \
	Operational.o Damaged.o CitizenType.o EmployedCitizen.o PropertyOwner.o \
    OfficeFactory.o Office.o HouseFactory.o House.o Stops.o TrainStation.o Airpot.o Road.o RouteNode.o BestRouteNode.o AccesibleRoute.o MapIterator.o \
	Transport.o Train.o Vehicle.o Plane.o TransportBuilder.o PlaneBuilder.o TrainBuilder.o VehicleBuilder.o TravelManager.o \
    UtilityFactory.o PowerPlantFactory.o WaterFactory.o WasteFactory.o SewageFactory.o \
	EnergySource.o CoalSource.o NuclearSource.o HydroSource.o WindSource.o EnergyFactory.o HydroFactory.o NuclearFactory.o CoalFactory.o WindFactory.o \
	UtilityManager.o Command.o StartCommand.o StopCommand.o UndoCommand.o

demoall = DemoMain.o Stops.o TrainStation.o Airpot.o Road.o RouteNode.o BestRouteNode.o AccesibleRoute.o MapIterator.o \
	Transport.o Train.o Vehicle.o Plane.o TransportBuilder.o PlaneBuilder.o TrainBuilder.o \
	VehicleBuilder.o TravelManager.o

%.o: %.cpp %.h
	$(CC) $<

TebogosMain: $(all)
	g++ $(all) -o TebogosMain

DemoMain: $(demoall)
	g++ $(demoall) -o DemoMain

run: TebogosMain
	./TebogosMain

demo: DemoMain
	./DemoMain

valgrind: TebogosMain
	valgrind --leak-check=full ./TebogosMain

valgrind-demo: DemoMain
	valgrind --leak-check=full ./DemoMain

clean:
	rm -f *.o TebogosMain DemoMain