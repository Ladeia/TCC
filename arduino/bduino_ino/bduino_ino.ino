#include <dht11.h>

/*************************************************************
 * Aplicaçao do Bduino
 * Autor: Antonio Ladeia (contato@antonioladeia.com)
 *************************************************************/
#include<dht11.h>

#define BAUD 9600
#define DHT11 13
#define SonarTrig 12
#define SonarEcho 11
#define LDR 9
#define READ_INTERVAL 2000

dht11 sensor;

void setup() 
{
    Serial.begin(BAUD);
    pinMode(SonarTrig, OUTPUT);
    pinMode(SonarEcho, INPUT);
    delay(1000); 
}

void loop() 
{
    sensor.read(DHT11);
    Serial.print("Umidade = ");
    Serial.print(sensor.humidity);
    Serial.print("% ");
    Serial.print("Temperatura = ");
    Serial.print(sensor.temperature); 
    Serial.println(" Celsius");
    delay(READ_INTERVAL);
    
      Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(led, OUTPUT);
  pinMode(led2, OUTPUT);
  
  long duration, distance;
  digitalWrite(trigPin, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(trigPin, HIGH);
//  delayMicroseconds(1000); - Removed this line
  delayMicroseconds(10); // Added this line
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  if (distance < 4) {  // This is where the LED On/Off happens
    digitalWrite(led,HIGH); // When the Red condition is met, the Green LED should turn off
  digitalWrite(led2,LOW);
}
  else {
    digitalWrite(led,LOW);
    digitalWrite(led2,HIGH);
  }
  if (distance >= 200 || distance <= 0){
    Serial.println("Out of range");
  }
  else {
    Serial.print(distance);
    Serial.println(" cm");
  }
  delay(500);
  
  int iluminacao = analogRead(LDR)
}

#include <AcceleroMMA7361.h> //Carrega a biblioteca do MMA7361  
   
 AcceleroMMA7361 accelero;  
 int x;  
 int y;  
 int z;  
   
 void setup()  
 {  
  Serial.begin(9600);  
  accelero.begin(13, 12, 11, 10, A0, A1, A2);  
  //Seta a voltagem de referencia AREF como 3.3V
  accelero.setARefVoltage(3.3);
  //Seta a sensibilidade (Pino GS) para +/-6G    
  accelero.setSensitivity(LOW);    
  accelero.calibrate();  
 }  
   
 void loop()  
 {  
  x = accelero.getXAccel(); //Obtem o valor do eixo X  
  y = accelero.getYAccel(); //Obtem o valor do eixo Y  
  z = accelero.getZAccel(); //Obtem o valor do eixo Z  
  Serial.print("\nx: ");   //Mostra os valores no serial monitor  
  Serial.print(x);  
  Serial.print(" \ty: ");  
  Serial.print(y);  
  Serial.print(" \tz: ");  
  Serial.print(z);  
  Serial.print("\tG*10^-2");  
  delay(500);                     
 }  

