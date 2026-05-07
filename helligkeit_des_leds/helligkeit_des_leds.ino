//GEL

const int red = 13;
const int yellow = 12;
const int green = 8;
const int yellow_down = 9;
const int piep = 7;

int fade = 5;
int hell = 0;
bool status_system = false;


void setup() {

  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(yellow_down, OUTPUT);
  pinMode(piep, OUTPUT);
  randomSeed(A0);
  Serial.begin(9600); // Console aktivieren
  _initMenu();


}

// SETTING TO ARDUINO
void loop() {
  // put your main code here, to run repeatedly:
  _menu();

}

void _initMenu() {
  Serial.println("--------------------------------------------");
  Serial.print("WAITING FOR INPUT");
  Serial.print(".");
  delay(500);
  Serial.print(".");
  delay(500);
  Serial.println(".");
  delay(500);
  Serial.println("0 = ENDEN");
  Serial.println("1 = BLINK UND HELLIGKEIT MODE");
  Serial.println("2 = AMPEL MODE");
  Serial.println("3 = F1 MODE");

  Serial.println("--------------------------------------------");
}

void _menu() {
     

  if (Serial.available() > 0) {
    char steuerung = Serial.read();
        if (steuerung == '0') {
          Serial.println("---------------------");
          Serial.println("| PROGRAMM BEENDET |");
          Serial.println("---------------------");

        } else if (steuerung == '1') {
        Serial.println("--------------------------------------------");
        Serial.println("INITIALIZING BLINK UND HELLIGKEIT MODE");
        delay(1000);
        Serial.println("PLEASE WAIT...");
        Serial.println("--------------------------------------------");
        _wechselblinkenFunktionen();

      } else if (steuerung == '2'){
        status_system = true;
        Serial.print("INITIALIZING AMPEL MODE");
        Serial.print(".");
        delay(1000);
        Serial.print(".");
        delay(1000);
        Serial.print(".");
        delay(1000);
        AmpelModus();
        

      } else if (steuerung == '3'){
        status_system = true;
        Serial.print("INITIALIZING F1 MODE");
        Serial.print(".");
        delay(1500);
        Serial.print(".");
        delay(1500);
        Serial.println(".");
        delay(1500);
        F1Modus();
            
      } 
    }

  }

void _wechselblinkenFunktionen(){
  if (!status_system) {
    return;
  }
  LedBlinken();
  if (!status_system) {
    return;
  }
  WechselBlinker();
  if (!status_system) {
    return;
  }

  _initMenu();
}

void _funktionen() {

    Helligkeit();
  if (!status_system) {
    return;
  }
  delay(5000);

}

// ------------- FUNKTIONEN -------------

void Helligkeit() {
  analogWrite(yellow_down, hell);
  hell = hell + fade;
  delay(50);
  if (hell == 0 || fade == 255){
    fade = -fade;
  }
}
//______________________________________________
//--------------- GELB BLINKER -----------------

void LedBlinken() {

  delay(1000);
  Serial.println("LED PIN 9 WIRD BLINKEN");
  delay(1000);
  for (int i = 1; i < 5; i++) {
    if (!status_system) {
      return;
    }
    Serial.print("ACHTUNG NUMMER: ");
    Serial.println(i);
    digitalWrite(yellow_down, HIGH);
    digitalWrite(piep, HIGH);
    delay(1000);
    digitalWrite(yellow_down, LOW);
    digitalWrite(piep, LOW);
    delay(1000);
  }
  Serial.println("INFO: Funktion gelbe Blinker beendet.");

}

//______________________________________________
//------------- WECHSEL BLINKER-----------------
void WechselBlinker() {
  if (!status_system) {
    return;
  }
  Serial.println("");

  for (int j = 1; j < 11; j++) {
    if (!status_system) {
      return;
    }
    Serial.print("COUNTER J = ");
    Serial.println(j);
    digitalWrite(red, HIGH);
    delay(100);
    digitalWrite(red, LOW);
    digitalWrite(yellow, HIGH);
    delay(100);
    digitalWrite(yellow, LOW);
    digitalWrite(green, HIGH);
    delay(100);
    digitalWrite(green, LOW);
    digitalWrite(green, HIGH);
    delay(100);
    digitalWrite(green, LOW);
    digitalWrite(yellow, HIGH);
    delay(100);
    digitalWrite(yellow, LOW);
    digitalWrite(red, HIGH);
    delay(100);
    digitalWrite(red, LOW);

  }

  Serial.println("Info: Ende der Wechsel Blinker. Returning to starting menu.");
  delay(2000);
  _menu();

}

//------------- AMPEL MODUS -------------

void AmpelModus(){

}



//------------- F1 MODUS -------------


void _testcheck() {
  if (!status_system) {
    return;
  }
  Serial.println("TEST CHECK IN PROGRESS...");

  for (int k = 1; k < 6; k++) {
    if (!status_system) {
      return;
    }
    digitalWrite(red, HIGH);
    delay(100);
    digitalWrite(red, LOW);
    digitalWrite(yellow, HIGH);
    delay(100);
    digitalWrite(yellow, LOW);
    digitalWrite(green, HIGH);
    delay(100);
    digitalWrite(green, LOW);
    digitalWrite(green, HIGH);
    delay(100);
    digitalWrite(green, LOW);
    digitalWrite(yellow, HIGH);
    delay(100);
    digitalWrite(yellow, LOW);
    digitalWrite(red, HIGH);
    delay(100);
    digitalWrite(red, LOW);

  }

  Serial.println("Info: Ende der Wechsel Blinker. Returning to starting menu.");


}


void F1Modus(){

  Serial.println("INITIALIZING F1 COUNTER...");
  delay(2000);
  _testcheck();
  Serial.println("GET READY");
 
  delay(5000);
  
  float random_zeit = random(200,3001);
  digitalWrite(red, HIGH);
  digitalWrite(piep, HIGH);
  digitalWrite(piep, LOW);
  delay(1000);

  digitalWrite(yellow, HIGH);
  digitalWrite(piep, HIGH);
  digitalWrite(piep, LOW);
  delay(1000);
  
  digitalWrite(green, HIGH);
  digitalWrite(piep, HIGH);
  digitalWrite(piep, LOW);
  delay(1000);

  delay(random_zeit);
  digitalWrite(red, LOW);
  digitalWrite(yellow, LOW);
  digitalWrite(green, LOW);
  
  digitalWrite(yellow_down, HIGH);
  digitalWrite(piep, HIGH);
  Serial.println("GOOO!!!");
  Serial.print("LAUNCH Zeit: ");
  Serial.print(random_zeit/1000);
  Serial.println(" Sekunden");
  delay(5000);
  digitalWrite(yellow_down, LOW);
  
  Serial.println("Returning to starting menu.");
  delay(2000);
  _initMenu();

}






//________________________________________________

