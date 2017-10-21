#include <ESP8266WebServer.h>

const char *ssid = "hiimwifi";
const char *password = "onetill8";
ESP8266WebServer server(80);

void handleRoot(){
  server.send(200,"text/html","<h1>You are connected</h1>");
}

String webPage =
(String)"<h1>ESP8266 Access Point</h1>"+
"<p>Socket #1 <a href=\"socket1On\"><button>ON</button></a>&nbsp;<a href=\"socket1Off\"><button>OFF</button></a></p>"+
"<p>Socket #2 <a href=\"socket2On\"><button>ON</button></a>&nbsp;<a href=\"socket2Off\"><button>OFF</button></a></p>";

int gpio0_pin = 4;
int gpio2_pin = 2;

void setup(){
  pinMode(gpio0_pin, OUTPUT);
  pinMode(gpio2_pin, OUTPUT);
  digitalWrite(gpio0_pin, LOW);
  digitalWrite(gpio2_pin, LOW);
  delay(1000);
  Serial.begin(115200);
  Serial.println();
  Serial.print("Configuring access point...");

  WiFi.softAP(ssid, password);
  IPAddress myIP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(myIP);
  server.on("/",[](){
    server.send(200, "text/html", webPage);  
  });
  server.on("/socket1On",[](){
    server.send(200, "text/html", webPage);
    digitalWrite(gpio0_pin, HIGH);
    delay(1000);
  });
  server.on("/socket1Off",[](){
    server.send(200, "text/html", webPage);
    digitalWrite(gpio0_pin, LOW);
    delay(1000);
  });
  server.on("/socket2On",[](){
    server.send(200, "text/html", webPage);
    digitalWrite(gpio2_pin, HIGH);
    delay(1000);
  });
  server.on("/socket2Off",[](){
    server.send(200, "text/html", webPage);
    digitalWrite(gpio2_pin, LOW);
    delay(1000);
  });
  server.begin();
  Serial.println("HTTP server started");
}

void loop(){
  server.handleClient();
}

