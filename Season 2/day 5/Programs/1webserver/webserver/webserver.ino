#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>


// Create an instance of the server
// specify the port to listen on as an argument
// WiFi.printDiag(Serial);
const char* ssid = "Lenovo";
const char* password = "terserah";
ESP8266WebServer server(80);

void handleRoot() {
  server.send(200, "text/html", "<h1>You are connected</h1>");
}

void setup() {
  delay(1000);
  Serial.begin(115200);
  delay(10);
    
  // Connect to WiFi network
  Serial.println();  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  
  // Start the server
  server.on("/", handleRoot);
  server.begin();
  Serial.println("Server started");

  // Print the IP address
  Serial.println(WiFi.localIP());
}

void loop() {
  server.handleClient();
}
