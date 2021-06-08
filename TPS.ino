#include <Encoder.h>

constexpr int PIN_ENCODER_1 = 2;
constexpr int PIN_ENCODER_2 3
#define PIN_OUTPUT 10
#define PWM_LEVEL_MIN 104
#define PWM_LEVEL_MAX 945
#define ENCODER_VALUE_MAX 570

bool fix_255_;
double divisor_;
int const k_min_;
int const k_max_;
long int position_max_;

Encoder encoder(PIN_ENCODER_2, PIN_ENCODER_1);

int PWM_Calculate(long int position) {
  if (position > position_max_) {
    divisorUpdate(position);
  }

  int pwm_level  = static_cast<int>(static_cast<double>(position) / divisor_) + k_min_;

  if (fix_255_) {
    pwm_level = fix255(pwm_level);
  }

  return pwm_level;
}

void PWM_DivisorUpdate() {
  divisor_ = static_cast<double>(position_max_) / (k_max_ - k_min_);
}

void setup() {
  TCCR1A = 0b00000011;
  TCCR1B = 0b00001001;
  
  pinMode(PIN_OUTPUT, OUTPUT);
  Serial.begin(9600);

//  pwm.setFix255Enable(true);
}

void loop() {
//  auto position_current = encoder.read();
//auto position_current = 12;
  
//  if (position_current < 0) {
//    encoder.write(0);
//    position_current = 0;
//  }

//  auto pwm_level = pwm.calculate(position_current);

  Serial.println("Hello");
  delay(1000);
  
//  analogWrite(PIN_OUTPUT, pwm_level);
}
