CC = g++ -c -std=c++17 -g -Wall -Werror

all = main.o Stops.o TrainStation.o Airpot.o Road.o RouteNode.o BestRouteNode.o AccesibleRoute.o MapIterator.o \
	Transport.o Train.o Vehicle.o Plane.o TransportBuilder.o PlaneBuilder.o TrainBuilder.o \
	VehicleBuilder.o TravelManager.o

%.o: %.cpp %.h
	$(CC) $<

main: $(all)
	g++ $(all) -o main

run: main
	./main

valgrind: main
	valgrind --leak-check=full ./main

clean:
	rm -f *.o main