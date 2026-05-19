#include <SoftwareSerial.h>
SoftwareSerial BT(2, 3);   // RX, TX

//CONFIG MOTOREN
const int GSM1 = 10;
const int in1 = 9;
const int in2 = 8;

const int GSM2 = 5;
const int in3 = 7;
const int in4 = 6;

void setup() {
  pinMode(GSM1, OUTPUT);
  pinMode(GSM2, OUTPUT);

  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  BT.begin(9600);
}

void loop() {
  _carfunktionen();
}

void _carfunktionen() {
  analogWrite(GSM1, 255);
  analogWrite(GSM2, 255);

  if (BT.available() > 0) {
    char control = BT.read();

    if (control == 'F') _front();
    if (control == 'B') _back();
    if (control == 'L') _links();
    if (control == 'R') _rechts();
    if (control == 'S') _stop();
  }
}

void _stop() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}

void _front() {
  _stop();

  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);

  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

void _back() {
  _stop();
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);

  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void _rechts() {
  _stop();

  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);

  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void _links() {
  _stop();

  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);

  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}
