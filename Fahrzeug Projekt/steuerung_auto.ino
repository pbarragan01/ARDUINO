#include <SoftwareSerial.h>
SoftwareSerial BT(2, 3);  // RX, TX

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
  pinMode(12, OUTPUT);

  BT.begin(9600); // CONSOLE AKTIVIEREN
  Serial.begin(9600); // BLUETOOTH AKTIVIEREN
}

void loop() {
  _carfunktionen(); // Alle Funktionen werden gesteuert, indem Method _carFunktionen() aktivieren
}

void _carfunktionen() {
  analogWrite(GSM1, 255);
  analogWrite(GSM2, 255);

  if (BT.available() > 0) {
    char control = BT.read();

    if (control == 'F') _front(control);
    if (control == 'B') _back(control);
    if (control == 'R') _links(control);
    if (control == 'L') _rechts(control);
    if (control == 'S') _stop();
    if (control == 'U') _ledON(control);
    if (control == 'u') _ledsOFF(control);
  }
}


void _ledsON(char control) {
  Serial.print("LEDS ON: ");
  Serial.println(control);
  digitalWrite(12, HIGH);
  delay(100);
  digitalWrite(12, LOW);
}


void _ledsOFF(char control) {
  Serial.print("LEDS OFF: ");
  Serial.println(control);
  digitalWrite(12, LOW);
}


void _stop() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}

void _front(char control) {
  Serial.print("Richtung: ");
  Serial.println(control);

  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);

  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

void _back(char control) {
  Serial.print("Richtung: ");
  Serial.println(control);

  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);

  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void _rechts(char control) {
  Serial.print("Richtung: ");
  Serial.println(control);


  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);

  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void _links(char control) {
  Serial.print("Richtung: ");
  Serial.println(control);


  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);

  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

//Programiert bei Pau Barragan und Malte Mergens
