#include <EEPROM.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>

const char *ssid = "hiimwifi";
const char *password = "onetill8";
ESP8266WebServer server(80);

String indexPage =
(String)"<h1>ESP8266 Access Point</h1>"+
"<form action=\"inputNUM\" method=\"post\">"+
"Number input: <input type=\"number\" name=\"NUM\">"+
"<input type=\"submit\": value=\"Store\">"+
"</form>";

void setupAP(){
  Serial.begin(115200);
  Serial.println();
  WiFi.softAP(ssid,password);

  IPAddress APIP = WiFi.softAPIP();
  Serial.print("visit : ");
  Serial.println(APIP);
}
void setupServer(){
  server.on("/",[](){
    server.send(200, "text/html", indexPage);
  });
  server.on("/inputNUM",HTTP_POST,handleInput);
  server.on("/NUM",handleoutput);
}
void handleoutput(){
  int NUM;
  String NUMpage;
  EEPROM.begin(512);
  EEPROM.get(0,NUM);
  EEPROM.end();
  NUMpage = (String)"Nilai dari NUM yang disimpan adalah " + NUM;
  server.send(200,"text/plain", NUMpage);
}
void handleInput(){
  String inputNUMpage;
  String NUM;

  NUM = server.arg("NUM");

  int eeAdress = 0;
  int data = NUM.toInt();
  EEPROM.begin(512);
  EEPROM.put(eeAdress,data);
  EEPROM.end();

  inputNUMpage += NUM + " has been stored on address " + String(eeAdress) +'\n';
  inputNUMpage += "this is server.argName() " + server.argName(0) + '\n';
  inputNUMpage += "this is server.arg() " + server.arg(0);

  server.send(200,"text/plain", inputNUMpage);
}

void setup(){
  setupAP();
  setupServer();
  server.begin();
  Serial.println("HTTP server started");
}
void loop(){
  server.handleClient();
}

