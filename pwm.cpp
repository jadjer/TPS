//
// Created by jadjer on 8.06.21.
//

#include "pwm.hpp"

PWM::PWM(int min, int max)
    : k_min_(min), k_max_(max) {

  divisorUpdate(0);
}

PWM::~PWM() = default;

void PWM::setPositionMax(long int position) {
  divisorUpdate(position);
}

void PWM::setFixEnable(bool value) {
  fix_ = value;
}

int PWM::calculate(long int position) {
  if (position > position_max_) {
    divisorUpdate(position);
  }

  int pwm_level  = (position / divisor_) + k_min_;

  if (fix_) {
    pwm_level = fix255(pwm_level);
  }

  return pwm_level;
}

void PWM::divisorUpdate() {
  divisor_ = position_max_ / (k_max_ - k_min_);
  Serial.print("Divisor: ");
  Serial.println(divisor_);
}

void PWM::divisorUpdate(long int position) {
  position_max_ = position;
  divisorUpdate();
}

int PWM::fix255(int value) {
  if (value >= 255 and value <= 256) {
    return 256;
  }

  return value;
}