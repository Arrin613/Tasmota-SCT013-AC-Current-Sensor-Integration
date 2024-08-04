// Add this function to read AC current
float readACCurrent() {
    int rawValue = analogRead(SCT013_PIN);          // Read the analog value
    float voltage = (rawValue / 1024.0) * SCT013_VOLTAGE; // Convert raw value to voltage
    float current = (voltage / SCT013_SENSITIVITY) * 1000.0; // Convert voltage to current (mA)
    return current;
}

// ntegrate the sensor reading into the main loop or the appropriate processing function

// Modify the loop or processing function

void loop() {
    // Call the function to read AC current
    float current = readACCurrent();
    // Process or display the current value
    Serial.print("AC Current: ");
    Serial.print(current);
    Serial.println(" mA");
    delay(1000); // Delay for readability
}
