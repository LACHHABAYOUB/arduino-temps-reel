#include <LiquidCrystal_PCF8574.h>
#include <Wire.h> 

LiquidCrystal_PCF8574 lcd(0x3f);  // set the LCD address to 0x27 for a 16 chars and 2 line display
     
    const int trigPin = 2; // ultransonic Sensor
    const int echoPin = 3; //ultransonic Sensor
    // defines variables
    long duration;
    float distanceCM;
    float distanceINCH;
    
void setup() {

    lcd.begin(16,2);
      
    pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
    pinMode(echoPin, INPUT); // Sets the echoPin as an Input
    pinMode(5, OUTPUT);
    Serial.begin(9600); // Starts the serial communication
}
void loop() {
     
    // Clears the trigPin
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    // Sets the trigPin on HIGH state for 10 micro seconds
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    // Reads the echoPin, returns the sound wave travel time in microseconds
    duration = pulseIn(echoPin, HIGH);
    // Calculating the distance
    distanceCM= duration*0.034/2;
    distanceINCH = duration*0.0133/2;
    // Prints the distance on the Serial Monitor
    Serial.print("Distance: ");
    Serial.println(distanceCM);
  lcd.setBacklight(255);
  lcd.setCursor(0,0);                  // 3 place on row 0 
  lcd.print("Dist: ");
  lcd.print(distanceCM);
  lcd.print(" cm   ");
  lcd.setCursor(0,1);
  lcd.print("Dist: ");
  lcd.print(distanceINCH);
  lcd.print(" inch");
  if (distanceCM > 10) 
    digitalWrite(5, 1);
  else 
    digitalWrite(5, LOW);

  delay(300);
}

