#include<Servo.h>

Servo myservo;

int pos = 0;

void setup() {
  // put your setup code here, to run once:
  myservo.attach(9);
}

void loop() {
  // put your main code here, to run repeatedly:
  myservo.write(0);
  delay(5000);
  myservo.write(180);
  delay(5000);
  /*for (pos = 0; pos < 180; pos ++) {
     myservo.write(pos);
     delay(15);
   }
   for (pos = 180; pos >= 1; pos --) {
     myservo.write(pos);
     delay(15);
   }
   */
}
