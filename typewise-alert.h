#pragma once

#include <stdio.h>

typedef enum {
  PASSIVE_COOLING,
  HI_ACTIVE_COOLING,
  MED_ACTIVE_COOLING
} CoolingType;

typedef enum {
  NORMAL,
  TOO_LOW,
  TOO_HIGH
} BreachType;

typedef enum {
  TO_CONTROLLER,
  TO_EMAIL
} AlertTarget;


typedef struct {
  CoolingType coolingType;
  char brand[48];
} BatteryCharacter;

typedef enum {
	SEND_TO_CONTROLLER,
	SEND_TO_EMAIL_TOO_LOW,
	SEND_TO_EMAIL_TOO_HIGH,
	SEND_TO_EMAIL_NORMAL,
}Targetype;


typedef struct{
double lowerLimit;
double upperLimit;
CoolingType coolingType;	
}BreachLimit_t;


BreachType inferBreach(double value, double lowerLimit, double upperLimit);
BreachType classifyTemperatureBreach(CoolingType coolingType, double temperatureInC);

Targetype checkAndAlert( AlertTarget alertTarget, BatteryCharacter batteryChar, double temperatureInC);

Targetype sendToController(BreachType breachType);
Targetype sendToEmail(BreachType breachType);
Targetype sendTooLowMessage(const char* recepient);
Targetype sendTooHighMessage(const char* recepient);
Targetype sendNormalMessage(const char* recepient);

