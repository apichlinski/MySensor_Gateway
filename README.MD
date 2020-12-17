# MySensors - Serial Gateway - 12 channel relay example

[![Build Status](https://travis-ci.org/joemccann/dillinger.svg?branch=master)](https://travis-ci.org/joemccann/dillinger)

This is a very simple example on how to write Smart serial gateway witch you can control via:
 - Google Assistant
 - Amazon Alexa
 - Home Assistant
 - Domoticz etc.

### New Features!

  - Cleaned up code v1.0
  - Moved to new PlatformIO IDE for better dependency managment.

### Hardware recommendation
For this project I recommend to use Arduino Mega 2560 because there is a lot of I/O pins and you can use other pins for another sensors like BME280 etc.
Also I recommend a 5V Relay module ror example SSR relay module with 1/2/4/8 channels.

### Software recommendation
* [mysensors/MySensors@^2.3.2] - MySensors main framework
* [thomasfredericks/Bounce2@^2.55] - Buttons bounce module

### Installation

If you use PlatformIO IDE you can simple clone repository and open it in IDE:

```sh
$ git clone https://github.com/apichlinski/MySensor_Gateway.git
```

But if you use Arduino you have to move content of headers.h file to first line of MySensors_Gateway.cpp and change extension main file from *.cpp to *.ino.

```sh
$ cd MySensor_Gateway
$ mv MySensor_Gateway.cpp MySensor_Gateway.ino
```
In arduino IDE you have to manually install require dependency  see Software recommendation

### Todos

 - Write MORE Tests

License
----

MIT