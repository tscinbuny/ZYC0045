/*************************************
 *     TIME:2023.06.25
 *     Development Team: Zhiyi Technology Co., Ltd.
 * 
 *  **************************************/
#define ENA 5
#define ENB 6
#define IN1 3
#define IN2 4
#define IN3 2
#define IN4 7

int Sensor1;
int Sensor2;
int Sensor3;
int Sensor4;

void setup() {
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  pinMode(8, INPUT);
  pinMode(9, INPUT);
  pinMode(10, INPUT);
  pinMode(11, INPUT);
  Serial.begin(9600);
}
void loop()
{
    //从前进方向看，从左到右传感器排列:Sensor4|Sensor3|Sensor2|Sensor1
    //The sensors are arranged from left to right:Sensor4|Sensor3|Sensor2|Sensor1
    Sensor1 = digitalRead(8);
    Sensor2 = digitalRead(9);
    Sensor3 = digitalRead(10);
    Sensor4 = digitalRead(11);
    //高电平为检测到黑线;The high level means that a black line is detected
    if ((Sensor4 == HIGH || Sensor3 == HIGH) && (Sensor2 == LOW || Sensor1 == LOW))
    {
        analogWrite(ENA, 150);
        analogWrite(ENB, 150);
        digitalWrite(IN1,HIGH);
        digitalWrite(IN2,LOW);
        digitalWrite(IN3,HIGH);
        digitalWrite(IN4,LOW);
        Serial.println("left");
    }
    else if((Sensor4 == LOW || Sensor3 == LOW) && (Sensor2 == HIGH || Sensor1 == HIGH))
    {
        analogWrite(ENA, 150);
        analogWrite(ENB, 150);
        digitalWrite(IN1,LOW);
        digitalWrite(IN2,HIGH);
        digitalWrite(IN3,LOW);
        digitalWrite(IN4,HIGH);
        Serial.println("right");
    }
    else  if(Sensor4 == LOW && Sensor3 == LOW && Sensor2 == LOW && Sensor1 == LOW)
    {
        analogWrite(ENA, 150);
        analogWrite(ENB, 150);
        digitalWrite(IN1,HIGH);
        digitalWrite(IN2,LOW);  
        digitalWrite(IN3,LOW);  
        digitalWrite(IN4,HIGH);
        Serial.println("forward");
    }
    else  if((Sensor2 == HIGH || Sensor3 == HIGH ) && Sensor1 == LOW && Sensor4 == LOW)
    {
        analogWrite(ENA, 180);
        analogWrite(ENB, 180);
        digitalWrite(IN1,HIGH);
        digitalWrite(IN2,LOW);
        digitalWrite(IN3,LOW);
        digitalWrite(IN4,HIGH);
        Serial.println("forward");
    }
    else
    {
        analogWrite(ENA, 0);
        analogWrite(ENB, 0);
        digitalWrite(IN1, LOW);
        digitalWrite(IN2, LOW);
        digitalWrite(IN3, LOW);
        digitalWrite(IN4, LOW);
        Serial.println("stop");
    }     
}
