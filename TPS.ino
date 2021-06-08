#include <Encoder.h>
#include "pwm.hpp"

#define PIN_ENCODER_1 2
#define PIN_ENCODER_2 3
#define PIN_OUTPUT 10
#define PWM_LEVEL_MIN 104
#define PWM_LEVEL_MAX 945
#define ENCODER_VALUE_MAX 570

Encoder encoder(PIN_ENCODER_2, PIN_ENCODER_1);
PWM pwm(PWM_LEVEL_MIN, PWM_LEVEL_MAX, ENCODER_VALUE_MAX);

void setup() {
  TCCR1A = 0b00000011;
  TCCR1B = 0b00001001;
  
  pinMode(PIN_OUTPUT, OUTPUT);
  Serial.begin(9600);

  pwm.setFixEnable(true);
}

void loop() {
  auto position_current = encoder.read();
  
  if (position_current < 0) {
    encoder.write(0);
    position_current = 0;
  }

  auto pwm_level = pwm.calculate(position_current);
  
  analogWrite(PIN_OUTPUT, pwm_level);
}
