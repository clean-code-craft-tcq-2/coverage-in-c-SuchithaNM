#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "typewise-alert.h"

TEST_CASE("infers the breach according to limits in HI_ACTIVE_COOLING for NORMAL case") {
  REQUIRE(classifyTemperatureBreach(HI_ACTIVE_COOLING, 40) == NORMAL);
}

TEST_CASE("infers the breach according to limits in PASSIVE_COOLING for TOO_LOW case") {
  REQUIRE(classifyTemperatureBreach(PASSIVE_COOLING, -4) == TOO_LOW);
}

TEST_CASE("infers the breach according to limits in MED_ACTIVE_COOLING for TOO_HIGH case") {
  REQUIRE(classifyTemperatureBreach(MED_ACTIVE_COOLING, 60) == TOO_HIGH);
}

TEST_CASE("Check and alert functionality check to controller in case of PASSIVE_COOLING:NORMAL") {
	 BatteryCharacter batterycharname= {PASSIVE_COOLING, "BMS"};
    REQUIRE( checkAndAlert(TO_CONTROLLER, batterycharname, 30)== SentToController);
}

TEST_CASE("Check and alert functionality check to email in case of PASSIVE_COOLING:NORMAL") {
	 BatteryCharacter batterycharname= {PASSIVE_COOLING, "BMS"};
     REQUIRE(checkAndAlert(TO_EMAIL, batterycharname, 30)==SentToEmail_Normal);
}

TEST_CASE("Check and alert functionality check to email in case of PASSIVE_COOLING:TOO_LOW") {
	 BatteryCharacter batterycharname= {PASSIVE_COOLING, "BMS"};
     REQUIRE(checkAndAlert(TO_EMAIL, batterycharname, -4)==SentToEmail_TooLow);
}

TEST_CASE("Check and alert functionality check to email in case of PASSIVE_COOLING:TOO_HIGH") {
	 BatteryCharacter batterycharname= {PASSIVE_COOLING, "BMS"};
     REQUIRE(checkAndAlert(TO_EMAIL, batterycharname, 50)==SentToEmail_TooHigh);
}

TEST_CASE("Check and alert functionality check to email in case of HI_ACTIVE_COOLING:NORMAL") {
	 BatteryCharacter batterycharname= {HI_ACTIVE_COOLING, "BMS"};
     REQUIRE(checkAndAlert(TO_CONSOLE, batterycharname, 30)==SentToConsole);
}

/*
TEST_CASE("infers the breach according to limits") {
  REQUIRE(inferBreach(12, 20, 30) == TOO_LOW);
}

TEST_CASE("infers the breach according to high limits") {
  REQUIRE(inferBreach(35, 7, 30) == TOO_HIGH);
}

TEST_CASE("infers the breach according to Normal ") {
  REQUIRE(inferBreach(20, 5, 40) == NORMAL);
}

TEST_CASE("Classify temperature Breach as a Passive cooling  ") {
  REQUIRE(classifyTemperatureBreach(PASSIVE_COOLING ,-1 ) == TOO_LOW);
}

TEST_CASE("Classify temperature Breach as a HIgh active cooling  ") {
  REQUIRE(classifyTemperatureBreach(HI_ACTIVE_COOLING ,55 ) == TOO_HIGH);
}

TEST_CASE("Classify temperature Breach as a Mid active cooling  ") {
  REQUIRE(classifyTemperatureBreach(MED_ACTIVE_COOLING ,20 ) == NORMAL);
}

TEST_CASE("Check and Send Email Alert to receipt to notify  too High Tempature  ") {
	BatteryCharacter batteryChar = {HI_ACTIVE_COOLING,"BMS"};
  REQUIRE(checkAndAlert(TO_EMAIL,batteryChar,120) == SEND_TO_EMAIL_TOO_HIGH);
}

TEST_CASE("Check and Send Email Alert to receipt to notify  Noraml Tempature   ") {
	BatteryCharacter batteryChar = {PASSIVE_COOLING,"BMS"};
  REQUIRE(checkAndAlert(TO_EMAIL,batteryChar,40) == SEND_TO_EMAIL_NORMAL);
}

TEST_CASE("Check and Send Email Alert to receipt to notify too Low Tempearture  ") {
	BatteryCharacter batteryChar = {PASSIVE_COOLING,"BMS"};
  REQUIRE(checkAndAlert(TO_EMAIL,batteryChar,0 ) == SEND_TO_EMAIL_TOO_LOW);
}

TEST_CASE("Check and Send Alert notification to controller ") {
	BatteryCharacter batteryChar = {PASSIVE_COOLING,"BMS"};
  REQUIRE(checkAndAlert(TO_CONTROLLER,batteryChar,30 ) == SEND_TO_CONTROLLER);
}*/
  
