//
// Created by jadjer on 8.06.21.
//

#ifndef TPS__PWM_HPP_
#define TPS__PWM_HPP_

class PWM {
 public:
  explicit PWM(int k_min, int k_max, long int position_max);
  ~PWM();

  void setPositionMax(long int position);
  void setFix255Enable(bool value);

  int calculate(long int position);

 private:
  bool fix_255_;
  double divisor_;
  int const k_min_;
  int const k_max_;
  long int position_max_;

  void divisorUpdate();
  void divisorUpdate(long int position);

  static int fix255(int value);
};

#endif //TPS__PWM_HPP_
