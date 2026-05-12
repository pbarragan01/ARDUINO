// Motor rechts
#define MOTOR_RF  5
#define MOTOR_RH  6

// Motor links
#define MOTOR_LF 10
#define MOTOR_LH 11

// Ultraschallsensor
#define TRIG_PIN 2
#define ECHO_PIN 3

// --- Funktion zum Messen des Abstands ---
float getDistance() {
  long duration;

  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  duration = pulseIn(ECHO_PIN, HIGH, 30000); // 30ms Timeout

  if (duration == 0) return 999; // Kein Echo → sehr weit weg

  return duration / 58.0; // cm
}

// --- Motorfunktionen ---
void forward() {
  digitalWrite(MOTOR_RF, HIGH);
  digitalWrite(MOTOR_RH, LOW);
  digitalWrite(MOTOR_LF, HIGH);
  digitalWrite(MOTOR_LH, LOW);
}

void backward() {
  digitalWrite(MOTOR_RF, LOW);
  digitalWrite(MOTOR_RH, HIGH);
  digitalWrite(MOTOR_LF, LOW);
  digitalWrite(MOTOR_LH, HIGH);
}

void turnRight() {
  digitalWrite(MOTOR_RF, HIGH);
  digitalWrite(MOTOR_RH, LOW);
  digitalWrite(MOTOR_LF, LOW);
  digitalWrite(MOTOR_LH, HIGH);
}

void stopMotors() {
  digitalWrite(MOTOR_RF, LOW);
  digitalWrite(MOTOR_RH, LOW);
  digitalWrite(MOTOR_LF, LOW);
  digitalWrite(MOTOR_LH, LOW);
}

void setup() {
  pinMode(MOTOR_RF, OUTPUT);
  pinMode(MOTOR_RH, OUTPUT);
  pinMode(MOTOR_LF, OUTPUT);
  pinMode(MOTOR_LH, OUTPUT);

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
}

void loop() {
  float dist = getDistance();

  // --- Weiterfahren wenn >20 cm ---
  if (dist > 20) {
    forward();
  }

  // --- Reagieren wenn <=20 cm ---
  else {

    // --- Abstand <10 cm → rückwärts ---
    if (dist < 10) {
      backward();
      delay(200);
      stopMotors();
      delay(100);
    }

    // --- Abstand >=10 cm → rechts abbiegen ---
    else {
      turnRight();
      delay(200);
      stopMotors();
      delay(100);
    }
  }

  delay(30); // Sensor entlasten
}
