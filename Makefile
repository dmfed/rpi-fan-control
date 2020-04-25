CC=g++
CFLAGS=-Wall
LDFLAGS=-lwiringPi -lpthread
SOURCES=src/main.cpp src/temperatureSensor.cpp src/fan.cpp
EXECUTABLE=rpi-fan-control

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): 
	$(CC) $(CFLAGS) $(LDFLAGS) -o bin/$(EXECUTABLE) $(SOURCES)

clean:
	rm bin/$(EXECUTABLE)
	rm -rf *.o hello
