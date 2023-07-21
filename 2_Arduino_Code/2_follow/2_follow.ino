/*************************************
 *     TIME:2022.06.25
 *     Development Team: Zhiyi Technology Co., Ltd.
 * 
 *  **************************************/
// #include <AFMotor.h>
#define Trig 12 //Pin Tring connects to D12
#define Echo 13 //Pin Echo connects to D13
float distance;//Distance variable
float cm;

int ENA = 5; 
int IN1 = 3; 
int IN2 = 4;

int ENB = 6; 
int IN3 = 2;
int IN4 = 7;
#define carSpeed 200

void setup()
{
    //Set the pin mode
    pinMode(ENA, OUTPUT);
    pinMode(IN1, OUTPUT);
    pinMode(IN2, OUTPUT);

    pinMode(ENB, OUTPUT);
    pinMode(IN3, OUTPUT);
    pinMode(IN4, OUTPUT);

    pinMode(Trig, OUTPUT);
    pinMode(Echo, INPUT);
    Serial.begin(9600);
}

void loop()
{
    cm = GetDistance();
    if(cm > 10 && cm <25){
        forward();
    }
    else if(cm >25 || cm <5){
        stop();
    }
    else  if(cm <= 10){
        back();
    }
}

/*
Function: obtain ultrasonic sensor ranging data
Parameters: Trig, Echo
Trig -------> pin D12
Echo -------> pin D13
*/
float GetDistance()
{
  // Send a low short pulse to Trig to trigger the ranging
  digitalWrite(Trig, LOW); //Send a low level to Trig
  delayMicroseconds(2);
  digitalWrite(Trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trig, LOW);
  distance = pulseIn(Echo, HIGH) / 58.00;
  Serial.print("Distance = ");
  Serial.println(distance);//The serial output distance is converted into cm
  return distance;
}
void forward(){//forward function
  analogWrite(ENA, carSpeed);//Set the speed of ENA
  analogWrite(ENB, carSpeed);//Set the speed of ENB
  //The left forward
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  //The right forward
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  Serial.println("Forward");
}

void back() {//back function
  analogWrite(ENA, carSpeed);//Set the speed of ENA
  analogWrite(ENB, carSpeed);//Set the speed of ENB

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  Serial.println("Back");
}

void stop() {//stop function
  digitalWrite(ENA, LOW);//Set the speed of ENA to low 
  digitalWrite(ENB, LOW);//Set the speed of ENB to low
  Serial.println("Stop!");
}
