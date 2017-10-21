#define d7 13//GPIO13 on nodeMCU on digital pin 7

void setup(){
  //initialize digital pin as an output
  pinMode(d7,OUTPUT);
}

void loop(){
  digitalWrite(d7, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(1000);            // wait for a second
  digitalWrite(d7,LOW);   // turn the LED off by making the voltage LOW
  delay(1000);            // wait for a second
}

