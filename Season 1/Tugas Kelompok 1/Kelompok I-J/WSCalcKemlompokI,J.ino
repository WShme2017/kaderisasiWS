#include <LiquidCrystal.h>
#include <Key.h>
#include <Keypad.h>
#include <math.h>

LiquidCrystal lcd(13,12,11,10,9,8);
int sum;
float sumfl;
int button1=6;
int i;
int A=0;
int B=0;
int intA;
int intB;
String str="";
String sumstr="";
String tempchar;
const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
char keys[ROWS][COLS] = 
{
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {A0,A1,A2,A3}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {5,4,3,2}; //connect to the column pinouts of the keypad
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
bool cekmode=false;

void setup(){
   Serial.begin(9600);
   pinMode(button1, INPUT_PULLUP);
}
  
void loop(){
  cekmode=false;
  char key = keypad.getKey();
  if (digitalRead(button1)==LOW){ // ketika tdk mendeteksi inut pullup dari button
    delay(500);
    B=B+1;
    B=B%5;
    lcd.clear();
  }
 switch (B) {
    case 0:
        lcd.setCursor(0, 0);
      lcd.print("WSCALCULATOR"); //welcome screen 
        delay(2000);
      for (i = 0 ; i < 16; i ++) {
       lcd.scrollDisplayRight(); 
          if (digitalRead(button1)==LOW){ //jika input pullup = low, running text jalan
            delay(500);B=B+1;  
            lcd.clear(); 
            lcd.setCursor(0,0);
            break;}
         delay(700);
      }
    break;   
    
    case 1:
        while (not(cekmode)) {
      key = keypad.getKey();
          tempchar=tempchar+key;
          if ((key)&& (tempchar!="*" && tempchar!="#" && tempchar!="A" && tempchar!="B" && tempchar!="C" && tempchar!="D")){ // selama tdk ada simbol, maka membaca input dari keypad
              Serial.println(key);
              lcd.print(key);
              delay(200);
              str=str+key;
          }
          if(digitalRead(button1)==LOW){
            delay(500);
            cekmode=true;
            B=B+1;
            lcd.clear();
            lcd.setCursor(0,0); 
            intA=str.toInt();
            str="";
            Serial.println(intA);//menampilkan input angka ke lcd
          } 
        }
    break;
   
      case 2:
        while(not(cekmode)){
          key=keypad.getKey();
          tempchar="";
         if (key){
           tempchar=tempchar+key;
           delay(300);
           Serial.println(tempchar);
           if (tempchar=="#") {
              A =A+1;
              A = A % 13 ;
             Serial.println(A);
             tempchar="";
           } else if (tempchar=="*") {
              A =A-1;
              A = A % 13 ;
             Serial.println(A);   
             tempchar="";
           }
           switch (A) { // print untu setiap operator
            case 1:
             lcd.print("+             ");
             break;  
            case 2:
             lcd.print("-             ");
             break;
            case 3:
             lcd.print("X             ");
             break;
            case 4 :
             lcd.print("sin             ");
             break;
            case 5 :
             lcd.print("cos             ");
             break;
            case 6 :
             lcd.print("tan              " );
             break;
            case 7:
             lcd.print("sqrt             ");
             break; 
            case 8:
             lcd.print("power            ");
             break; 
            case 9:
             lcd.print("Binary          ");
             break; 
            case 10:
             lcd.print("Hexadecimal     ");
             break;
            case 11:
             lcd.print("Log             ");
             break;
            case 12:
             lcd.print("Exp             ");
             break;
            case -12:
             lcd.print("+             ");
             break; 
            case -11:
             lcd.print("-             ");
             break;
            case -10:
             lcd.print("X             ");
             break;
            case -9 :
             lcd.print("sin           ");
             break;
            case -8 :
             lcd.print("cos         ");
             break;
            case -7 :
             lcd.print("tan          ");
             break;
            case -6:
             lcd.print("sqrt          ");
             break; 
            case -5:
             lcd.print("power        ");
             break; 
            case -4:
             lcd.print("Binary        ");
             break; 
            case -3:             
             lcd.print("Hexadecimal   ");
             break;
            case -2:
             lcd.print("Logaritma    ");
             break;
            case -1:
             lcd.print("exponen      ");
             break;
            case 0:
             lcd.print("/             ");
             break;
            }
           lcd.setCursor(0,0);
          } 
          
          if(digitalRead(button1)==LOW){
            delay(500);
            cekmode=true;
            B=B+1;
            lcd.clear();
            lcd.setCursor(0,0); 
            Serial.println(intA);
            Serial.println(A); 
          } 
          
        }
      break;
   case 3:
        while (not(cekmode)) {
      key = keypad.getKey();
          if (key){
              Serial.println(key);
              lcd.print(key);
              delay(200);
              str=str+key; //menerima input angka kedua dari keypad
          }
          if(digitalRead(button1)==LOW){
            delay(500);
            cekmode=true;
            B=B+1;
            lcd.clear();
            lcd.setCursor(0,0); 
            intB=str.toInt();
            str="";
            Serial.println(intB);  // menampilkan angka kedua di layar lcd
          } 
        }
    break;
   case 4:
   while (not(cekmode)){
     lcd.setCursor(1,0);
     switch (A) { 
       case 1:
          sum=intA+intB; // untuk penjumlahan
          lcd.print(sum);
          delay(500);
       break;
       case 2:
          sum=intA-intB; //untuk pengurangan
          lcd.print(sum);
          delay(500);
       break;
       case 3:
          sum=intA*intB; //untuk perkalian
          lcd.print(sum);
          delay(500);
       break;
       case 4:
          sum=intA*sin(intB*PI/180); // untuk sin  
          lcd.print(sum);
          delay(500);
       break;
       case 5:
          sum=intA*cos(intB*PI/180); //untuk cos     
          lcd.print(sum);
          delay(500);
       break;
       case 6:
          sum=intA*tan(intB*PI/180);      //untuk tangen    
          lcd.print(sum);
          delay(500);
       break;
       case 7:
          sum=intA*sqrt(intB);          //untuk akar
          lcd.print(sum);
          delay(500);
       break;
       case 8:
          sum=pow(intA,intB);          //untuk kuadrat 
          lcd.print(sum);
          delay(500);
       break;
       case 9:
          sumstr=String(intB, BIN);      //untuk biner     
          lcd.print(sumstr);
          delay(500);
       break;
       case 10:
          sumstr=String(intB, HEX);        //untuk hexadecimal   
          lcd.print(sum);
          delay(500);
       break;
       case 11:
          sum=intA*log10(intB);           //untuk logaritma
          lcd.print(sum);
          delay(500);
       break;
       case 12:
          sum=intA*exp(intB);           //untuk exponential
          lcd.print(sum);
          delay(500);
       break;
       case -12:
          sum=intA+intB;               //untuk angka negatif
          lcd.print(sum);
          delay(500);
       break;
       case -11:
          sum=intA-intB;              //untuk angka negatif
          lcd.print(sum);
          delay(500);
       break;
       case -10:
          sum=intA*intB;
          lcd.print(sum);
          delay(500);
       break;
       case -9:
          sum=intA*sin(intB*PI/180);          
          lcd.print(sum);
          delay(500);
       break;
       case -8:
          sum=intA*cos(intB*PI/180);          
          lcd.print(sum);
          delay(500);
       break;
       case -7:
          sum=intA*tan(intB*PI/180);          
          lcd.print(sum);
          delay(500);
       break;
       case -6:
          sum=intA*sqrt(intB);          
          lcd.print(sum);
          delay(500);
       break;
       case -5:
          sum=pow(intA,intB);           
          lcd.print(sum);
          delay(500);
       break;
       case -4:
          sumstr=String(intB, BIN);           
          lcd.print(sumstr);
          delay(500);
       break;
       case -3:
          sumstr=String(intB, HEX);           
          lcd.print(sum);
          delay(500);
       break;
       case -2:
          sum=intA*log10(intB);           
          lcd.print(sum);
          delay(500);
       break;
       case -1:
          sum=intA*exp(intB);           
          lcd.print(sum);
          delay(500);
       break;
       case 0:
          sumfl:intA/intB;
          lcd.print(sumfl);
          delay(500);
       break;
       }
     if(digitalRead(button1)==LOW){
            delay(500);
            cekmode=true;
            B=0;
            lcd.clear();
          lcd.print("WSCALCULATOR"); //back to welcome screen
            lcd.setCursor(0,0); 
            str="";

          } 
     }
   
      
   break;
   }

  delay(10);
}
