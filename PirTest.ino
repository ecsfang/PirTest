#include <ESP8266WiFi.h>
#include "Pushover.h"
#include "secret.h"

int pirPin = D7;
int val;

void setup() {
  Serial.begin(115200);
  WiFi.begin(mySSID, myPassw);
  while (WiFi.status() != WL_CONNECTED) delay(50);
  Serial.println("Connected");
}
  
void sendPing() {
  Pushover po = Pushover(apiToken,userToken, UNSAFE);
  po.setDevice("WinLab");
  po.setMessage("Testnotification");
  po.setSound("bike");
  Serial.println(po.send()); //should return 1 on success
}

void loop()
{
val = digitalRead(pirPin);
//low = no motion, high = motion
if (val == LOW)
{
  Serial.println("No motion");
}
else
{
  Serial.println("Motion detected  ALARM");
  sendPing();
}
 
delay(1000);
}
