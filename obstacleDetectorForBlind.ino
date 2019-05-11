/*
    Project : Obstacle Detector for Blind/Visually Impaired People
    by Cybernetics Robo Academy
    https://www.cyberneticsroboacademy.com
    Credit : Syed Razwanul Haque(Nabil), CTO, Cybernetics Robo Academy
    nabil@cruxbd.com
    Orpon Chanda and Nihal , Student, Cybernetics Robo Academy
    Cybernetics Robo Academy is a Institute under Cybernetics Robo Limited
    Library Used : https://github.com/pololu/vl53l0x-arduino
  The range readings are in units of mm. */
int vibratorPin = 13;

#include <Wire.h>
#include <VL53L0X.h>

VL53L0X sensor;

void setup()
{
  Wire.begin();
  pinMode(vibratorPin, OUTPUT);
  sensor.init();
  sensor.setTimeout(2000);

  // Start continuous back-to-back mode (take readings as
  // fast as possible).  To use continuous timed mode
  // instead, provide a desired inter-measurement period in
  // ms (e.g. sensor.startContinuous(100)).
  sensor.startContinuous();
}

void loop()
{
  int val = sensor.readRangeContinuousMillimeters();
  Serial.print(val);
  if (sensor.timeoutOccurred()) {
    Serial.print(" TIMEOUT");
  }
  else if (sensor.readRangeContinuousMillimeters() < 450) {
    digitalWrite(vibratorPin, HIGH);
  }

  else {
    digitalWrite(vibratorPin, LOW);
  }
}
