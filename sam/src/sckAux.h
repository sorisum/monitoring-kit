#pragma once

// Include the necessary libraries for the auxiliary sensor to be used
#include <Wire.h>
#include <Adafruit_INA219.h>
#include "Adafruit_SHT31.h"
#include <MCP3424.h>

// TEMP
// Adafruit_INA219 aux1(0x41);

class auxSensor {
public:
	void setup();

private:
};

struct Resistor {
	byte deviceAddress;
	byte resistorAddress;
};

class AlphaDelta {
public:
	
	bool begin();
	
	// SHT31 Temperature and Humidity Sensor
	Adafruit_SHT31 sht31 = Adafruit_SHT31();
	float getTemperature();
	float getHumidity();

	// Alphasense Gas Sensors
	enum Electrodes {AE_1, WE_1, AE_2, WE_2, AE_3, WE_3};
	double getElectrode(Electrodes wichElectrode);

	// Alphasense Digital Potenciometers
	Resistor POT_AE1 = {0x55, 0x01};
	Resistor POT_WE1 = {0x55, 0x00};
	Resistor POT_AE2 = {0x56, 0x01};
	Resistor POT_WE2 = {0x56, 0x00};
	Resistor POT_AE3 = {0x54, 0x01};
	Resistor POT_WE3 = {0x54, 0x00};

	void setPot(Resistor wichPot, uint32_t value);
	uint32_t getPot(Resistor wichPot);
	const float ohmsPerStep = 392.1568;     // Resistor conversion constant in Ohms. (100,000 / 255)

private:
};