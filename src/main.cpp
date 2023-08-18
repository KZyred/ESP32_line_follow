#include <main.h>

uint8_t inputPin[5]={26,25,33,32,35};
esp32_motor leftMotor(14,27,5,6,50000,10);
esp32_motor rightMotor(13,12,7,8,50000,10);
line_status error(inputPin);

PIDcontroller lineFollow(KP,KI,KD);

void setup() {
  // Serial.begin(9600);
}

void loop() {
  error.updateLineStatus();
  lineFollow.calculateOutput(error.getError());
  leftMotor.Run(BASE_PWM+lineFollow.output);
  rightMotor.Run(BASE_PWM-lineFollow.output);
  // lineFollow.printError();
}
