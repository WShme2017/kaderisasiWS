// include the library code:
#include <LiquidCrystal.h>
#include <Keypad.h> //import keypad library
#include <math.h> // import library math
///////////////////////////////////////////////////////VARIABLES///////////////////////////////////////////
//VARIABLES TO PARSE FLOATING ANSWER INTO WHOLE NUMBER AND DECIMAL PARTS///
char outresult[20];
String OutResult;
int decimal_location;
String whole_number;
String decimal_number;

//VARIABLES USED TO SCROLL TOP LINE//
bool STOP;
bool cek;
int de = 0;

//FOR OPERATORS//
char operators;
//INPUT VARIABLES//
char input[9]; //buffer for input characters
float firstnumber = 0; //stores first number
float secondnumber = 0;  //stores second number
float response = 0;  //stores "answer"
float sum1 = 0; //stores input 1
float sum2 = 0; //stores input 2
bool positive = 1; //indicates positive number
int lcdcolumnindexrow1 = 1; // used to indicate location of input key

//FUNCTION VARIABLES//
int function = 9;  //stores currently selected function
const int number_of_functions = 10;
int mode = 2; // select normal operation (1) or mystery function (0)
bool toggle = 1;
int level = 0;  // stores level for the game
const int number_of_levels = 10;

///////////////////////////////////////////////////////KEYPAD SETUP///////////////////////////////////////
const byte ROWS = 4; // Four rows
const byte COLS = 3; // Four columns
// Define the Keymap
char keys[ROWS][COLS] = {
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'},
  {'*', '0', '#'}
};

// Connect keypad ROW0, ROW1, ROW2 and ROW3 to these Arduino pins.
byte rowPins[ROWS] = { 0, 6, 7, 8 };
// Connect keypad COL0, COL1, COL2, and COL3 to these Arduino pins.
byte colPins[COLS] = { 9, 10, 13 };

// Create the Keypad
Keypad kpd = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

///////////////////////////////////////////////////////LCD SETUP///////////////////////////////////////
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
void setup() {
  // put your setup code here, to run once:
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("WSCalc 2017");
  // DISPLAY ROW 1
  for (int i = 0; i < 3; i++) {
    lcd.setCursor(0, 1);
    lcd.write("Made by Kelompok B&G");
    delay(500);
    lcd.setCursor(0, 1);
    lcd.write("ade by Kelompok B&G");
    delay(500);
    lcd.setCursor(0, 1);
    lcd.write("e by Kelompok B&G");
    delay(500);
    lcd.setCursor(0, 1);
    lcd.write(" by Kelompok B&G");
    delay(500);
  }
  //CLEAR LCD
  lcd.clear();
}
  
void loop() {
  sum1=0;
  sum2=0;
  firstnumber = 0;
  secondnumber = 0;
  int c1=0; //cursor input1
  ////////////////////////INPUT A//////////////////////////////
  lcd.clear();
  STOP = false;
  cek = true;
  do
  {
    // put your main code here, to run repeatedly:
    lcd.setCursor(0, 0);
    lcd.print("Masukan input A:");
    char key = kpd.getKey();
    if (key)
    {
      // set the cursor to column 9, line 1
      //(note: line 1 is the second row, since counting begins with 0):
      lcd.setCursor(c1, 1);
      //Print the detected key
      lcd.print(key);
      ++c1;
      sum1 = sum1*10 + firstnumber;
      switch (key) {
        
        case '1':
          firstnumber = 1;
          cek = true;
          break;
        case '2':
          firstnumber = 2;
          cek = true;
          break;
        case '3':
          firstnumber = 3;
          cek = true;
          break;
        case '4':
          firstnumber = 4;
          cek = true;
          break;
        case '5':
          firstnumber = 5;
          cek = true;
          break;
        case '6':
          firstnumber = 6;
          cek = true;
          break;
        case '7':
          firstnumber = 7;
          cek = true;
          break;
        case '8':
          firstnumber = 8;
          cek = true;
          break;
        case '9':
          firstnumber = 9;
          cek = true;
          break;
        case '0':
          firstnumber = 0;
          cek = true;
          break;
        case '*':
          STOP = true;
          break;
      }
      
    }
  } while (STOP == false);
  lcd.setCursor(0, 1);
  /////////////////OPERATORS////////////////////////
  lcd.clear();
  bool STOP2 = true;
  int change = 1;
  do {
    lcd.setCursor(0, 0);
    lcd.print("Masukan Operator:");
    char key = kpd.getKey();
    ///PENGEMBALI OPERATOR LOOP///
    if (change == 6) {
      change = 1;
    }
    switch (key) {
      case '*': if (change == 1) {
          lcd.setCursor(0, 1);
          lcd.print('*');
          change = change + 1;
        } else if (change == 2) {
          lcd.setCursor(0, 1);
          lcd.print('/');
          change = change + 1;
        } else if (change == 3) {
          lcd.setCursor(0, 1);
          lcd.print('+');
          change = change + 1;
        } else if (change == 4) {
          lcd.setCursor(0, 1);
          lcd.print('-');
          change = change + 1;
        } else {
          lcd.setCursor(0, 1);
          lcd.print("^");
          change = change + 1;
        }
        break;

      case '#':
        STOP2 = false;
        break;
    }

  } while (STOP2 == true);



  ////////////////INPUT B//////////////////////////
  int c2=0; //cursor input 2
  lcd.clear();
  STOP = false;
  cek = true;
  do
  {
    // put your main code here, to run repeatedly:
    lcd.setCursor(0, 0);
    lcd.print("Masukan input B:");
    char key = kpd.getKey();
    if (key)
    {
      // set the cursor to column 9, line 1
      //(note: line 1 is the second row, since counting begins with 0):
      lcd.setCursor(c2, 1);
      //Print the detected key
      lcd.print(key);
      ++c2;
      sum2 = sum2*10 + secondnumber;
      switch (key) {
        case '1':
          secondnumber = 1;
          cek = true;
          break;
        case '2':
          secondnumber = 2;
          cek = true;
          break;
        case '3':
          secondnumber = 3;
          cek = true;
          break;
        case '4':
          secondnumber = 4;
          cek = true;
          break;
        case '5':
          secondnumber = 5;
          cek = true;
          break;
        case '6':
          secondnumber = 6;
          cek = true;
          break;
        case '7':
          secondnumber = 7;
          cek = true;
          break;
        case '8':
          secondnumber = 8;
          cek = true;
          break;
        case '9':
          secondnumber = 9;
          cek = true;
          break;
        case '0':
          secondnumber = 0;
          cek = true;
          break;
        case '*':
          STOP = true;
          break;
      }
    }
  } while (STOP == false);
 
  ////OPERATING/////
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("HASILNYA >.<");
  char key = kpd.getKey();
  if (change == 2) {
    lcd.setCursor(0, 1);
    lcd.print(sum1 * sum2);
  } else if (change == 3) {
    lcd.setCursor(0, 1);
    lcd.print(sum1 / sum2);
  } else if (change == 4) {
    lcd.setCursor(0, 1);
    lcd.print(sum1 + sum2);
  } else if (change == 5) {
    lcd.setCursor(0, 1);
    lcd.print(sum1 - sum2);
  } else {
    lcd.setCursor(0, 1);
    lcd.print(pow(sum1,sum2));
  }
  delay(5000);
}


