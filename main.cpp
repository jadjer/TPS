//
// Created by jadjer on 8.06.21.
//

//#include <iostream>
#include "pwm.hpp"

int main(int argc, char **argv) {

  PWM pwm(104, 945, 570);
  pwm.setFixEnable(true);

  for (auto i = 0; i <= 570; i++) {
    auto pwm_level = pwm.calculate(i);
//    std::cout << "Index: " << i << "; PWM: " << pwm_level << std::endl;
  }

  return 0;
}