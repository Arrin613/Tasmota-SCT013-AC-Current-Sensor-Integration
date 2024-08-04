# Tasmota-SCT013-AC-Current-Sensor-Integration

## Overview

This repository contains the modified TASMOTA firmware integrated with the DF Robot SCT013 AC current sensor. The modifications enable the TASMOTA firmware to read and process AC current values from the SCT013 sensor.

## Integration Steps

1. Review TASMOTA Firmware:
   - Familiarize yourself with the TASMOTA firmware structure.

2. Utilize DF Robot SCT013 Example Code:
   - Review the example code provided in the DF Robot SCT013 repository for reading AC current values.

3. Code Modifications:
   - Added sensor definitions for SCT013 in `src/user_config.h`.
   - Implemented the `readACCurrent()` function in `src/Sonoff_Sensors.cpp`.
   - Updated the main loop to include SCT013 sensor readings.

4. Compile and Test:
   - Instructions on compiling the firmware and uploading it to the device.
   - Verify the integration by checking AC current readings.

## Files

- `src/user_config.h`: Sensor definitions.
- `src/Sonoff_Sensors.cpp`: Implementation of sensor reading function and integration into the main loop.

## Contact

For any questions or issues, please contact Arin Soni at arinsoni1905@gmail.com
