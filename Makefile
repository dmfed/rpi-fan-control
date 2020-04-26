CC=g++
CFLAGS=-Wall
LDFLAGS=-lwiringPi -lpthread
SOURCES=src/main.cpp src/temperature.cpp src/fan.cpp src/log.cpp src/fanController.cpp
EXECUTABLE=rpi-fan-control

all: $(EXECUTABLE)
	
$(EXECUTABLE): 
	$(CC) $(CFLAGS) $(LDFLAGS) -o bin/$(EXECUTABLE) $(SOURCES)

clean:
	rm bin/$(EXECUTABLE)
	rm -rf *.o hello
