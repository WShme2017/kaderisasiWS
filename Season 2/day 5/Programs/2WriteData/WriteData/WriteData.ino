// include ThingSpeak and ESP8266 WiFi Libraries
#include <ThingSpeak.h>
#include <ESP8266WiFi.h>

// set your Router user name and passward
char ssid[] = "yashf";          //  your network SSID (name) 
char pass[] = "12211221";   // your network password

// that you have already remembered from ThingSpeak websie
unsigned long myChannelNumber = 325405;
const char * myWriteAPIKey = "PK3Q0KXF1RPK2G44";

int sensorValue; // variable to save analog reading
WiFiClient  client;

void setup() {
  delay(1000);
  Serial.begin(115200);
  Serial.println("");
  WiFi.begin(ssid, pass);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  WiFi.printDiag(Serial);
  ThingSpeak.begin(client); 
}

void loop() {
  // read the input on analog pin 0:
  sensorValue = analogRead(A0);
  
  // Write to ThingSpeak. 
  // send your Channel Number
  // write to field 1
  // send sensorValue
  // send your Write API Key
  Serial.println(sensorValue);
  ThingSpeak.writeField(myChannelNumber, 1, sensorValue, myWriteAPIKey);
  delay(10000); // ThingSpeak will accept updates every 10 seconds.
}
