#define Rpwm_pin 5
#define Lpwm_pin 4
#define enc_A 2 // interupt pin 2
#define enc_B 3 // interupt pin 3
#define pi 3.141592653 // pi value

// Motor Parameters
int PPR = 22; // Tickcount or Pulse per revolution of motor => Find from experiment
int GR = 41; // Motor Gear Ratio => Find from experiment or paper spec

// init value
int tickcount = 0; // start encoder at 0

float kp = 0.1;
float kd = 0.1;
float ki = 0.1;

float omega_d; // desired velocity rad/s
float omega_c; // current calculate omega
float theta_p = 0; // previous theta
float theta_c; // current theta
float e_area_old = 0;
float e_area_new;
float e_p = 0;
float e_c;

unsigned long StartTime;
unsigned long CurrentTime;
unsigned long Ts; // sampling time

int PWM;

void setup() {
  Serial.begin(9600);
  StartTime = millis();
  pinMode(Rpwm_pin, OUTPUT);
  pinMode(Lpwm_pin, OUTPUT);
  pinMode(enc_A, INPUT);
  pinMode(enc_B, INPUT);
  attachInterrupt(digitalPinToInterrupt(enc_A), enc_read, RISING);
}

void loop() {
  // omega from controller
  omega_d = 2;

  // find theta from encoder
  theta_c = tick_2_theta(tickcount, PPR, GR);
  omega_c = (theta_c - theta_p) / Ts / 1000;

  // find error for omega
  e_c = omega_d - omega_c;

  // PID I Term
  e_area_new = e_area_old + e_c * Ts;

  // PID
  PWM = kp * e_c + kd * ((e_c - e_p) / Ts) + ki * e_area_new ;

  Serial.print("W_d: ");
  Serial.print(omega_d);
  Serial.print(", W_c: ");
  Serial.print(omega_c);
  Serial.print(", e_c: ");
  Serial.print(e_c);
  Serial.print(", PWM: ");
  Serial.print(PWM);
  Serial.print(", Ts: ");
  Serial.print(Ts);
  Serial.println("");

  // limit PWM
  if (PWM < -250) {
    PWM = -250;
  }
  if (PWM > 250) {
    PWM = 250;
  }
  // write to pin
  if ( PWM < 0) {
    analogWrite(Rpwm_pin, 0);
    analogWrite(Lpwm_pin, PWM * -1);
  }
  else if ( PWM > 0) {
    analogWrite(Rpwm_pin, PWM);
    analogWrite(Lpwm_pin, 0);
  }
  else {
    analogWrite(Rpwm_pin, 0);
    analogWrite(Lpwm_pin, 0);
  }

  // update
  theta_p = theta_c;
  e_p = e_c;
  e_area_old = e_area_new;

  delay(30);
}

void enc_read() {
  int a = digitalRead(enc_B);
  if (a > 0) {
    tickcount++;
  }
  else {
    tickcount--;
  }
  CurrentTime = millis();
  Ts = CurrentTime - StartTime;
  StartTime = CurrentTime;
}

float tick_2_theta(int tick, int PPR, int GR) {
  float theta = (2 * pi * tick) / (PPR * GR);
  return theta;
}
