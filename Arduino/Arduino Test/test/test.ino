#include<Servo.h>
Servo myservo;//定义舵机变量名
int val = 45;
int tmp0, tmp1, tmp2;
void setup()
{
  Serial.begin(9600);
  myservo.attach(9);//定义舵机接口（9、10 都可以，缺点只能控制2 个）
}
void loop()
{
  tmp0 = Serial.read();
  tmp1 = Serial.read();
  tmp2 = Serial.read();
  if (tmp0 != -1 && tmp1 != -1 && tmp2 != -1) {
    val=(tmp0-48)*100+(tmp1-48)*10+tmp2-48;
  }
  Serial.println(tmp0);
  Serial.println(val);
  myservo.write(val);//设置舵机旋转的角度
  delay(50);
}
