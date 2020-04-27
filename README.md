# rpi-fan-control

## How to install

`$ git clone https://github.com/softeip/rpi-fan-control.git`  
`$ cd rpi-fan-control`  

## How to configure
All the configuration parameters are listed in `src/configuration.h` with comments  

## How to build
Get binary executable file:  
`$ make`  
Find bin here: `./bin/rpi-fan-controller`  
OR  
Install it as systemd service by running:
`$ sudo make install`  

## How to uninstall  
`$ sudo make uninstall`  

## How it works  
Program has 3 levels: Low, Average, High  
- Low is defined as threshold value  
- Average is defined as average between Low and Critical values  
- High is defined as critical value  
  
Starts fan (by using soft PWM) when CPU temperature higher than threshold  
Stops when less than threshold
Continues spinning your fan for 20 sec if level gets lower  
