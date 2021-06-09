#include <Encoder.h>

constexpr int PIN_ENCODER_1 = 2;
constexpr int PIN_ENCODER_2 = 3;
constexpr int PIN_OUTPUT = 10;
constexpr int PWM_LEVEL_MIN = 104;
constexpr int PWM_LEVEL_MAX = 945;

long int position_max = 570;
long int position_old = -999;
auto divisorCalc = [&position_max, &PWM_LEVEL_MAX, &PWM_LEVEL_MIN]()-> double { return static_cast<double>(position_max) / (PWM_LEVEL_MAX - PWM_LEVEL_MIN); };
double divisor = divisorCalc();
auto pwmLevelCalc = [&divisor, &PWM_LEVEL_MIN](long int position)-> int { return static_cast<int>(static_cast<double>(position) / divisor) + PWM_LEVEL_MIN; };

Encoder encoder(PIN_ENCODER_2, PIN_ENCODER_1);

void setup() {
  TCCR1A = 0b00000011;
  TCCR1B = 0b00001001;
  
  pinMode(PIN_OUTPUT, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  auto position = encoder.read();
  
  if (position < 0) {
    encoder.write(0);
    position = 0;
  }

  if (position > position_max) {
    position_max = position;
    divisor = divisorCalc();
  }

  int pwm_level = pwmLevelCalc(position);
  
  if (pwm_level >= 255 and pwm_level <= 256) {
    pwm_level = 256;
  }
  
  analogWrite(PIN_OUTPUT, pwm_level);

  if (position != position_old) {
    position_old = position;
    
    Serial.print("Encoder: ");
    Serial.print(position);
    Serial.print("; PWM: ");
    Serial.println(pwm_level);
  }
}
