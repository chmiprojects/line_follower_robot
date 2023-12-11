#define motor1a 5
#define motor1b 4
#define motor2a 3
#define motor2b 2

#define motor1en 9
#define motor2en 10

#define irRight 7
#define irLeft 6

// #define speed 130

#define power 13
void setup() {
  Serial.begin(9600);
  
  pinMode(motor1a, OUTPUT);
  pinMode(motor1b, OUTPUT);
  pinMode(motor2a, OUTPUT);
  pinMode(motor2b, OUTPUT);
  pinMode(power, OUTPUT);


  pinMode(motor1en, OUTPUT);
  pinMode(motor2en, OUTPUT);

  pinMode(irLeft, INPUT);
  pinMode(irRight, INPUT);

  startupLed(200);
}

void loop() {
  int leftSensor = digitalRead(irLeft);
  int rightSensor = digitalRead(irRight);

  if (leftSensor == HIGH && rightSensor == HIGH) {
   
  stop();
    // Serial.println("stop");
  } else if (leftSensor == HIGH && rightSensor == LOW) {
    turnRight(); 
  // Serial.println("right");
    
  } else if (leftSensor == LOW  && rightSensor == HIGH) {
 turnLeft();
  // Serial.println("left");

  } else {
    moveForwardv1();
    // Serial.println("forward");
  }
}
void moveForward(){
    digitalWrite(motor1a, LOW);
    digitalWrite(motor1b, HIGH);
    digitalWrite(motor2a, LOW);
    digitalWrite(motor2b, HIGH);

    // analogWrite(motor1en,speed);
    // analogWrite(motor2en,speed);

}
void turnRight(){
    digitalWrite(motor1a, LOW);
    digitalWrite(motor1b, HIGH);
    digitalWrite(motor2a, HIGH);
    digitalWrite(motor2b, LOW);

    // analogWrite(motor1en,speed);
    // analogWrite(motor2en,speed);
}
void turnLeft(){
    digitalWrite(motor1a, HIGH);
    digitalWrite(motor1b, LOW);
    digitalWrite(motor2a, LOW);
    digitalWrite(motor2b, HIGH);

    // analogWrite(motor1en,speed);
    // analogWrite(motor2en,speed);
}
void stop(){
    digitalWrite(motor1a, LOW);
    digitalWrite(motor1b, LOW);
    digitalWrite(motor2a, LOW);
    digitalWrite(motor2b, LOW);

    // analogWrite(motor1en,0);
    // analogWrite(motor2en,0);
}
void moveBackward(){
    digitalWrite(motor1a, HIGH);
    digitalWrite(motor1b, LOW);
    digitalWrite(motor2a, HIGH);
    digitalWrite(motor2b, LOW);
 
    // analogWrite(motor1en,speed);
    // analogWrite(motor2en,speed); 
}
void startupLed(int dl){
  digitalWrite(power,HIGH);
  delay(dl);
  digitalWrite(power,LOW);
  delay(dl);
  digitalWrite(power,HIGH);
  delay(dl);
  digitalWrite(power,LOW);
  delay(dl);
  digitalWrite(power,HIGH);
  delay(dl);
  digitalWrite(power,LOW);
  delay(dl);
  digitalWrite(power,HIGH);
}

void moveForwardv1(){
for (int i = 0 ; i<1;i++){
    if (i==0){
     digitalWrite(motor1a, LOW);
     digitalWrite(motor1b, HIGH);
     digitalWrite(motor2a, LOW);
     digitalWrite(motor2b, HIGH);
     delay(10);
    }
    else{
      digitalWrite(motor1a, LOW);
      digitalWrite(motor1b, LOW);
      digitalWrite(motor2a, LOW);
      digitalWrite(motor2b, LOW);
    }
}

}