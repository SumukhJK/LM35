// Include necessary libraries
#include <Arduino.h>

// Define pin connections
#define LM35_PIN A0
#define LED_PIN 13

// Define temperature thresholds
#define LOW_TEMP_THRESHOLD 30
#define HIGH_TEMP_THRESHOLD 31

// Variables to store temperature data
int temperature;
int lastTemperature = -1;

// Variable to store last LED state
bool lastLEDState = LOW;

// Function prototypes
void readTemperature();
void controlLED();

void setup() {
  // Setting LED pin as output
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  // Reading temperature
  readTemperature();

  // Controlling LED based on temperature
  controlLED();
}

// Function to read temperature from LM35 temperature sensor
void readTemperature() {
  // Reading analog value from LM35 temperature sensor
  int sensorValue = analogRead(LM35_PIN);

  // Convert analog value to temperature in degree Celsius
  temperature = (sensorValue * 500) / 1024;
}

// Function to control onboard LED based on temperature readings
void controlLED() {
  // Checking if temperature has changed
  if (temperature != lastTemperature) {
    // Update last temperature
    lastTemperature = temperature;

    // Checking temperature threshold
    if (temperature < LOW_TEMP_THRESHOLD) {
      // Blink LED every 250 milliseconds
      digitalWrite(LED_PIN, lastLEDState);
      lastLEDState = !lastLEDState;
      delay(250);
    } else if (temperature > HIGH_TEMP_THRESHOLD) {
      // Blink LED every 500 milliseconds
      digitalWrite(LED_PIN, lastLEDState);
      lastLEDState = !lastLEDState;
      delay(500);
    }
  }
}
