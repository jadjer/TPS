//
// Created by jadjer on 8.06.21.
//

#ifndef TPS__PWM_HPP_
#define TPS__PWM_HPP_

#include <Arduino.h>

class PWM {
 public:
  explicit PWM(int min, int max);
  ~PWM();

  void setPositionMax(long int position);
  void setFixEnable(bool value);

  int calculate(long int position);

 private:
  bool fix_;
  double divisor_;
  int const k_min_;
  int const k_max_;
  long int position_max_;

  void divisorUpdate();
  void divisorUpdate(long int position);

  int fix255(int value);
};

#endif //TPS__PWM_HPP_
