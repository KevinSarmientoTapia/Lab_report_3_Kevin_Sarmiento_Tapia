/*
 DHT11 with LCD

 This program's goal is to use the DHT11 to measure temperature and humidity and display it in the LCD.

 The theme is "#include 'DHT.h'" to be able to use the DHT11.
*/
#include "DHT.h"// Includes the library fo the DHT11.
#define DHTPIN 2// The DHTPIN is connected to pin 2 in the Arduino board.  
#define DHTTYPE DHT11// The type of DHT is the DHT11.  

DHT dht(DHTPIN, DHTTYPE);// Inicialize DHT11.
#include <Wire.h>// To include Wire.h in the program.                

#include <LiquidCrystal.h>// Includes the library for the LCD.
LiquidCrystal lcd(0, 1, 8, 9, 10, 11);// Sets the pins LCD is connected to.

void setup() {// This program will run once.
lcd.begin(16, 2);   // Set up the LCD's numbers of columns and rows.
// Column 0 is the first column, since counting starts with 0.
// row 0 is the first row, since counting starts with 0.             
dht.begin();//DHT11 starts to measure.
}

void loop() {// This program will run forever.
delay(2000);// Wait for 2 seconds between measurements.
float h = dht.readHumidity();// Read humidity.
float t = dht.readTemperature();// Read temperature in Celsius.
float f = dht.readTemperature(true);// Read temperature in Fahrenheit.
float hif = dht.computeHeatIndex(f, h);// Compute heat index in Fahrenheit.
float hic = dht.computeHeatIndex(t, h, false);// Compure hear index in Celsius.

lcd.setCursor(0,0);// Set cursor to column 0, row 0.            
lcd.print("Hum: ");// Print "Hum: " in LCD
lcd.print(h);// Print the value of h in LCD.
lcd.print(" % ");// Print " % " in LCD.
lcd.setCursor(0,1);// Set cursor to column 0, row 1.
lcd.print("Temp: ");// Print "Temp: " in LCD.
lcd.print(t);// Print the value of t in LCD.
lcd.print(" *C ");// Print " *C " in LCD.
}
