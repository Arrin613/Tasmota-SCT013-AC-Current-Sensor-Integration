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
