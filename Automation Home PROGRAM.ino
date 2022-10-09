#define BLYNK_PRINT Serial

#include <Servo.h>
#include <ESP8266WiFi.h>
#include "BlynkSimpleEsp8266.h"
Servo tap_servo;
int sensor_pin =D7;
int tap_servo_pin =D2;
int val;

char auth[] = "YLHf5M0dLBn1dzvjlxu3Lb7DSZ13MVjv";

char ssid[] = "scientist";
char pass[] = "mainak123";

void setup()
{
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
pinMode(sensor_pin,INPUT);
  tap_servo.attach(tap_servo_pin);
}

void loop()
{
  Blynk.run();

 val = digitalRead(sensor_pin);

  if (val==0)
  {tap_servo.write(0);
  }
  if (val==1)
  {tap_servo.write(90);
    }
}
