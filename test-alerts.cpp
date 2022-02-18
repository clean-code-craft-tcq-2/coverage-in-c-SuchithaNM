#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "typewise-alert.h"

TEST_CASE("infers the breach according to limits") {
  REQUIRE(inferBreach(12, 20, 30) == TOO_LOW);
}

TEST_CASE("infers the breach according to high limits") {
  REQUIRE(inferBreach(35, 7, 30) == TOO_HIGH);
}

TEST_CASE("infers the breach according to Normal ") {
  REQUIRE(inferBreach(20, 5, 40) == NORMAL);
}

TEST_CASE("Send Email Alert to receipt to notify  too Low Tempature  ") {
  REQUIRE(sendToEmail(TOO_LOW)) == SEND_TO_EMAIL_TOO_LOW);
}

TEST_CASE("Send Email Alert to receipt to notify too High Tempature  ") {
  REQUIRE(sendToEmail(TOO_HIGH)) == SEND_TO_EMAIL_TOO_HIGH);
}

TEST_CASE("Send Email Alert to receipt to notify Normal Tempature  ") {
  REQUIRE(sendToEmail(NORMAL)) == SEND_TO_EMAIL_NORMAL);
}
  
