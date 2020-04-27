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

install: all
	cp bin/rpi-fan-control /usr/bin/rpi-fan-control
	chmod +x /usr/bin/rpi-fan-control
	cp rpi-fan-control.service /etc/systemd/system/rpi-fan-control.service
	chmod 644 /etc/systemd/system/rpi-fan-control.service
	systemctl enable rpi-fan-control
	systemctl start rpi-fan-control

uninstall:
	systemctl stop rpi-fan-control
	rm -f /etc/systemd/system/rpi-fan-control.service
	rm -f /usr/bin/rpi-fan-control
