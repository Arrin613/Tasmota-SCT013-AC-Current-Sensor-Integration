# DF Robot SCT013 AC Current Sensor Integration with Tasmota

This repository provides an example of how to integrate the DF Robot SCT013 AC current sensor with Tasmota firmware.

## Arduino Example

The `Arduino/DFRobot_ACS_Example.ino` file demonstrates how to read AC current values using the DF Robot SCT013 sensor with an Arduino.

## Tasmota Firmware

### Steps to Integrate the Sensor with Tasmota:

1. Clone the Tasmota firmware repository:
    ```sh
    git clone https://github.com/arendst/Tasmota.git
    cd Tasmota
    ```

2. Define the sensor in `xsns_sensor.h`:
    ```cpp
    #define USE_MY_AC_SENSOR   // Enable support for the DF Robot AC current sensor
    ```

3. Create a new sensor file `xsns_99_my_ac_sensor.ino` in the `tasmota/tasmota/xsns_` directory:
    ```cpp
    // xsns_99_my_ac_sensor.ino
    #ifdef USE_MY_AC_SENSOR

    #include <DFRobot_ACS.h>

    const int sensorPin = A0; // Analog input pin for AC current sensor
    DFRobot_ACS acs(sensorPin);

    void MyACSensorInit() {
      acs.calibrate();
    }

    void MyACSensorRead() {
      float current = acs.readCurrent();

      char value[16];
      snprintf_P(value, sizeof(value), PSTR("%0.2f"), current);

      // Publish the current value
      snprintf_P(mqtt_data, sizeof(mqtt_data), PSTR("{\"ACCurrent\":%s}"), value);
      MQTT_PublishPrefixTopic_P(RESULT_OR_TELE, PSTR(D_RSLT_STATE), mqtt_data);
    }

    boolean Xsns99(uint8_t function) {
      boolean result = false;
      switch (function) {
        case FUNC_INIT:
          MyACSensorInit();
          result = true;
          break;
        case FUNC_LOOP:
          MyACSensorRead();
          result = true;
          break;
        case FUNC_JSON_APPEND:
          break;
        case FUNC_COMMAND:
          break;
        default:
          break;
      }
      return result;
    }

    #endif // USE_MY_AC_SENSOR
    ```

4. Register the sensor in `xsns_00_core.ino`:
    ```cpp
    #ifdef USE_MY_AC_SENSOR
      { XSNS_99, &Xsns99, "MyACSensor" },
    #endif
    ```

5. Modify the `platformio.ini` file to include the build flag:
    ```ini
    [common]
    ; Add your sensor definition to the build flags
    build_flags = -DUSE_MY_AC_SENSOR
    ```

6. Compile and upload the firmware:
    ```sh
    platformio run -e <your_environment> -t upload
    ```

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
