CC = g++ -c -std=c++17 -g -Wall -Werror

all = TestingMain.o Stops.o TrainStation.o Airpot.o Road.o RouteNode.o BestRouteNode.o AccesibleRoute.o MapIterator.o \
	Transport.o Train.o Vehicle.o Plane.o TransportBuilder.o PlaneBuilder.o TrainBuilder.o \
	VehicleBuilder.o TravelManager.o

demoall = DemoMain.o Stops.o TrainStation.o Airpot.o Road.o RouteNode.o BestRouteNode.o AccesibleRoute.o MapIterator.o \
	Transport.o Train.o Vehicle.o Plane.o TransportBuilder.o PlaneBuilder.o TrainBuilder.o \
	VehicleBuilder.o TravelManager.o

%.o: %.cpp %.h
	$(CC) $<

TestingMain: $(all)
	g++ $(all) -o TestingMain

DemoMain: $(demoall)
	g++ $(demoall) -o DemoMain

run: TestingMain
	./TestingMain

demo: DemoMain
	./DemoMain

valgrind: TestingMain
	valgrind --leak-check=full ./TestingMain

valgrind-demo: DemoMain
	valgrind --leak-check=full ./DemoMain

clean:
	rm -f *.o TestingMain DemoMain