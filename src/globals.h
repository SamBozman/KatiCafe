#pragma once

#include <Arduino.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include <HX711_ADC.h>
#include <WebSerial.h>
#include <WiFi.h>
#if defined(ESP8266) || defined(ESP32) || defined(AVR)
#include <EEPROM.h>
#endif


#define LED 26

AsyncWebServer server(80);

const char *ssid = "BOZWRT_2.4G";    // Your WiFi SSID
const char *password = "3bh7avd8mi"; // Your WiFi Password
// pins:
const int HX711_dout = 4; // mcu > HX711 dout pin
const int HX711_sck = 5;  // mcu > HX711 sck pin

// HX711 constructor:
HX711_ADC LoadCell(HX711_dout, HX711_sck);

const int calVal_eepromAdress = 0;

unsigned long t = 0;

void calibrate();
void changeSavedCalFactor();
void recvMsg(uint8_t *data, size_t len);