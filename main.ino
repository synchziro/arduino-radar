// Library servo
#include <Servo.h>. 

// Deklarasi pin Trigger dan Echo pada HC-SR04
const int trigPin = 10;
const int echoPin = 11;

// Variabel durasi dan jarak
long duration;
int distance;

// Deklarasi servo sebagai objek
Servo myServo; 

void setup() {
  pinMode(trigPin, OUTPUT);   // Atur trigPin sebagai output
  pinMode(echoPin, INPUT);    // Atur echoPin sebagai input
  Serial.begin(9600);
  myServo.attach(12);         // Definisi letak pin servo
}
void loop() {
  // putar servo dari 15 derajat hingga 165 derajat
  for(int i=15;i<=165;i++){  
  myServo.write(i);
  delay(30);
  distance = calculateDistance();  
  Serial.print(i); 
  Serial.print(","); 
  Serial.print(distance); 
  Serial.print("."); 
  }
  for(int i=165;i>15;i--){  
  myServo.write(i);
  delay(30);
  distance = calculateDistance();
  Serial.print(i);
  Serial.print(",");
  Serial.print(distance);
  Serial.print(".");
  }
}
int calculateDistance(){ 
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH); 
  distance= duration*0.034/2;
  return distance;
}
