#include "typewise-alert.h"


/***************************************************EmailMsgHandler.c *************************************************/
Targetype (*EmailMesssage[])(const char* recepient) = { sendTooLowMessage , sendTooHighMessage, sendNormalMessage };


Targetype sendToEmail(BreachType breachType) 
{
  const char* recepient = "a.b@c.com";
  Targetype EmailMesssageNotify = (*EmailMesssage[breachType])(recepient);
	  return EmailMesssageNotify;

}


Targetype sendTooLowMessage(const char* recepient)
{
	  printf("To: %s\n", recepient);
      printf("Hi, the temperature is too low\n");
	  return SEND_TO_EMAIL_TOO_LOW;

}

Targetype sendTooHighMessage(const char* recepient)
{
      printf("To: %s\n", recepient);
      printf("Hi, the temperature is too high\n");
	  return SEND_TO_EMAIL_TOO_HIGH;
}


Targetype sendNormalMessage(const char* recepient)
{
      printf("To: %s\n", recepient);
      printf("Hi, the temperature is Normal\n");
	  return SEND_TO_EMAIL_NORMAL;
}
