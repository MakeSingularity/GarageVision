#include "esp_camera.h"
#include <Arduino.h>
#include <WiFi.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include <iostream>
#include <sstream>
#include <ESP32Servo.h>

#define DUMMY_SERVO1_PIN 12 //We need to create 2 dummy servos.
#define DUMMY_SERVO2_PIN 13 //So that ESP32Servo library does not interfere with pwm channel and timer used by esp32 camera.

#define PAN_PIN 14
#define TILT_PIN 15

Servo dummyServo1;
Servo dummyServo2;
Servo panServo;
Servo tiltServo;
