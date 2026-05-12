
// Motor rechts
#define MOTOR_RF  5   // Motor rechts vorne
#define MOTOR_RH  6   // Motor rechts hinten

// Motor links
#define MOTOR_LF 10   // Motor links vorne
#define MOTOR_LH 11   // Motor links hinten

// Ultraschallsensor
#define TRIG_PIN 2
#define ECHO_PIN 3

void setup() {
  pinMode(MOTOR_RF, OUTPUT);
  pinMode(MOTOR_RH, OUTPUT);
  pinMode(MOTOR_LF, OUTPUT);
  pinMode(MOTOR_LH, OUTPUT);

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
}

void loop() {
  float dist;
  long duration;

  // === ABSTAND MESSEN ===
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  duration = pulseIn(ECHO_PIN, HIGH, 3000);
  if (duration == 0) return;
  dist = duration / 58.0;

  // === dist > 30 cm → vorwärts fahren ===
  while (dist > 30) {
    digitalWrite(MOTOR_RF, HIGH);
    digitalWrite(MOTOR_RH, LOW);
    digitalWrite(MOTOR_LF, HIGH);
    digitalWrite(MOTOR_LH, LOW);

    digitalWrite(TRIG_PIN, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN, LOW);
    duration = pulseIn(ECHO_PIN, HIGH, 3000);
    if (duration == 0) break;
    dist = duration / 58.0;
  }

  // === dist ≤ 20 cm → reagieren ===
  while (dist <= 20) {
    if (dist < 10) {
      digitalWrite(MOTOR_RF, HIGH);
      digitalWrite(MOTOR_RH, LOW);
      digitalWrite(MOTOR_LF, LOW);
      digitalWrite(MOTOR_LH, HIGH);
    }

    digitalWrite(TRIG_PIN, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN, LOW);
    duration = pulseIn(ECHO_PIN, HIGH, 3000);
    if (duration == 0) break;
    dist = duration / 58.0;
  }                                                                                                                                 
}
