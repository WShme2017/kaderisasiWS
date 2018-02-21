#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <Servo.h>    
Servo myservo;

char auth[] = "d80b6c1d1d294120b40c0e270be7c38f";

char ssid[] = "lol";
char pass[] = "qwerty555";

int count = 0;
int servo = 0;
int magnet = 4;
int touch = 13;
int laser = 5;
int buzzer = 15;

void setup()
{ 
  myservo.attach(12);
  // Debug console
  Serial.begin(9600);

  Blynk.begin(auth, ssid, pass);
}

void loop()
{
  Blynk.run();
  if ((digitalRead(servo)==HIGH) || ((digitalRead(magnet)== HIGH) && (digitalRead(touch)==HIGH) && (digitalRead(laser)==LOW))){   
    count = count + 1;
    if (count == 1){
      digitalWrite(buzzer, HIGH);
      delay(100);
      digitalWrite(buzzer, LOW);  
    }
    myservo.write(0);
    delay(900);       
  }
  else {
    count = 0;
    myservo.write(90);    
    delay(150);
  }
}

