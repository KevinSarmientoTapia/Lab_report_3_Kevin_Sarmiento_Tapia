/*
 Voltmeter with LCD

 The program's goal is measure the voltage value an display it in a LCD.

 The theme is the use of "#include <LiquidCrystal.h>" to use the LCD as a screen to display the value.
*/
#include <LiquidCrystal.h>// Includes the library for the LCD.

LiquidCrystal lcd(0, 1, 8, 9, 10, 11);// Sets the pins LCD is connected to.

float volt;// Float variable named "volt".
float a=5;// Float variable named "a" with a value of 5.
float b=1023;// Float variable named "b" with a value of 1023.

void setup() {// This program will run once.

lcd.begin(16, 2);// Set up the LCD's numbers of columns and rows.
// Column 0 is the first column, since counting starts with 0.
// row 0 is the first row, since counting starts with 0.
lcd.setCursor(0, 0);// Set the cursor to column 0, row 0 
lcd.print("Value=");// Print "Value=" in LCD

lcd.setCursor(0, 1);// Set the cursor to column 0, row 1.
lcd.print("Voltage=");// Print "Voltage=" in LCD.

}

void loop() {// This program will run forever.

int sensorValue = analogRead(A0);// Int variable named "sensorValue" equals the value of analogRead(A0).
volt = sensorValue*a/b;// calculates the voltage.

lcd.setCursor(7,0);// Set the cursor to column 7, row 0.
lcd.print(sensorValue);// Print sensorValue's value in LCD

lcd.setCursor(9, 1);// Set the cursor to column 9, row 1.
lcd.print(volt);// Print volt's value in LCD.

}
