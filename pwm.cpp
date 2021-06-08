//
// Created by jadjer on 8.06.21.
//

#include "pwm.hpp"

PWM::PWM(int k_min, int k_max, long int position_max)
    : k_min_(k_min), k_max_(k_max) {

  fix_255_ = false;
  divisor_ = 0;
  position_max_ = position_max;

  divisorUpdate();
}

PWM::~PWM() = default;

void PWM::setPositionMax(long int position) {
  divisorUpdate(position);
}

void PWM::setFix255Enable(bool value) {
  fix_255_ = value;
}

int PWM::calculate(long int position) {
  if (position > position_max_) {
    divisorUpdate(position);
  }

  int pwm_level  = static_cast<int>(static_cast<double>(position) / divisor_) + k_min_;

  if (fix_255_) {
    pwm_level = fix255(pwm_level);
  }

  return pwm_level;
}

void PWM::divisorUpdate() {
  divisor_ = static_cast<double>(position_max_) / (k_max_ - k_min_);
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
