#include <Arduino.h>
#include <DFRobot_ACS.h>

// Define the pin where the sensor is connected
const int sensorPin = A0; // Analog input pin

DFRobot_ACS acs(sensorPin);

void setup() {
  // Initialize serial communication
  Serial.begin(9600);
  acs.calibrate();
}

void loop() {
  // Read the current value from the sensor
  float current = acs.readCurrent();

  // Print the current value to the serial monitor
  Serial.print("Current: ");
  Serial.print(current);
  Serial.println(" A");

  // Wait for a short period before reading the value again
  delay(1000);
}

int main() {
  setup();
  while (true) {
    loop();
  }
  return 0;
}
