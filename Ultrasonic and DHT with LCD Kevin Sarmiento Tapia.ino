/*
  Ultrasonic and DHT with LCD 

  This program's goal is to use the DH11 to increase the accuracy of the Ultrasonic sensor.

  The programs theme is the use of "#include 'NewPing.h'" to be able to use Ultrasonic Sensor.
*/
#include "DHT.h";// Includes the library fo the DHT11.
#include "NewPing.h"// Include NewPing Library
#define DHTPIN 7 // The DHTPIN is connected to pin 7 in the Arduino board.  
#define DHTTYPE DHT11// DHT Type is DHT11.
#define TRIGGER_PIN 12//The TRIGGER_PIN is connected to pin 12 in the Arduino board.  
#define ECHO_PIN 13//The ECHO_PIN connected to pin 12 in the Arduino board.  
#define MAX_DISTANCE 400//the maximun distance is 400cm.
 
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);// Inicialize ultrasonic sensor.
 
float hum;// Float variable named "hum".
float temp;// Float variable named "temp".
float duration;// Float variable named "duration".
float distance;// Float variable named "distance".
float soundsp;// Float variable named " soundsp".
float soundcm;// Float variable named  "soundcm".
int iterations = 5;// Float variable named  "iterations" with a value of 5.
 
DHT dht(DHTPIN, DHTTYPE);// Inicialize DHT11.

#include <LiquidCrystal.h>// Includes the library for the LCD.
LiquidCrystal lcd(0, 1, 8, 9, 10, 11);// Sets the pins LCD is connected to.
 
void setup() {// This program will run once.
  lcd.begin(16, 2);// Set up the LCD's numbers of columns and rows, I will use it to display distance.
  dht.begin();//DHT11 starts to measure.
  Serial.begin(9600);//Start serial monitor, I will use it to check other measurements (sound, hum and temp).
}
 
void loop() {// This program will run forever.
 
  delay(2000);// Wait for 2 seconds between measurements.
   
    hum = dht.readHumidity();// Read humidity.
    temp= dht.readTemperature();// Read temperature in Celsius.
    
    soundsp = 331.4 + (0.606 * temp) + (0.0124 * hum);// Calculate the Speed of Sound in M/S
    soundcm = soundsp / 10000;// Convert to cm/ms
    
  duration = sonar.ping_median(iterations);
  
  distance = (duration / 2) * soundcm;// Calculate the distance
  
    Serial.print("Sound: ");
    Serial.print(soundsp);
    Serial.print(" m/s, ");
    Serial.print("Humid: ");
    Serial.print(hum);
    Serial.print(" %, Temp: ");
    Serial.print(temp);
    Serial.println(" C ");

    lcd.setCursor(0, 0);// Set the cursor to column 0, row 0 
    lcd.print("Distance: ");// Print "Distance: " in LCD
    if (distance >= 400 || distance <= 2) {// If the distance is greater than 400cm and lower than 2cm, then:
    lcd.print("Out of range");// Print "Out of range" in LCD.
    }
    else {// If none of the above is true, then:
    lcd.print(distance);// Print distance value in LCD.
    lcd.print(" cm");// Print " cm" in LCD.
    delay(500);// Wait 1/2 of a second.
    }
}
