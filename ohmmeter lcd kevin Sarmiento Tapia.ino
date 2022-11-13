/*
 Ohmmeter with LCD

 The program's goal is to measure the value of a resistor with an unknow resistance.

 The theme is the use of "byte ohms[8] {" to intsert the ohms' symbol: Ω.
*/
#include <LiquidCrystal.h>// Includes the library for the LCD.

LiquidCrystal lcd(0, 1, 8, 9, 10, 11); // Sets the pins LCD is connected to.
byte ohms[8] {// This function allows us to write any symbol we want in a column of the LCD; 0 are empty blocks and 1 are fulled blocks. 
  0b00000,
  0b01110,
  0b10001,
  0b10001,
  0b10001,
  0b01010,
  0b11011,
  0b00000

};
float voltacross;// Float variable named "voltacross".
float voltage;// Float variable named "voltage".
float resistance;// Float variable named "resistance".
float current;// Float variable named "current".
float a=5;// Float variable named "a" with a value of 5.
float b=1023;// Float variable named "b" with a value of 1023.

void setup() {// This program will run once.
lcd.begin(16, 2);// Set up the LCD's numbers of columns and rows.
// Column 0 is the first column, since counting starts with 0.
// row 0 is the first row, since counting starts with 0.
lcd.createChar(0, ohms);// create the chart 0 (the first chart since counting starts with 0).
lcd.setCursor(0, 0);// Set the cursor to column 0, row 0.
lcd.print("ohms=");// Print "ohms=" in LCD.
}
void loop() {// This program will run forever.
int sensorValue = analogRead(A0);// Int variable named "sensorValue" equals the value of analogRead(A0).
voltage = sensorValue*a/b;// Calculates the voltage. 
voltacross = 5-voltage;// Calculates the voltage across.
current = voltacross/1000;// Calculates the current.
resistance= voltage/current;// Calculates the resistance.

lcd.setCursor(5,0);// Set the cursor to column 5, row 0 
lcd.print(resistance);// Print resistance value in LCD
lcd.write(byte(0));// Write the character created in "byte ohms[8]"" (byte(0) means the first character written).
}


