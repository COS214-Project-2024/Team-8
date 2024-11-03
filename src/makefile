CC = g++ -c -std=c++17 -g -Wall -Werror

all = main.o Stops.o TrainStation.o Airpot.o Road.o RouteNode.o BestRouteNode.o AccesibleRoute.o MapIterator.o \
	Transport.o Train.o Vehicle.o Plane.o TransportBuilder.o PlaneBuilder.o TrainBuilder.o \
	VehicleBuilder.o TravelManager.o

demoall = DemoMain.o Stops.o TrainStation.o Airpot.o Road.o RouteNode.o BestRouteNode.o AccesibleRoute.o MapIterator.o \
	Transport.o Train.o Vehicle.o Plane.o TransportBuilder.o PlaneBuilder.o TrainBuilder.o \
	VehicleBuilder.o TravelManager.o

%.o: %.cpp %.h
	$(CC) $<

main: $(all)
	g++ $(all) -o main

DemoMain: $(demoall)
	g++ $(demoall) -o DemoMain

run: main
	./main

demo: DemoMain
	./DemoMain

valgrind: main
	valgrind --leak-check=full ./main

valgrind-demo: DemoMain
	valgrind --leak-check=full ./DemoMain

clean:
	rm -f *.o main DemoMain