

#define LA 3
#define LB 4
#define RA 1
#define RB 0

#define trigpin 6
#define echo 8

void setup() {
  // put your setup code here, to run once:
  pinMode(LA, OUTPUT);
  pinMode(LB, OUTPUT);
  pinMode(RA, OUTPUT);
  pinMode(RB, OUTPUT);

  pinMode(trigpin, OUTPUT);
  pinMode(echo, INPUT);
  delay(3000);


}
int distance;
void loop() {
  int duration;
  digitalWrite(trigpin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin, LOW);
  duration = pulseIn(echo, HIGH);
  distance = (1 / 29.1) * (duration / 2);
  delay(40);
  if(distance>15){
    moveForward();
  }
  if(distance<=15)
 {
  moveStop();
  delay(100);
  moveBackward();
  delay(300);
  moveStop();
  delay(200);
  turnRight();
  delay(200);
 }
}

void moveForward() {
  digitalWrite(LA, HIGH);
  digitalWrite(LB, LOW);
  digitalWrite(RA, HIGH);
  digitalWrite(RB, LOW);
}
void moveBackward() {
  digitalWrite(LA, LOW);
  digitalWrite(LB, HIGH);
  digitalWrite(RA, LOW);
  digitalWrite(RB, HIGH);
}
void turnRight() {
  digitalWrite(LA, LOW);
  digitalWrite(LB, HIGH);
  digitalWrite(RA, HIGH);
  digitalWrite(RB, LOW);
}
void moveStop() {
  digitalWrite(LA, LOW);
  digitalWrite(LB, LOW);
  digitalWrite(RA, LOW);
  digitalWrite(RB, LOW);
}

  
