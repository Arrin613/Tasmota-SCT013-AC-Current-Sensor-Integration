# Tasmota-SCT013-AC-Current-Sensor-Integration

## Overview

This repository contains the modified TASMOTA firmware integrated with the DF Robot SCT013 AC current sensor. The modifications enable the TASMOTA firmware to read and process AC current values from the SCT013 sensor.

## Integration Steps

1.Clone the TASMOTA Repository :-Clone the TASMOTA firmware repository to your local machine: by uisng this command-

- git clone https://github.com/arendst/Tasmota.git
- cd Tasmota



2. Utilize DF Robot SCT013 Example Code:
   - Define the SCT013 sensor constants in the appropriate configuration file. Modify or create a file in the TASMOTA firmware where you can add new sensor configurations. For example, modify 
     user_config.h

3. Code Modifications: Add the code to read from the SCT013 sensor. Create or modify a file in the src directory, such as Sonoff_Sensors.cpp, to include this function:
   
   - Added sensor definitions for SCT013 in `src/user_config.h`.
   - Implemented the `readACCurrent()` function in `src/Sonoff_Sensors.cpp`.
     
     Integrate the sensor reading into the main loop or relevant processing function. Modify Sonoff_Sensors.cpp 
     
   - Updated the main loop to include SCT013 sensor readings.
  
   

5. Compile and Test:
   - Instructions on compiling the firmware and uploading it to the device.
   - Verify the integration by checking AC current readings.

## Files

- `src/user_config.h`: Sensor definitions.
- `src/Sonoff_Sensors.cpp`: Implementation of sensor reading function and integration into the main loop.

## Contact

For any questions or issues, please contact Arin Soni at arinsoni1905@gmail.com
