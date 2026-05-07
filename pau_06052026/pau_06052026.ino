const int gelb = 5;
const int rot = 7;
const int gelb_blink = 9;

bool status_system = false;
void setup() {
  Serial.begin(9600); // Console aktivieren
  _initMenu();
  //-------------------------
  //        SETUP PINS:
  //   FÜR WECHSELBLINKER:
  //    GELB --> PIN 5
  //    ROT --> PIN 7
  pinMode(gelb, OUTPUT);
  pinMode(rot, OUTPUT);
  //-------------------------
  // GELBER EIGENER BLINKER --> 9  
  pinMode(gelb_blink, OUTPUT);
  
}

// SETTING TO ARDUINO
void loop() {
  // put your main code here, to run repeatedly:
  _menu();
  _funktionen();
  
}

void _initMenu(){
  Serial.println("WAITING FOR INPUT...");
  Serial.println(" ");
  Serial.println("1 = BEGINNEN");
  Serial.println("0 = ENDEN");
}


void _menu(){
  if(Serial.available() > 0){
    char steuerung = Serial.read();
    if (steuerung == '1'){
      status_system = true;
       Serial.println("DAS PROGRAMM WIRD EINGESCHALTET");
       delay(2000);
    } else if (steuerung == '0'){
      status_system = false;
       delay(2000);
       Serial.println("PROGRAMM BEENDET");
     
      
    } 
  }
}
//______________________________________________
//--------------- GELB BLINKER -----------------
void LedBlinken(){
if(!status_system){return;}
delay(1000);
Serial.println("LED PIN 9 WIRD BLINKEN");
delay(1000);
  for (int i = 0; i < 4; i++){
    Serial.print("COUNTER i = ");
    Serial.println(i);
    digitalWrite(gelb_blink, HIGH);
    delay(1000);
    digitalWrite(gelb_blink, LOW);
    delay(1000);
  }
    Serial.println("INFO: Funktion gelbe Blinker beendet.");

}

//______________________________________________
//------------- WECHSEL BLINKER-----------------
void WechselBlinker() {
if(!status_system){return;}
  Serial.println("Info: Wechsel Blinker aktiv");

  for (int j = 0; j < 10; j++) {
    Serial.print("COUNTER J = ");
    Serial.println(j);
    digitalWrite(gelb, HIGH);
    delay(200);
    digitalWrite(gelb, LOW),
    digitalWrite(rot, HIGH);
    delay(200);
    digitalWrite(rot, LOW);
  }

  Serial.println("Info: Ende der Wechsel Blinker");

}


void _funktionen(){
    if(!status_system){return;}
  LedBlinken();
if(!status_system){return;}
  WechselBlinker();
if(!status_system){return;}
  delay(5000);

}
//________________________________________________




// LedBlinken();
//  delay(1000);
//  WechselBlinker();
//  delay(1000);