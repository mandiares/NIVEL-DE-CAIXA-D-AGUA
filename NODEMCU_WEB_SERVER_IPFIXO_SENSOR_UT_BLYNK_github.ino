 
       
/*
********************************************
Claudio Peixoto Rocha
claudiopeixotorocha@gmail.com
********************************************
*/
#define TRIGGER D0
#define ECHO    D2

// NodeMCU Pino D0 > TRIGGER | Pino D2 > ECHO

#define BLYNK_PRINT Serial    
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// o auth code é obtido quando se abre um projeto no Blynk
// após abrir o projeto clica no icone de porca
char auth[] = ""; insira seu auth code entre aspas

// seu wifi
// nome da rede e senha entre aspas
char ssid[] = "";
char pass[] = "";
void setup() {
  
  Serial.begin (9600);
  Blynk.begin(auth, ssid, pass);
  pinMode(TRIGGER, OUTPUT);
  pinMode(ECHO, INPUT);
  pinMode(BUILTIN_LED, OUTPUT);
}

void loop() {
  
  long duration, distance;
  int litros = 0;
  digitalWrite(TRIGGER, LOW);  
  delayMicroseconds(2); 
  
  digitalWrite(TRIGGER, HIGH);
  delayMicroseconds(10); 
  
  digitalWrite(TRIGGER, LOW);
  duration = pulseIn(ECHO, HIGH);
  distance = (duration/2) / 29.1;
  litros = (152000- (2000 * distance))/66;
  

   if (distance <=76) {
    Blynk.virtualWrite(V0, 255);
}
  else {
    Blynk.virtualWrite(V0, 0);
  }

 if (distance <= 57) {
    Blynk.virtualWrite(V1, 255);
}
  else {
    Blynk.virtualWrite(V1, 0);
  }

   if (distance <= 38) {
    Blynk.virtualWrite(V2, 255);
}
  else {
    Blynk.virtualWrite(V2, 0);
  }

   if (distance <= 25) {
    Blynk.virtualWrite(V3, 255);
}
  else {
    Blynk.virtualWrite(V3, 0);
  }

   if (distance <= 10) {
    Blynk.virtualWrite(V4, 255);
}
  else {
    Blynk.virtualWrite(V4, 0);
  }

  
  
  Serial.print(distance);
  Serial.println("Centimeter:");
  Blynk.virtualWrite(V5, distance);
  delay(200);
  Blynk.run();

 Serial.print(distance);
 Serial.println("litros:");
  Blynk.virtualWrite(V6, litros);
  delay(100);
  Blynk.run();
}
