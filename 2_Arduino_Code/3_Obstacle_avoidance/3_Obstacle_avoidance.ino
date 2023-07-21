/*************************************
 *     TIME:2022.6.25
 *     Development Team: Zhiyi Technology Co., Ltd.
 * 
 *  **************************************/
// #include <AFMotor.h>
int Trig = 12;//Pin to D12
int Echo = 13;//Pin to D13
#define ENA 5
#define ENB 6
#define IN1 3
#define IN2 4
#define IN3 2
#define IN4 7
#define carSpeed 180//Set the carSpeed to 130
float distance;
float cm;

void forward(){ 
  analogWrite(ENA,carSpeed); 
  analogWrite(ENB,carSpeed); 

  digitalWrite(IN1,LOW); 
  digitalWrite(IN2,HIGH);  
  digitalWrite(IN3,HIGH);  
  digitalWrite(IN4,LOW); 
  Serial.println("Forward");
}

void back(){
analogWrite(ENA,carSpeed); 
  analogWrite(ENB,carSpeed); 
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);
  Serial.println("Back");
}


void left(){
  analogWrite(ENA,carSpeed); 
  analogWrite(ENB,carSpeed); 
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);
  Serial.println("Left");
}

void right(){
  analogWrite(ENA,carSpeed); 
  analogWrite(ENB,carSpeed); 
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH); 
  Serial.println("Right");
}

void stop() {//stop function
  digitalWrite(ENA, LOW);//Set the speed of ENA to low
  digitalWrite(ENB, LOW);//Set the speed of ENB to low
  Serial.println("Stop!");
}

float GetDistance()
{
    // Send a low short pulse to Trig to trigger the ranging
    digitalWrite(Trig, LOW); //Send a low level to Trig
    delayMicroseconds(2); 
    digitalWrite(Trig, HIGH); 
    delayMicroseconds(10);
    digitalWrite(Trig, LOW);
    distance = pulseIn(Echo, HIGH) / 58.00;
	  return distance;
}

void setup() {
  Serial.begin(9600);
  pinMode(Echo, INPUT);
  pinMode(Trig, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  stop();
  delay(100);
}

void loop() 
{
  cm = GetDistance();
  if(cm <= 15){
    back();
    delay(500);
    left();
    delay(500);
  }
  else if(cm > 15){
    forward();
  }
  // Serial.print("Distance = ");
  // Serial.print(cm);
  // Serial.println("cm");
}
